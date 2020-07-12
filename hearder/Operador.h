//
// Created by Chiro on 11/7/2020.
//

#ifndef TAREACORTA3_OPERADOR_H
#define TAREACORTA3_OPERADOR_H


#include "ABB.h"
#include "Busqueda.h"

using namespace std;

class Operador {
public:
    Operador() {}

    void operaciones(ABB arbol, LecturaArchivos la, Busqueda busqueda, MemoriaCache memoriaCache);

    int convertirNumero(string numS);

    void busquedaDato(MemoriaCache *mc, Busqueda b, ABB arbol);

    void eliminarDato(MemoriaCache *mc, Busqueda b, ABB *arbol);

    void purgarDatos(Busqueda b, ABB *arbol, MemoriaCache *mc);

    void reindexar(ABB *arbol, LecturaArchivos la, MemoriaCache *mc);

    void insertarDato(MemoriaCache *mc, Busqueda b, ABB *arbol);
};


#endif //TAREACORTA3_OPERADOR_H
