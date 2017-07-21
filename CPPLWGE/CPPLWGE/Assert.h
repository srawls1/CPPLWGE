#pragma once

#define Assert(condition) if (!condition)\
{\
	std::exit(1);\
}

#define Assert(condition, message) if (!condition)\
{\
	std::cout << message << std::endl;\
}