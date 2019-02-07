#include "KernelThread.h"

void KernelThread::print_thread_state()
{
}

void KernelThread::add_to_queue(UserThreadSharedPointer new_thread) noexcept
{
    waiting_queue.push_back(new_thread);
}