#ifndef THREAD_LIBRARY_INL_H_
#define THREAD_LIBRARY_INL_H_

#ifndef THREAD_LIBRARY_H_
#error "ThreadLibrary-inl.h" should be included only in "ThreadLibrary.h" file.
#endif

#include "ThreadLibrary.h"

#define FIRST_ID 1

typedef std::shared_ptr<ThreadLibrary> ThreadLibrarySharedPointer;

ThreadLibrary::ThreadLibrary() noexcept
: process_id(FIRST_ID)
, thread_id(FIRST_ID)
{
}

uint ThreadLibrary::get_process_id()
{
    return process_id;
}

uint ThreadLibrary::get_thread_id()
{
    return thread_id;
}

void ThreadLibrary::increment_process_id()
{
    process_id++;
}

void ThreadLibrary::increment_thread_id()
{
    thread_id++;
}

#endif