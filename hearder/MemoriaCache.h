//
// Created by Chiro on 6/7/2020.
//

#ifndef TAREACORTA3_MEMORIACACHE_H
#define TAREACORTA3_MEMORIACACHE_H


#include "ABB.h"

class NodoCache {
public:
    NodoCache() {}

    virtual ~NodoCache();

    int getCedula() { return cedula; }

    string getNombre() { return nombre; }

private:
    string nombre;
    int cedula;

    friend class MemoriaCache;
};

class MemoriaCache {
public:
    MemoriaCache();

    virtual ~MemoriaCache();

    const NodoCache *getMemoria() { return memoria; }

    void llenarMemoria(int cedula, string nombre, int topeActual);

    void reacomodarMemoria(int indice);

    void imprimerCache();

    int buscarIndice(int cedula);

    bool memoriaVacia() { return tope == 0; }

    int getTope() { return tope; }

    int getCedula() { return this->getCedula(); }

    void setTope(int topeN) { tope = topeN; }

private:
    NodoCache memoria[20];
    int tope;
};

#endif //TAREACORTA3_MEMORIACACHE_H
