# Proyecto OpenGL C++

**Nombre:** Jonathan Leonardo Bautista Rondón  
**Carnet:** 16-10109  
**API:** OpenGL
**Desarrollado en:** Lenguaje C++ y SO Windows. 
**Requisito:** Es necesario tener `g++` para la compilación.  

Este proyecto muestra un triángulo en pantalla usando OpenGL y GLFW, con shaders aplicados para personalizar los colores y el fondo.

## Dependencias

El proyecto utiliza las siguientes dependencias, todas ubicadas en la carpeta `include` y `lib`:

- **GLFW:** Biblioteca para crear ventanas y gestionar contexto de OpenGL.
- **GLAD:** Biblioteca para la gestión de funciones de OpenGL.

## Instrucciones de Compilación

Para compilar el proyecto, asegúrate de tener todas las dependencias ubicadas en las carpetas correctas (`include` y `lib`). Luego, ejecuta el siguiente comando desde la raíz del proyecto:

```bash
g++ -I./include -L./lib .\src\main.cpp .\src\glad.c -o .\src\main -lglfw3dll
```
## Ejecucion 

Para ejecutar el proyecto:
Es necesario que el archivo glfw3.dll este al mismo nivel que el main.exe, de haber seguido las instrucciones anteriores el archivo main.exe se creara dentro de src donde ya se encuentra el archivo .dll
```bash
./src/main.exe
```