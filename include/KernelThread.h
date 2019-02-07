#ifndef KERNEL_THREAD_H_
#define KERNEL_THREAD_H_

#include <vector>
#include <memory>

#include "UserThread.h"

class KernelThread
{
public:
    typedef std::shared_ptr<UserThread> UserThreadSharedPointer;

    void add_to_queue(UserThreadSharedPointer new_thread) noexcept;
    void remove_from_queue(int index) noexcept;

    void print_thread_state();
    inline uint get_queue_size();
    
private:
    std::vector<UserThreadSharedPointer> waiting_queue;
};

#include "KernelThread-inl.h"
#endif