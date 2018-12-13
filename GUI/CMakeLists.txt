# cmake needs this line
cmake_minimum_required(VERSION 3.8)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(GUI)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5OpenGL)
find_package(Qt5Widgets)
find_package(Qt5PrintSupport)

# OpenGL & GLEW library
find_package(OpenGL)

set(SOURCE_FILES_GUI GUI.cpp mainwindow.ui mainwindow.cpp qcustomplot.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES_GUI})

qt5_use_modules(${PROJECT_NAME} Widgets OpenGL PrintSupport)
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES} ${OPENGL_LIBRARIES})

