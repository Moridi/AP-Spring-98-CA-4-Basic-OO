#ifndef USER_THREAD_H_
#define USER_THREAD_H_

class UserThread
{
public:
    inline UserThread(int _number_of_time_slots);

    void print_thread_state();
    
private:
    int number_of_time_slots;
};

#include "UserThread-inl.h"
#endif