#include "CommandHandler.h"

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

#include "ThreadScheduler.h"
#include "Thread.h"
#include "Process.h"

using namespace std;

CommandHandler* CommandHandler::instance;

CommandHandler::CommandHandler()
{
}

CommandHandler* CommandHandler::get_instance()
{
	if (instance == nullptr)
		instance = new CommandHandler();
	return instance;
}

void CommandHandler::run()
{
    ThreadScheduler* thread_scheduler = ThreadScheduler::get_instance();

    constexpr char ADD_PROCESS[] = "add_process";
    constexpr char ADD_CORE[] = "add_core";
    constexpr char SHOW_CORES_STAT[] = "show_cores_stat";
    constexpr char RUN_CORES[] = "run_cores";
    constexpr char FINISH_TASKS[] = "finish_tasks";

	string input;
    
	while (getline(cin, input))
	{
        string command_name = split_string(input)[0];

		if (command_name == ADD_PROCESS)
			thread_scheduler->add_process(create_process(input));

		else if (input == ADD_CORE)
			thread_scheduler->add_core();

		else if (input == SHOW_CORES_STAT)
			thread_scheduler->show_cores_stat();

		else if (input == RUN_CORES)
			thread_scheduler->run_cores();
        
        else if (input == FINISH_TASKS)
			thread_scheduler->finish_tasks();
	}
}

CommandHandler::StringList CommandHandler::split_string(std::string input)
{
    stringstream input_string_stream(input);
    return vector<std::string>(istream_iterator<string>(input_string_stream),
            istream_iterator<string>());
}

Process* CommandHandler::create_process(std::string input_line)
{
    Process* new_process = new Process();

    CommandHandler::StringList string_list = split_string(input_line);

    for (unsigned int i = 2; i < string_list.size(); i++)
        new_process->add_thread(new Thread(stoi(string_list[i]), new_process));
    
    return new_process;
}
