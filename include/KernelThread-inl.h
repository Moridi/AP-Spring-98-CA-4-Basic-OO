#ifndef KERNEL_THREAD_INL_H_
#define KERNEL_THREAD_INL_H_

#ifndef KERNEL_THREAD_H_
#error "KernelThread-inl.h" should be included only in "KernelThread.h" file.
#endif

uint KernelThread::get_queue_size()
{
    return waiting_queue.size();
}

#endif