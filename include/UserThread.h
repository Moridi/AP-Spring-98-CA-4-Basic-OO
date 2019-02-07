#ifndef USER_THREAD_H_
#define USER_THREAD_H_

// @TODO: remove it
#include <memory>

class UserThread
{
public:
    inline UserThread(int _number_of_time_slots, uint _thread_id);

    void print_thread_state();
    inline void decrease_number_time_slots();
    inline int get_number_of_time_slots();
    inline uint get_thread_id();
    
private:
    int number_of_time_slots;
    uint thread_id;
};

#include "UserThread-inl.h"
#endif