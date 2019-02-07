#ifndef THREAD_LIBRARY_H_
#define THREAD_LIBRARY_H_

#include <memory>
#include <vector>

#include "Process.h"

class ThreadLibrary
{    
public:
    typedef std::shared_ptr<ThreadLibrary> ThreadLibrarySharedPointer;
    typedef std::shared_ptr<Process> ProcessSharedPointer;

    static ThreadLibrarySharedPointer get_instance() noexcept;
    void run();
    void add_process();
    void print_processes();

private:
	inline ThreadLibrary() noexcept;
	static ThreadLibrarySharedPointer instance;
    std::vector<ProcessSharedPointer> processes;
};

#include "ThreadLibrary-inl.h"
#endif