cmake_minimum_required(VERSION 3.14)
project(Sample-Raylib-Project)

if (UNIX)
    set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Build GLFW Wayland support")
    set(GLFW_BUILD_X11 ON CACHE BOOL "Build GLFW X11 support")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Raylib
add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/raylib ${CMAKE_BINARY_DIR}/_deps/raylib-build)

# Raygui
add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/raygui/projects/CMake ${CMAKE_BINARY_DIR}/_deps/raygui-build)

file(GLOB SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include/)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -static)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib raygui)

# Web Configurations
if ("${PLATFORM}" STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "index" SUFFIX ".html")
    target_link_options(${PROJECT_NAME} PUBLIC 
        "-sASSERTIONS=1"
        "-sFORCE_FILESYSTEM"
        "-sALLOW_MEMORY_GROWTH"
        "-sUSE_GLFW=3"
        "-sEXPORTED_RUNTIME_METHODS=['HEAPF32']"
        "--preload-file=${CMAKE_SOURCE_DIR}/resources@resources"
        "--preload-file=${CMAKE_SOURCE_DIR}/settings.txt@settings.txt"
    )
    if ("${SHELL}" STREQUAL "Minimal")
        target_link_options(${PROJECT_NAME} PUBLIC "--shell-file" "${CMAKE_SOURCE_DIR}/src/shell_minimal.html")
    endif()
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
endif()
