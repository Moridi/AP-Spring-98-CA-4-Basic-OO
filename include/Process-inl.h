#ifndef PROCESS_INL_H_
#define PROCESS_INL_H_

#ifndef PROCESS_H_
#error "Process-inl.h" should be included only in "Process.h" file.
#endif

#include "Process.h"

#include <iostream>

Process::Process(uint _process_id)
: process_id(_process_id)
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

int Process::get_number_of_time_slots(int index)
{
    int number_of_time_slots;
    std::cout << "\t" << index << "- Please enter number of time slots:" << std::endl;
    std::cin >> number_of_time_slots;
    return number_of_time_slots;
}

uint Process::get_process_id()
{
    return process_id;
}

#endif