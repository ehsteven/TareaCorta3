//
// Created by Chiro on 14/6/2020.
//

#include "../hearder/ABB.h"

ABB::~ABB() {

}

void NodoBB::InsertaBinario(int pIndice, int pCedula) {
    if (pCedula < cedula) {
        if (Hizq == NULL) {
            Hizq = new NodoBB(pIndice, pCedula);
        } else {
            Hizq->InsertaBinario(pIndice, pCedula);
        }
    } else {
        if (Hder == NULL) {
            Hder = new NodoBB(pIndice, pCedula);
        } else {
            Hder->InsertaBinario(pIndice, pCedula);
        }
    }
}

void NodoBB::InsertaBinario(int num, string pNombre) {
    if (num < cedula) {
        if (Hizq == NULL) {
            Hizq = new NodoBB(num, pNombre);
        } else {
            Hizq->InsertaBinario(num, pNombre);
        }
    } else {
        if (Hder == NULL) {
            Hder = new NodoBB(num, pNombre);
        } else {
            Hder->InsertaBinario(num, pNombre);
        }
    }
}

void NodoBB::InsertaBinario(int *num, string pNombre, int pCedula) {
    if (*num < indice) {
        if (Hizq == NULL) {
            Hizq = new NodoBB(num, pNombre, pCedula);
        } else {
            Hizq->InsertaBinario(num, pNombre, pCedula);
        }
    } else {
        if (Hder == NULL) {
            Hder = new NodoBB(num, pNombre, pCedula);
        } else {
            Hder->InsertaBinario(num, pNombre, pCedula);
        }
    }
}

void ABB::InsertaNodo(int num, string nombre) {
    if (raiz == NULL) {
        raiz = new NodoBB(num, nombre);
    } else {
        raiz->InsertaBinario(num, nombre);
    }
}

void ABB::InsertaNodo(int indice, int cedula) {
    if (raiz == NULL) {
        raiz = new NodoBB(indice, cedula);
    } else {
        raiz->InsertaBinario(indice, cedula);
    }
}

void ABB::InsertaNodo(int *num, string nombre, int cedula) {
    if (raiz == NULL) {
        raiz = new NodoBB(num, nombre, cedula);
    } else {
        raiz->InsertaBinario(num, nombre, cedula);
    }
}

NodoBB *ABB::buscarElemento(int num) {
    NodoBB *aux = raiz;
    int encontrado = 0;
    while (!encontrado && aux != NULL) {
        if (num == aux->getCedula())
            encontrado = 1;
        else {
            if (num <= aux->getCedula()) {
                aux = aux->Hizq;
            } else {
                aux = aux->Hder;
            }
        }
    }
    return aux;
}

NodoBB *ABB::buscarElementoIndice(int num) {
    NodoBB *aux = raiz;
    int encontrado = 0;
    while (!encontrado && aux != NULL) {
        if (num == aux->getCedula())
            encontrado = 1;
        else
            aux = aux->Hder;
    }
    return aux;
}

void ABB::PreordenR(NodoBB *R) {
    if (R == NULL) {
        return;
    } else {
        cout << "Indice: " << R->indice;
        cout << " - Nombre: " << R->nombre;
        cout << " - Cedula: " << R->cedula << endl;
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void ABB::PreordenIndice(NodoBB *R) {
    if (R == NULL) {
        return;
    } else {
        cout << "Indice: " << R->indice;
        cout << " - Cedula: " << R->cedula << endl;
        PreordenIndice(R->Hizq);
        PreordenIndice(R->Hder);
    }
}

void ABB::eliminarCedula(int cedula) {
    eliminar(&raiz, cedula);
}

void ABB::eliminar(NodoBB **r, int cedula) {
    if (!(*r))
        cout << "\nNo se encontro la cedula" << endl;
    else {
        if (cedula < (*r)->cedula)
            eliminar(&(*r)->Hizq, cedula);
        else {
            if (cedula > (*r)->cedula)
                eliminar(&(*r)->Hder, cedula);
            else {
                NodoBB *q;
                q = (*r);
                if (q->Hizq == NULL) {
                    (*r) = q->Hder;
                    cout << "Se ha eliminado correctamente\n" << endl;
                } else {
                    if (q->Hder == NULL) {
                        (*r) = q->Hizq;
                        cout << "Se ha eliminado correctamente\n" << endl;
                    } else
                        reemplazar(&q);
                    delete (q);
                }
            }
        }
    }
}

void ABB::reemplazar(NodoBB **actual) {
    NodoBB *a, *p;
    p = *actual;
    a = (*actual)->Hizq;
    while (a->Hder) {
        p = a;
        a = a->Hder;
    }
    (*actual)->cedula = a->cedula;
    if (p == (*actual))
        p->Hizq = a->Hizq;
    else
        p->Hder = a->Hizq;
    (*actual) = a;
}


//}
//
//string ABB::PreordenRString(NodoBB *R, string dato) {
//    if (R == NULL) {
//        return "";
//    } else {
//        if (R->numerico) {
//            dato += to_string(R->getValor()) + " -> ";
//        } else {
//            dato += R->nombreEstudiante + " -> ";
//        }
//        PreordenRString(R->Hizq, dato);
//        PreordenRString(R->Hder, dato);
//    }
//    return dato;
//}
//

/*
void ABB::InordenR(NodoBB *R) {
    if (R == NULL) {
        return;
    } else {
        InordenR(R->Hizq);
        if (R->numerico) {
            cout << R->cedula << " -> ";
        } else {
            cout << R->nombreEstudiante << " -> ";
        }
        InordenR(R->Hder);
    }
}
*/


//
//void ABB::PostordenR(NodoBB *R) {
//    if (R == NULL) {
//        return;
//    } else {
//        PostordenR(R->Hizq);
//        PostordenR(R->Hder);
//        if (R->numerico) {
//            cout << R->cedula << " -> ";
//        } else {
//            cout << R->nombreEstudiante << " -> ";
//        }
//    }
//}


//pnodobb ABB::sacarUltimo() {
//    pnodobb aux = raiz;
//    while (aux->siguiente != NULL) {
//        aux = aux->siguiente;
//    }
//    pnodobb nuevo = new NodoBB();
//    nuevo->Hizq = aux->Hizq;
//    nuevo->Hder = aux->Hder;
//    if (aux->numerico) {
//        nuevo->cedula = aux->cedula;
//        nuevo->numerico = true;
//    } else {
//        nuevo->nombreEstudiante = aux->nombreEstudiante;
//        nuevo->numerico = false;
//    }
//    return nuevo;
//}
//
//void ABB::Mostrar() {
//    pnodobb aux = raiz;
//    while (aux != NULL) {
//        PreordenR(aux);
//        aux = aux->siguiente;
//    }
//}

//string ABB::MostrarString() {
//    string dato = "";
//    pnodobb aux = raiz;
//    while (aux != NULL) {
//        dato = PreordenRString(aux, dato);
//        aux = aux->siguiente;
//    }
//    return dato;
//}

