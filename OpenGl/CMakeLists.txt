cmake_minimum_required(VERSION 3.10)  # Requerido para versiones más nuevas de CMake
project(OPENGL)  # Nombre de tu proyecto

# Establecer la versión de C++
set(CMAKE_CXX_STANDARD 11)  # Cambia esto si necesitas una versión diferente

# Incluir los directorios de encabezados
include_directories(include)

# Agregar el ejecutable
add_executable(main src/main.cpp src/glad.c)

# Vincular bibliotecas
target_link_libraries(main)

# Establecer la ruta de búsqueda de bibliotecas
link_directories(${CMAKE_SOURCE_DIR}/lib)