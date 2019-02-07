#ifndef THREAD_LIBRARY_INL_H_
#define THREAD_LIBRARY_INL_H_

#ifndef THREAD_LIBRARY_H_
#error "ThreadLibrary-inl.h" should be included only in "ThreadLibrary.h" file.
#endif

#include "ThreadLibrary.h"

typedef std::shared_ptr<ThreadLibrary> ThreadLibrarySharedPointer;

ThreadLibrary::ThreadLibrary() noexcept
{
}

ThreadLibrarySharedPointer ThreadLibrary::get_instance() noexcept
{
	if (instance == nullptr)
		instance = std::make_shared<ThreadLibrary>(ThreadLibrary());
	return instance;
}

#endif