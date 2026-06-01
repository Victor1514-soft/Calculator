cmake_minimum_required(VERSION 3.10)

#ProjectName
project(Calculator)

# Le dice a CMake que busque Qt6 y sus componentes de interfaz
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Qt Meta Object compiler
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# properties
add_executable(Calculator 
    src/main.cpp 
    src/Calculator.h
    src/Calculator.cpp
)

# to link libraries
target_link_libraries(Calculator PRIVATE Qt6::Widgets)

configure_file(src/Calculator.qss ${CMAKE_BINARY_DIR}/Calculator.qss COPYONLY)