cmake_minimum_required(VERSION 3.10)

project(lldc LANGUAGES C VERSION 0.1.0)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Compiler Config
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)  

# Build Options
option(BUILD_SHARED_LIBS "Build shared libraries (rather than static ones)" ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/cwire)

find_package(UV REQUIRED)

add_library(lldc
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/yyjson/yyjson.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/spooky.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hashmap.c
)

set_target_properties(cwire PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
)

find_package(UV REQUIRED)

target_include_directories(lldc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${UV_INCLUDE_DIR}
)

target_link_libraries(lldc PUBLIC
    # Event Loop
    ${UV_LIBRARIES} 
    cwire
)

# DEMO

add_executable(demo
    src/demo.c
)

target_link_libraries(demo lldc)
