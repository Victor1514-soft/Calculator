cmake_minimum_required(VERSION 3.10)

# Nombre de tu proyecto
project(Calculator)

# Le dice a CMake que busque Qt6 y sus componentes de interfaz
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Permite que Qt procese automáticamente archivos especiales de C++
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Aquí listamos tus archivos. ¡Asegúrate de poner los nombres de tus archivos del engine!
add_executable(Calculator 
    src/main.cpp 
    src/CalculatorEngine.cpp 
    src/CalculatorEngine.h
    src/Calculator.h
    src/Calculator.cpp
)

# Une tu código con las librerías de Qt
target_link_libraries(Calculator PRIVATE Qt6::Widgets)