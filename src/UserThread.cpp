#include "UserThread.h"

#include <iostream>

using namespace std;

void UserThread::print_thread_state()
{
    cout << "\t-------- Thread ID : " << thread_id << " --------" << endl;
    cout << "\t\t__________ Number of time slots: " <<
            number_of_time_slots << "__________" << endl;
}