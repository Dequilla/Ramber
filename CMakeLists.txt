cmake_minimum_required( VERSION 3.25 )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
project( Ramber
    LANGUAGES C CXX
    VERSION 0.1.0
    DESCRIPTION "Homebrew software rasterizer."
)

# Set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set (CMAKE_CXX_STANDARD 23)

add_subdirectory( ramber )
add_subdirectory( sample )
