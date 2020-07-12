cmake_minimum_required(VERSION 3.16)
project(TareaCorta3)

set(CMAKE_CXX_STANDARD 14)

add_executable(TareaCorta3 cpp/main.cpp hearder/phc.h cpp/LecturaArchivos.cpp hearder/LecturaArchivos.h cpp/ABB.cpp hearder/ABB.h cpp/Busqueda.cpp hearder/Busqueda.h cpp/MemoriaCache.cpp hearder/MemoriaCache.h cpp/Operador.cpp hearder/Operador.h)