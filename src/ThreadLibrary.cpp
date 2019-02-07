#include "ThreadLibrary.h"

#include <iostream>
#include <string>

using namespace std;

ThreadLibrarySharedPointer ThreadLibrary::instance;

void ThreadLibrary::process()
{
	constexpr char QUIT[] = "quit";
	string input;

	while (cin >> input && input != QUIT)
	{
	}
}

ThreadLibrarySharedPointer ThreadLibrary::get_instance() noexcept
{
	if (instance == nullptr)
		instance = std::make_shared<ThreadLibrary>(ThreadLibrary());
	return instance;
}
