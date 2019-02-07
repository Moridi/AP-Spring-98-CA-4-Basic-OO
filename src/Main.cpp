#include "ThreadLibrary.h"

int main()
{
    ThreadLibrarySharedPointer thread_library =
            ThreadLibrary::get_instance();
    
    thread_library->process();

    return 0;
}