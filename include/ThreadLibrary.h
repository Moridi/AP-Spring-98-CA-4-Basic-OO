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
    void run_kernel_threads();
    inline uint get_process_id();
    inline uint get_thread_id();
    inline void increment_process_id();
    inline void increment_thread_id();

private:
	inline ThreadLibrary() noexcept;
	static ThreadLibrarySharedPointer instance;
    uint process_id;
    uint thread_id;
    std::vector<ProcessSharedPointer> processes;
    std::vector<KernelThreadSharedPointer> kernel_threads;
};

#include "ThreadLibrary-inl.h"
#endif