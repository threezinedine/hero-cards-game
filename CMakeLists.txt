cmake_minimum_required(VERSION 3.10)

project(HeroCards)

add_subdirectory(vendors)

# load all *.cpp file except inside the src/components folder
file(
    GLOB_RECURSE
    SOURCES
    src/*.cpp
)

foreach(SOURCE ${SOURCES})
    if(${SOURCE} MATCHES "src/components")
        list(REMOVE_ITEM SOURCES ${SOURCE})
    endif()
endforeach()

foreach(SOURCE ${SOURCES})
    message(${SOURCE})
endforeach()



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
    raylib
    nlohmann_json
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    src
)