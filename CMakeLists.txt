cmake_minimum_required(VERSION 3.26)
project(PROYECTO)

set(CMAKE_CXX_STANDARD 17)

add_executable(PROYECTO src/main.cpp
        src/user/Usuario.cpp
        src/exercise/Flexibilidad.cpp
        src/exercise/Fuerza.cpp
        src/exercise/Cardio.cpp
        src/user/BaseDeDatos.cpp
        docs/ReporteGeneral.txt
)

