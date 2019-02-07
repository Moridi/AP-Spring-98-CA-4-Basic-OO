#ifndef PROCESS_INL_H_
#define PROCESS_INL_H_

#ifndef PROCESS_H_
#error "Process-inl.h" should be included only in "Process.h" file.
#endif

#include "Process.h"

Process::Process()
{
}

uint Process::get_number_of_threads()
{
    return threads.size();
}

Process::UserThreadSharedPointer Process::get_thread(uint index)
{
    // @TODO: throw in invalid size case
    return threads[index];
}

#endif