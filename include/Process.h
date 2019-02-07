#ifndef PROCESS_H_
#define PROCESS_H_

#include <memory>
#include <vector>

#include "UserThread.h"

class Process
{
public:
    typedef std::shared_ptr<UserThread> UserThreadSharedPointer;

    inline Process(uint _process_id);

    void add_thread(UserThread new_thread);
    void remove_thread(int index);

    void initialize_threads(int number_of_threads);
    inline uint get_number_of_threads();
    inline UserThreadSharedPointer get_thread(uint index);
    inline int get_number_of_time_slots(int index);
    inline uint get_process_id();

    void print_process();

private:
    std::vector<UserThreadSharedPointer> threads;
    uint process_id;
};

#include "Process-inl.h"
#endif