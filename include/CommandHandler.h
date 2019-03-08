#ifndef COMMAND_HANDLER_H_
#define COMMAND_HANDLER_H_

#include <string>
#include <vector>

#include <Process.h>

class CommandHandler 
{
public:
    void run();

private:
    typedef std::vector<std::string> StringList;

    Process* create_process(std::string input_line);
    StringList split_string(std::string input);
};

#endif