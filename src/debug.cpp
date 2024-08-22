#include <iostream>;

static class Debug
{
public:
	static void log(std::string message)
	{
		std::cout << message << std::endl;
	}
};