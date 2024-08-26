#pragma once
#include <cores/commons/common.hpp>
#include <cstdio>
#include "FunctionLog.hpp"

#ifdef _DEBUG
#define PRINT(...)       \
    printf(__VA_ARGS__); \
    std::cout << std::endl
#define DEBUG_POINT() printf("----------------\nDebug point: %s:%d\n--------------\n", \
                             __FILE__, __LINE__)

// #ifdef _TEST
#define FUNCTION_LOG() FunctionLog log(__PRETTY_FUNCTION__, __FILE__, __LINE__)
#define FUNCTION_LOG_P(...)                                   \
    FunctionLog log(__PRETTY_FUNCTION__, __FILE__, __LINE__); \
    log.Print(__VA_ARGS__)
// #else
// #define FUNCTION_LOG()
// #endif
#else
#define PRINT(...)
#define DEBUG_POINT()
#define FUNCTION_LOG()
#define FUNCTION_LOG_P(...)
#endif