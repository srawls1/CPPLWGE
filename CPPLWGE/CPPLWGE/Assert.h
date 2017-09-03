#pragma once
#include "Config.h"

#ifdef DEBUG
// TODO change this to throw an exception when I get strings working
#define Assert(condition) if (!(condition))\
{\
	std::cout << "Assertion failed at " << __FILE__ << ':' << __LINE__\
	 << ": " << #condition << std::endl;\
}
#else
#define Assert(condition)
#endif
