#include "KernelThread.h"

#include <iostream>

using namespace std;

void KernelThread::print_thread_state()
{
    cout << "Kernel thread with thread ID = " << thread_id << endl;

    for (uint i = 0; i < waiting_queue.size(); ++i)
    {   
        cout << i << " :" << endl;
        waiting_queue[i]->print_thread_state();
    }
}

void KernelThread::add_to_queue(UserThreadSharedPointer new_thread) noexcept
{
    waiting_queue.push_back(new_thread);
}

void KernelThread::run_user_thread()
{
    if (waiting_queue.size() == 0)
        return;

    UserThreadSharedPointer first_thread = waiting_queue[0];
    first_thread->decrease_number_time_slots();

    if (first_thread->get_number_of_time_slots() != 0)
        waiting_queue.push_back(first_thread);

    waiting_queue.erase(waiting_queue.begin());
}