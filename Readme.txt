Proyecto de Programacion 3: Venelipsis

Creditos:
  - Dickson Labrador

Tecnologias Utilizadas:

  - Lenguaje de Programacion: C++
      - Estándar: C++17
  - Compilador: g++ (GNU Compiler Collection)
  - Herramienta de Automatizacion de Build: GNU Make (para gestionar la compilacion con el Makefile)
  - Librerias Graficas y Multimedia: SFML (Simple and Fast Multimedia Library)
      - Version: SFML 2.x.x (se requieren los modulos Graphics, Window, System y Audio)
  - Sanitizadores de Codigo (para desarrollo):
      - AddressSanitizer (ASan): Utilizado para la deteccion de fugas de memoria, errores de uso de memoria y desbordamientos de bufer durante el desarrollo.
  - Control de Versiones: Git



Compilacion y Ejecucion:

Sigue estos pasos para compilar y ejecutar el proyecto:

1.  Clonar el Repositorio:

2.  Requisitos Previos para la Compilacion:
    Asegurate de tener instalados los siguientes componentes en tu sistema:

      - Un compilador C++ (g++).
      - GNU Make.
      - Las librerias SFML (version 2.x.x).

3.  Compilar el Proyecto:
    Para compilar el juego, utiliza el Makefile proporcionado. pero primero utilizar "make clean" para la limpieza de codigo y luego si un m

    make clean
    make

    Una vez completado, se generara un ejecutable llamado 'juego' en el directorio raiz del proyecto.

4.  Preparar Recursos:
    Las Carpetas con los Recursos deben estar en el mismo directorio donde se encuentra el ejecutable 'juego'.

5.  Ejecutar el Juego:
    Para iniciar el juego, abre una terminal en el directorio del proyecto y ejecuta:

    ./juego
