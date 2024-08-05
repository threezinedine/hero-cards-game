FILE(
    GLOB
    VENDORS 
    *
)

foreach(VENDOR ${VENDORS})
    if(IS_DIRECTORY ${VENDOR})
        message(STATUS "Adding vendor: ${VENDOR}")
        add_subdirectory(${VENDOR})
    endif()
endforeach()
