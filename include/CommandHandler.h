#ifndef COMMAND_HANDLER_H_
#define COMMAND_HANDLER_H_

#include <string>
#include <vector>

class Process;

class CommandHandler
{
public:
    static CommandHandler* get_instance();
    void run();

private:
    typedef std::vector<std::string> StringList;
    
    CommandHandler();
    Process* create_process(std::string input_line);
    StringList split_string(std::string input);

    static CommandHandler* instance;
};

#endif