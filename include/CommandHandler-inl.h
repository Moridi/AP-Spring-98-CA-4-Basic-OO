#ifndef COMMAND_HANDLER_INL_H_
#define COMMAND_HANDLER_INL_H_

#ifndef COMMAND_HANDLER_H_
#error "CommandHandler-inl.h" should be included only in "CommandHandler.h" file.
#endif

#include "CommandHandler.h"

typedef std::shared_ptr<CommandHandler> CommandHandlerSharedPointer;

CommandHandler::CommandHandler() noexcept
{
}

CommandHandlerSharedPointer CommandHandler::get_instance() noexcept
{
	if (instance == nullptr)
		instance = std::make_shared<CommandHandler>(CommandHandler());
	return instance;
}

#endif