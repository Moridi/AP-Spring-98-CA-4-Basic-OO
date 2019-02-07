#ifndef COMMAND_HANDLER_H_
#define COMMAND_HANDLER_H_

#include <memory>

class CommandHandler
{
public:
    typedef std::shared_ptr<CommandHandler> CommandHandlerSharedPointer;
    inline static CommandHandlerSharedPointer get_instance() noexcept;

private:
	inline CommandHandler() noexcept;
	static CommandHandlerSharedPointer instance;
};

#include "CommandHandler-inl.h"
#endif