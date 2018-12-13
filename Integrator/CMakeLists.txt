# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Define project name
project(Integrator)

# Declare the executable target built from your sources
include_directories(./methods ./system ./time)

add_library(MyTime	./time/myTime.cpp)
add_library(Model	./system/model.cpp)
add_library(RK4		./methods/RK4.cpp)
target_link_libraries (RK4 Model)


add_library(${PROJECT_NAME} Integrator.cpp)
target_link_libraries (${PROJECT_NAME} MyTime)
target_link_libraries (${PROJECT_NAME} RK4)

