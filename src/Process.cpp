#include "Process.h"

#include <iostream>

#include "Thread.h"
#include "ThreadScheduler.h"

using namespace std;

constexpr unsigned int FIRST_ID = 1;

Process::Process()
: process_id(FIRST_ID)
, thread_id_counter(FIRST_ID)
{
}

void Process::add_thread(Thread* new_thread)
{
    new_thread->set_thread_id(thread_id_counter++);
    threads.push_back(new_thread);
}

uint Process::get_number_of_threads()
{
    return threads.size();
}

vector<Thread*> Process::get_threads()
{
    return threads;
}

unsigned int Process::get_process_id()
{
    return process_id;
}

void Process::set_process_id(unsigned int _process_id)
{
    process_id = _process_id;
}

void Process::print_process()
{
    for (uint i = 0; i < threads.size(); ++i)
        threads[i]->print_thread_stat();
    cout << endl;
}

