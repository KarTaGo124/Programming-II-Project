cmake_minimum_required(VERSION 3.26)
project(PROYECTO)

set(CMAKE_CXX_STANDARD 17)

add_executable(PROYECTO main.cpp
        Ejercicio.h
        Usuario.cpp
        Usuario.h
        Flexibilidad.cpp
        Flexibilidad.h
        Fuerza.cpp
        Fuerza.h
        Cardio.cpp
        Cardio.h
        BaseDeDatos.cpp
        BaseDeDatos.h
        Menus.h
        Librerias.h
        ReporteGeneral.txt
)
add_executable(borrador Borrador/main.cpp
        Borrador/CMET.cpp
        Borrador/CMET.h)
