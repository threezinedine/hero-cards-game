cmake_minimum_required(VERSION 3.10)

project(HeroCards)

add_subdirectory(vendors)

file(
    GLOB
    SOURCES
    src/*.cpp
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG)
endif()

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    SFML::System
    SFML::Graphics
    SFML::Audio
)