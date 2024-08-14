#pragma once
#include <common.hpp>
#include <cstdio>

#ifdef _DEBUG
#define PRINT(...)       \
    printf(__VA_ARGS__); \
    std::cout << std::endl
#define DEBUG_POINT() printf("Debug point: %s:%d\n", __FILE__, __LINE__)
#else
#define PRINT(...)
#endif