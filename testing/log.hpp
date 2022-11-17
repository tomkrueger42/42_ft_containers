#pragma once

#include <iostream>

#define LOG(msg) std::cout << msg
#define LOGN(msg) std::cout << msg << std::endl;
#define LOGI(...) std::cout << #__VA_ARGS__ << ": " << __VA_ARGS__ << std::endl;
