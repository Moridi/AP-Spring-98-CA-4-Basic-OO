#ifndef PROCESS_H_
#define PROCESS_H_

#include <memory>
#include <vector>

#include "UserThread.h"

class Process
{
public:
    typedef std::shared_ptr<UserThread> UserThreadSharedPointer;

    inline Process();

    void add_thread(UserThread new_thread);
    void remove_thread(int index);

    void initialize_threads(int number_of_threads);

    void print_process();

private:
    std::vector<UserThreadSharedPointer> threads;
};

#include "Process-inl.h"
#endif