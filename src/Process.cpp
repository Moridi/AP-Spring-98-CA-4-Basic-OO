#include "Process.h"

#include <iostream>

#include "UserThread.h"

using namespace std;

void Process::initialize_threads(int number_of_threads)
{
    for (int i = 0; i < number_of_threads; ++i)
    {
        int number_of_time_slots;
    	cout << "\t" << i << "- Please enter number of time slots:" << endl;
    	cin >> number_of_time_slots;

        UserThreadSharedPointer new_thread =
                make_shared<UserThread>(UserThread(number_of_time_slots));   
        
        threads.push_back(new_thread);
    }
}

void Process::print_process()
{
    for (uint i = 0; i < threads.size(); ++i)
    {
        cout << "\t$$$$$$$$$ Thread " << i << " $$$$$$$$$" << endl;
        threads[i]->print_thread_state();
    }
}