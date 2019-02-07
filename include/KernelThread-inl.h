#ifndef KERNEL_THREAD_INL_H_
#define KERNEL_THREAD_INL_H_

#ifndef KERNEL_THREAD_H_
#error "KernelThread-inl.h" should be included only in "KernelThread.h" file.
#endif

KernelThread::KernelThread(uint _thread_id)
: thread_id(_thread_id)
{
}

uint KernelThread::get_queue_size()
{
    return waiting_queue.size();
}

uint KernelThread::get_thread_id()
{
    return thread_id;
}

#endif