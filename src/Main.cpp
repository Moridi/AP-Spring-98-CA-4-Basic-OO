#include "ThreadLibrary.h"

int main()
{
    ThreadLibrarySharedPointer thread_library =
            ThreadLibrary::get_instance();
    
    thread_library->run();
    return 0;
}