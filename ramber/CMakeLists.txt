message(STATUS "Building ramber!")

set(
    RAMBER_SOURCES

    src/ramber.cpp
)

set(
    RAMBER_INCLUDES

    "${PROJECT_SOURCE_DIR}/ramber/include/"
)

add_library(
    Ramber
    SHARED

    ${RAMBER_SOURCES}
)

target_include_directories(
    Ramber

    PUBLIC ${RAMBER_INCLUDES}
)
