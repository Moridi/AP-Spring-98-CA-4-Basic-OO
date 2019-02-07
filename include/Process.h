#ifndef PROCESS_H_
#define PROCESS_H_

#include <memory>
#include <vector>

#include "UserThread.h"

class Process
{
public:
    typedef std::shared_ptr<UserThread> UserThreadSharedPointer;

    void add_thread(UserThread new_thread);
    void remove_thread(int index);

private:
    std::vector<UserThreadSharedPointer> threads;
};

#include "Process-inl.h"
#endif