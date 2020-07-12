//
// Created by Chiro on 6/7/2020.
//

#ifndef TAREACORTA3_BUSQUEDA_H
#define TAREACORTA3_BUSQUEDA_H


#include "MemoriaCache.h"
#include "LecturaArchivos.h"

class Busqueda {
public:
    Busqueda() {}

    void busquedaDato(MemoriaCache *memoria, ABB arbol, int cedula);

    void eliminacionCedula(int cedula, ABB *arbol, MemoriaCache *mc);

    void insertarElemento(int cedula, string nombre, ABB *arbol, MemoriaCache *mc);

    void purgar();

private:
    LecturaArchivos la;

};


#endif //TAREACORTA3_BUSQUEDA_H
