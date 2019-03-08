#include "Core.h"

#include <iostream>

#include <Thread.h>

using namespace std;


Core::Core(uint _core_id)
: core_id(_core_id)
{
}

void Core::add_to_queue(Thread* new_thread)
{
    waiting_queue.push_back(new_thread);
}

void Core::print_core_stat()
{
    cout << "Core Number : " << core_id << endl;

    for (Thread* thread: waiting_queue)
        thread->print_thread_stat();
}

uint Core::get_queue_size()
{
    return waiting_queue.size();
}

uint Core::get_core_id()
{
    return core_id;
}

void Core::run_thread()
{
    if (waiting_queue.size() == 0)
        return;

    Thread* first_thread = waiting_queue[0];
    cout << "Core number : " << core_id << endl;
    first_thread->run_thread();
    
    if (first_thread->get_number_of_time_slots() != 0)
        waiting_queue.push_back(first_thread);

    waiting_queue.erase(waiting_queue.begin());
}