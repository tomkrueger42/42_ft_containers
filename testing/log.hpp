#pragma once

#include <iostream>

#define LOG(msg) std::cout << msg
#define LOGN(msg) std::cout << msg << std::endl
#define LOGI(...) std::cout << #__VA_ARGS__ << ": " << __VA_ARGS__ << std::endl

#if DEBUG > 0
	#define LOG1(msg) std::cout << msg
	#define LOGN1(msg) std::cout << msg  << std::endl
	#define LOGI1(...) std::cout << #__VA_ARGS__ << ": " << __VA_ARGS__ << std::endl
#else
	#define LOG1(msg) 
	#define LOGN1(msg) 
	#define LOGI1(...) 
#endif

#if DEBUG > 1
	#define LOG2(msg) std::cout << msg
	#define LOGN2(msg) std::cout << msg << std::endl
	#define LOGI2(...) std::cout << #__VA_ARGS__ << ": " << __VA_ARGS__ << std::endl
#else
	#define LOG2(msg) 
	#define LOGN2(msg) 
	#define LOGI2(...) 
#endif
