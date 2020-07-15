//
// Created by Chiro on 5/7/2020.
//

#ifndef TAREACORTA3_LECTURAARCHIVOS_H
#define TAREACORTA3_LECTURAARCHIVOS_H

#include "iostream"
#include "ABB.h"
#include "MemoriaCache.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class LecturaArchivos {
public:
    LecturaArchivos() {}

    int convertirNumero(string numS);

    void buscar(int indice, MemoriaCache *memoria, int cedula);

    ABB leerClientes(ABB arbolBinario, int firts);

    void crearArchivoIndex(ABB arbol);

    ABB leerArchivoIndex();

    void llenarMemoria(MemoriaCache *memoria, int tope, int indice);

    void marcarEliminados(int cedula);

    void crearArchivoTemp(string archivo, string cadena, int tipo);

    void insertar(int cedula, string nombre, ABB *arbol, MemoriaCache *mc);

    void actualizarClientes(string cliente, string temp);

    int insertarIndice();

    void purgar();

    int cantidadBorradosAntes20();
};


#endif //TAREACORTA3_LECTURAARCHIVOS_H
