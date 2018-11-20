cmake_minimum_required(VERSION 3.8)
project(PendulumSimulator)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

#find_package(Qt5Core)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
#find_package(Qt5Gui)

#set(SOURCE_LIB1 mainwindow.cpp)			
#add_library(mainwindow STATIC ${SOURCE_LIB1})

#set(SOURCE_LIB2 qcustomplot.cpp)			
#add_library(qcustomplot STATIC ${SOURCE_LIB2})

set(SOURCE_FILES main.cpp mainwindow.ui mainwindow.cpp qcustomplot.cpp)
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})

# specify which libraries to connect
#target_link_libraries(${PROJECT_NAME} Qt5::Core)
#target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport)