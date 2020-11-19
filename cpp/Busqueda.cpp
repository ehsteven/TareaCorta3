//
// Created by Chiro on 6/7/2020.
//

#include "../hearder/Busqueda.h"

void Busqueda::busquedaDato(MemoriaCache *memoria, ABB arbol, int cedula) {
    int busqueda = 0;
    if (!memoria->memoriaVacia()) {
        for (int i = 0; i < memoria->getTope(); i++) {
            NodoCache aux = memoria->getMemoria()[i];
            if (cedula == aux.getCedula()) {
                cout << "\nNombre: " << aux.getNombre() << " - Cedula: " << aux.getCedula() << "\n" << endl;
                busqueda = -1;
            }
        }
    }
    if (busqueda == 0) {
        NodoBB *aux = arbol.buscarElemento(cedula);
        if (aux != NULL) {
            la.buscar(aux->getIndice(), memoria, cedula);
            NodoCache nodoCache = memoria->getMemoria()[0];
            cout << "\nNombre: " << nodoCache.getNombre() << " - Cedula: " << nodoCache.getCedula() << "\n" << endl;
        }
        else {
            cout << "\nNo se encontro la cedula: " << cedula <<"\n"<< endl;
        }
    }
}

void Busqueda::eliminacionCedula(int cedula, ABB *arbol, MemoriaCache *mc) {
    NodoBB *aux = arbol->buscarElemento(cedula);
    if (aux != NULL) {
        arbol->eliminarCedula(cedula);
        int h = mc->buscarIndice(cedula);
        if (h != -1) {
            mc->reacomodarMemoria(h);
        }
        la.marcarEliminados(cedula);
    }else
        cout << "\nEl elemento no existe!\n" << endl;

}

void Busqueda::insertarElemento(int cedula, string nombre, ABB *arbol, MemoriaCache *mc) {
    la.insertar(cedula, nombre, arbol, mc);
}

void Busqueda::purgar() {
    la.purgar();
}
