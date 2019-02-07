#ifndef THREAD_LIBRARY_H_
#define THREAD_LIBRARY_H_

#include <memory>
#include <vector>

#include "Process.h"
#include "KernelThread.h"

class ThreadLibrary
{    
public:
    typedef std::shared_ptr<ThreadLibrary> ThreadLibrarySharedPointer;
    typedef std::shared_ptr<Process> ProcessSharedPointer;
    typedef std::shared_ptr<KernelThread> KernelThreadSharedPointer;

    static ThreadLibrarySharedPointer get_instance() noexcept;
    void run();
    void add_process();
    void print_processes();
    void add_kernel_thread();
    void assign_kthread_to_uthread(ProcessSharedPointer new_process);
    uint get_minimum_kthread_index();
    void show_kernel_stat();

private:
	inline ThreadLibrary() noexcept;
	static ThreadLibrarySharedPointer instance;
    std::vector<ProcessSharedPointer> processes;
    std::vector<KernelThreadSharedPointer> kernel_threads;
};

#include "ThreadLibrary-inl.h"
#endif