cmake_minimum_required(VERSION 3.10)

project(NTTEngine)

add_subdirectory(vendors)

# load all *.cpp file except inside the src/components folder
file(
    GLOB_RECURSE
    SOURCES
    src/*.cpp
)

list(FILTER SOURCES EXCLUDE REGEX ".*_test\\\.cpp$")
list(FILTER SOURCES EXCLUDE REGEX ".*_fixture\\\.cpp$")

file(
    GLOB_RECURSE 
    TESTING_SOURCES
    src/*_test.cpp
)

file(
    GLOB_RECURSE 
    TESTING_FIXTURES
    src/*_fixture.cpp
)

# foreach(SOURCE ${SOURCES})
#     message(STATUS "SOURCE CODE: ${SOURCE}")
# endforeach()

# foreach(TESTING_SOURCE ${TESTING_SOURCES})
#     message(STATUS "TESTING SOURCE CODE: ${TESTING_SOURCE}")
# endforeach()


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG)
endif()

add_compile_definitions(_LIB)

add_library(
    ${PROJECT_NAME}
    STATIC
    ${SOURCES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    raylib
    nlohmann_json
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    src
    include
)

# testing setup
add_executable(
    ${PROJECT_NAME}_test
    ${TESTING_SOURCES}
    ${TESTING_FIXTURES}
    test.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_test
    PUBLIC
    ${PROJECT_NAME}
    gtest
    gmock
)

add_subdirectory(examples)