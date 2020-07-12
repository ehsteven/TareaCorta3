//
// Created by Chiro on 6/7/2020.
//

#include "../hearder/MemoriaCache.h"

MemoriaCache::MemoriaCache() {
    tope = 0;
    for (int i = 0; i <= 19; i++) {
        memoria[i].nombre = "";
        memoria[i].cedula = 0;
    }
}

void MemoriaCache::llenarMemoria(int cedula, string nombre, int topeActual) {
    memoria[topeActual].cedula = cedula;
    memoria[topeActual].nombre = nombre;
    tope++;
}

void MemoriaCache::reacomodarMemoria(int indice) {
    if (indice == tope) {
        memoria[19].cedula = 0;
        memoria[19].nombre = "";
        return;
    }
    for (int i = indice; i < tope - 1; i++) {
        memoria[i] = memoria[i + 1];
    }
    memoria[19].cedula = 0;
    memoria[19].nombre = "";
}

void MemoriaCache::imprimerCache() {
    if (memoriaVacia()) {
        cout << "\nLa memoria esta vacia!" << endl;
        return;
    }
    for (int i = 0; i < tope; i++) {
        NodoCache aux = memoria[i];
        cout << i + 1 << ". Nombre: " << aux.nombre << " - Cedula: " << aux.cedula << endl;
    }
}

int MemoriaCache::buscarIndice(int cedula) {
    int encontrado = 0;
    if (!memoriaVacia()) {
        for (int i = 0; i < tope; i++) {
            NodoCache aux = memoria[i];
            if (cedula == aux.getCedula()) {
                return i;
            }
        }
    }
    if (encontrado == 0 || memoriaVacia())
        return -1;
    return -1;
}

MemoriaCache::~MemoriaCache() {

}

NodoCache::~NodoCache() {

}
