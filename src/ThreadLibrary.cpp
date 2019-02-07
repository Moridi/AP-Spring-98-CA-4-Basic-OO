#include "ThreadLibrary.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

ThreadLibrarySharedPointer ThreadLibrary::instance;

void ThreadLibrary::run()
{
	constexpr char QUIT[] = "quit";
	constexpr char ADD_PROCESS[] = "add_process";
	constexpr char SHOW_STAT[] = "show_stat";

	string input;

	while (cin >> input && input != QUIT)
	{
		if (input == ADD_PROCESS)
			add_process();
		else if (input == SHOW_STAT)
			print_processes();
	}
}

void ThreadLibrary::add_process()
{
	int number_of_threads;

	cout << "Please enter number of threads per process:" << endl;
	cin >> number_of_threads;

	ProcessSharedPointer new_process = make_shared<Process>(Process());
	new_process->initialize_threads(number_of_threads);

	processes.push_back(new_process);
}

void ThreadLibrary::print_processes()
{
	for (uint i = 0; i < processes.size(); ++i)
	{
		cout << "###### Process - " << i << " #####" << endl;
		processes[i]->print_process();
	}
}

ThreadLibrarySharedPointer ThreadLibrary::get_instance() noexcept
{
	if (instance == nullptr)
		instance = make_shared<ThreadLibrary>(ThreadLibrary());
	return instance;
}
