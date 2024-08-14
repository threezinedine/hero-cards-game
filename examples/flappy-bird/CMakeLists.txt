project(FlappyBird)

file(
    GLOB
    FLAPPY_BIRD_SOURCES
    *.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${FLAPPY_BIRD_SOURCES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    NTTEngine
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    .
)

# move file project.config.json to build folder
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/project.config.json
    ${CMAKE_CURRENT_BINARY_DIR}/project.config.json
)