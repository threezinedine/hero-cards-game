FILE(
    GLOB
    VENDORS 
    *
)

set(CMAKE_BUILD_TYPE Release)

foreach(VENDOR ${VENDORS})
    if(IS_DIRECTORY ${VENDOR})
        if (VENDOR STREQUAL "sfml")
            set(SFML_USE_STATIC_STD_LIBS TRUE)
            set(BUILD_SHARED_LIBS FALSE)
        endif()

        if (VENDOR STREQUAL "raylib")
            set(BUILD_SHARED_LIBS FALSE)
        endif()

        message(STATUS "Adding vendor: ${VENDOR}")
        add_subdirectory(${VENDOR})
    endif()
endforeach()
