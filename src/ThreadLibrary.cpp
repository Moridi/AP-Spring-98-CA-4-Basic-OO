#include "ThreadLibrary.h"

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

ThreadLibrarySharedPointer ThreadLibrary::instance;

void ThreadLibrary::run()
{
	constexpr char QUIT[] = "quit";
	constexpr char ADD_PROCESS[] = "add_process";
	constexpr char SHOW_STAT[] = "show_stat";
	constexpr char ADD_KERNEL_THREAD[] = "add_kthread";
	constexpr char SHOW_KERNEL_STAT[] = "show_kernel_stat";
	constexpr char RUN_THREADS[] = "run_threads";

	string input;

	while (cin >> input && input != QUIT)
	{
		if (input == ADD_PROCESS)
			add_process();
		else if (input == SHOW_STAT)
			print_processes();
		else if (input == ADD_KERNEL_THREAD)
			add_kernel_thread();
		else if (input == SHOW_KERNEL_STAT)
			show_kernel_stat();
		else if (input == RUN_THREADS)
			run_kernel_threads();
	}
}

void ThreadLibrary::run_kernel_threads()
{
	for (uint i = 0; i < kernel_threads.size(); ++i)
		if (kernel_threads[i]->get_queue_size() != 0)
			kernel_threads[i]->run_user_thread();
}

void ThreadLibrary::show_kernel_stat()
{
	cout << "####### KERNEL STAT ######" << endl;
	for (uint i = 0; i < kernel_threads.size(); ++i)
		kernel_threads[i]->print_thread_state();
}

void ThreadLibrary::add_kernel_thread()
{
	// @TODO: Get kernel thread information
	kernel_threads.push_back(make_shared<KernelThread>(KernelThread(thread_id++)));
	cout << "Kernel thread added!" << endl;
}

uint ThreadLibrary::get_minimum_kthread_index()
{
	uint min_index = kernel_threads.size();
	uint min_value = UINT32_MAX;

	for (uint i = 0; i < kernel_threads.size(); ++i)
	{
		if (min_value > kernel_threads[i]->get_queue_size())
		{
			min_value = kernel_threads[i]->get_queue_size();
			min_index = i;
		}
	}

	// @TODO: throw exception in invalid index case

	return min_index;
}

void ThreadLibrary::assign_kthread_to_uthread(ProcessSharedPointer new_process)
{
	for (uint i = 0; i < new_process->get_number_of_threads(); ++i)
	{
		uint min_index = get_minimum_kthread_index();
		if (min_index != kernel_threads.size())
			kernel_threads[min_index]->add_to_queue(new_process->get_thread(i));
	}
}

void ThreadLibrary::add_process()
{
	int number_of_threads;

	cout << "Please enter number of threads per process:" << endl;
	cin >> number_of_threads;

	ProcessSharedPointer new_process = make_shared<Process>(Process(process_id++));
	new_process->initialize_threads(number_of_threads);

	assign_kthread_to_uthread(new_process);
	processes.push_back(new_process);

	cout << "Process added!" << endl;
}

void ThreadLibrary::print_processes()
{
	for (uint i = 0; i < processes.size(); ++i)
	{
		cout << "###### Process ID :  " << processes[i]->get_process_id() << " #####" << endl;
		processes[i]->print_process();
	}
	cout << endl;
}

ThreadLibrarySharedPointer ThreadLibrary::get_instance() noexcept
{
	if (instance == nullptr)
		instance = make_shared<ThreadLibrary>(ThreadLibrary());
	return instance;
}
