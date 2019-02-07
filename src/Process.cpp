#include "Process.h"

#include <iostream>

#include "UserThread.h"
#include "ThreadLibrary.h"

using namespace std;

void Process::initialize_threads(int number_of_threads)
{
    ThreadLibrarySharedPointer thread_library = ThreadLibrary::get_instance();

    for (int i = 0; i < number_of_threads; ++i)
    {
        int number_of_time_slots = get_number_of_time_slots(i);

        UserThreadSharedPointer new_thread = make_shared<UserThread>(
                UserThread(number_of_time_slots, thread_library->get_thread_id()));   
        
        thread_library->increment_thread_id();
        
        threads.push_back(new_thread);
    }
}

void Process::print_process()
{
    for (uint i = 0; i < threads.size(); ++i)
        threads[i]->print_thread_state();
    cout << endl;
}