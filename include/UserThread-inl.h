#ifndef USER_THREAD_INL_H_
#define USER_THREAD_INL_H_

#ifndef USER_THREAD_H_
#error "UserThread-inl.h" should be included only in "UserThread.h" file.
#endif

#include "UserThread.h"

UserThread::UserThread(int _number_of_time_slots)
: number_of_time_slots(_number_of_time_slots)
{
}

#endif