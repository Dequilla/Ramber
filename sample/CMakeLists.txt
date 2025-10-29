message(STATUS "Building sample!")

set(
    SAMPLE_SOURCES

    src/main.cpp
)

add_executable(
    Sample

    ${SAMPLE_SOURCES}
)

target_link_libraries(
    Sample

    PUBLIC Ramber
)
