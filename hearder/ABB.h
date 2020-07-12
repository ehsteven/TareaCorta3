//
// Created by Chiro on 14/6/2020.
//

#ifndef TAREACORTA2_ABB_H
#define TAREACORTA2_ABB_H

#include "stdio.h"
#include <iostream>

using namespace std;

class NodoBB {
public:
    NodoBB() {
        Hizq = NULL;
        Hder = NULL;
    }

    NodoBB(int num, string pNombre) {
        cedula = num;
        nombre = pNombre;
        Hizq = NULL;
        Hder = NULL;
    }

    NodoBB(int *num, string pNombre, int pCedula) {
        cedula = pCedula;
        nombre = pNombre;
        indice = *num;
        Hizq = NULL;
        Hder = NULL;
    }

    NodoBB(int pIndice, int pCedula) {
        cedula = pCedula;
        indice = pIndice;
        Hizq = NULL;
        Hder = NULL;
    }

    void InsertaBinario(int num, string nombre);

    void InsertaBinario(int *num, string nombre, int cedula);

    void InsertaBinario(int pIndice, int pCedula);

    int getCedula() { return cedula; }

    int getIndice() { return indice; }

    string getPalabra() { return nombre; }

    NodoBB *getHizq() { return Hizq; }

    NodoBB *getHder() { return Hder; }

    void setValor(int num) { cedula = num; }

    void setHizq(NodoBB *hizq) { Hizq = hizq; }

    void setHder(NodoBB *hder) { Hder = hder; }

    void setNombre(string nombreSede) { nombre = nombreSede; }

    void setCedula(int ced) { cedula = ced; }

    friend class ABB;

private:
    int cedula;
    int indice;
    string nombre;
    NodoBB *Hder;
    NodoBB *Hizq;
};

typedef NodoBB *pnodobb;

class ABB {
public:
    ABB() { raiz = NULL; }

    ~ABB();

    void InsertaNodo(int num, string nombre);

    void InsertaNodo(int *num, string nombre, int cedula);

    void InsertaNodo(int indice, int cedula);

    void eliminarCedula(int cedula);

    void eliminar(NodoBB **r, int cedula);

    void reemplazar(NodoBB **actual);

    NodoBB *buscarElemento(int num);

    NodoBB *buscarElementoIndice(int num);

    void PreordenR(NodoBB *R);

    void PreordenIndice(NodoBB *R);

    pnodobb getRaiz() { return raiz; }

private:
    NodoBB *raiz;


};

#endif //TAREACORTA2_ABB_H
