# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

# Define project name
set(NAME pendulum)
project(${NAME})

include_directories(./GUI ./Integrator)

add_executable(main main.cpp)

add_subdirectory(GUI)
add_subdirectory(Integrator)

target_link_libraries(main GUI)
target_link_libraries(main Integrator)
