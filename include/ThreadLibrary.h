#ifndef THREAD_LIBRARY_H_
#define THREAD_LIBRARY_H_

#include <memory>

class ThreadLibrary
{    
public:
    typedef std::shared_ptr<ThreadLibrary> ThreadLibrarySharedPointer;
    static ThreadLibrarySharedPointer get_instance() noexcept;
    void process();

private:
	inline ThreadLibrary() noexcept;
	static ThreadLibrarySharedPointer instance;
};

#include "ThreadLibrary-inl.h"
#endif