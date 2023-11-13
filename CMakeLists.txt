cmake_minimum_required(VERSION 3.0.0)
project(Chip-8 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR},${CMAKE_CURRENT_SOURCE_DIR}/src, ${CMAKE_CURRENT_SOURCE_DIR}/headers) 

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include(CTest)
enable_testing()

add_executable(Chip-8 src/main.cpp headers/includes.h src/Chip8.cpp headers/Chip8.h)

target_link_libraries(Chip-8 ${SDL2_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
