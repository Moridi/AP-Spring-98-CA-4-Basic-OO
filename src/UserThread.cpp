#include "UserThread.h"

#include <iostream>

using namespace std;

void UserThread::print_thread_state()
{
    cout << "Number of time slots: " << number_of_time_slots << endl;
}