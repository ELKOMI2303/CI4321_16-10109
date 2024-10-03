# Proyecto OpenGL C++

**Nombre:** Jonathan Leonardo Bautista Rondón  
**Carnet:** 16-10109  
**API:** OpenGL
**Desarrollado en:** Lenaguaje: C++ y SO: Windows. 
**Requisito:** Es necesario tener `g++` para la compilación.  

Este proyecto muestra un triángulo 2D en pantalla usando OpenGL y GLFW, con shaders aplicados para creacion y personalizar de los vertices con colores. Tambien posee color de fondo personalizado.

## Dependencias

El proyecto utiliza las siguientes dependencias, todas ubicadas en la carpeta `include` y `lib`:

- **GLFW:** Biblioteca para crear ventanas y gestionar contexto de OpenGL. [GLFW](https://www.glfw.org) Version 3.4 Para Windows de 64 Bits
- **GLAD:** Biblioteca para la gestión de funciones de OpenGL. [GLAD](https://glad.dav1d.de) Gl Version 4.0, Profile Core

## Instrucciones de Compilación

Para compilar el proyecto, asegúrate de tener [C++](https://code.visualstudio.com/docs/cpp/config-mingw), y todas las dependencias ubicadas en las carpetas correctas (`include` y `lib`). Luego, ejecuta el siguiente comando desde la raíz del proyecto:

```bash
g++ -I./include -L./lib .\src\main.cpp .\src\glad.c -o .\src\main -lglfw3dll
```
## Ejecucion 

Para ejecutar el proyecto:
Es necesario que el archivo glfw3.dll este al mismo nivel que el main.exe, de haber seguido las instrucciones anteriores el archivo main.exe se creara dentro de src donde ya se encuentra el archivo .dll
```bash
./src/main.exe
```