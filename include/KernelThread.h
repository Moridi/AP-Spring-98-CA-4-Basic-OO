#ifndef KERNEL_THREAD_H_
#define KERNEL_THREAD_H_

#include <vector>
#include <memory>

#include "UserThread.h"

class KernelThread
{
public:
    typedef std::shared_ptr<UserThread> UserThreadSharedPointer;

    inline KernelThread(uint _thread_id);

    void add_to_queue(UserThreadSharedPointer new_thread) noexcept;
    void remove_from_queue(int index) noexcept;

    void print_thread_state();
    inline uint get_queue_size();
    inline uint get_thread_id();

    void run_user_thread();
    
private:
    std::vector<UserThreadSharedPointer> waiting_queue;
    uint thread_id;
};

#include "KernelThread-inl.h"
#endif