#pragma once
#include <cores/commons/common.hpp>
#include <cstdio>

#ifdef _DEBUG
#define PRINT(...)       \
    printf(__VA_ARGS__); \
    std::cout << std::endl
#define DEBUG_POINT() printf("Debug point: %s:%d\n", __FILE__, __LINE__)
#define FUNCTION_LOG() FunctionLog log(__PRETTY_FUNCTION__, __FILE__, __LINE__)
#else
#define PRINT(...)
#define DEBUG_POINT()
#define FUNCTION_LOG()
#endif

#include "FunctionLog.hpp"