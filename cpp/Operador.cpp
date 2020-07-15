//
// Created by Chiro on 11/7/2020.
//
#include "../hearder/Operador.h"

int Operador::convertirNumero(string numS) {
    int Numero;
    stringstream geek(numS);
    geek >> Numero;
    return Numero;
}


void Operador::operaciones(ABB arbol, LecturaArchivos la, Busqueda b, MemoriaCache mc) {
    bool sigue = true;
    ABB arbolInterno;
    bool inhabilitar = true;
    while (sigue) {
        string h;
        cout << "\n************ MENU DE INICIO *************" << endl;
        cout << "\n1. Cargar datos\n2. Busqueda\n3. Insertar\n4. Eliminar\n5. Purgar\n6. Reindexar\n7. Salir" << endl;
        cout << "Escoja una opción:";
        getline(cin, h, '\n');
        int seccion = convertirNumero(h);
        switch (seccion) {
            case 1:
                if (inhabilitar) {
                    cout << "\nEventualidades: \n" << endl;
                    arbolInterno = la.leerClientes(arbolInterno, 0);
                    arbol = la.leerArchivoIndex();
                    if (arbol.getRaiz() != NULL) {
                        cout << "*************************************"
                                "\nLos datos se han cargado correctamente!" << endl;
                        inhabilitar = false;
                    } else
                        cout << "No se han podido cargar los datos correctamente\nRevise el archivo Clientes.txt"
                             << endl;
                } else
                    cout << "*************************************"
                            "\nLos datos se han cargado correctamente!" << endl;
                break;
            case 2:
                if (arbol.getRaiz() != NULL)
                    busquedaDato(&mc, b, arbol);
                else
                    cout << "\nNo hay datos cargados" << endl;
                break;
            case 3:
                if (arbol.getRaiz() != NULL)
                    insertarDato(&mc, b, &arbol);
                else
                    cout << "\nNo hay datos cargados" << endl;
                break;
            case 4:
                if (arbol.getRaiz() != NULL)
                    eliminarDato(&mc, b, &arbol);
                else
                    cout << "\nNo hay datos cargados" << endl;
                break;
            case 5:
                purgarDatos(b, &arbol, &mc);
                break;
            case 6:
                reindexar(&arbol, la, &mc);
                break;
            case 7:
                sigue = false;
                break;
            default:
                cout << "Opcion no valida!\n";
                break;
        }
    }
}

void Operador::busquedaDato(MemoriaCache *mc, Busqueda b, ABB arbol) {
    cout << "\n********** BUSQUEDA DE CEDULA **********\n";
    cout << "\nDigite la cédula:";
    string cedula;
    getline(cin, cedula, '\n');
    int numCedula = convertirNumero(cedula);
    if (numCedula != 0) {
        b.busquedaDato(mc, arbol, numCedula);
        cout << "Árbol:" << endl;
        arbol.PreordenIndice(arbol.getRaiz());
        cout << "\nMemoria Caché:" << endl;
        mc->imprimerCache();
    } else {
        cout << "Hubo un error!" << endl;
    }
}

void Operador::eliminarDato(MemoriaCache *mc, Busqueda b, ABB *arbol) {
    cout << "\n*********** ELIMINACION DE CÉDULA ***********\n";
    cout << "\nDigite la cédula:";
    string cedula;
    getline(cin, cedula, '\n');
    int numCedula = convertirNumero(cedula);
    if (numCedula != 0) {
        b.eliminacionCedula(numCedula, arbol, mc);
        cout << "Árbol:" << endl;
        arbol->PreordenIndice(arbol->getRaiz());
        cout << "\nMemoria Caché:" << endl;
        mc->imprimerCache();
    } else {
        cout << "Hubo un error!" << endl;
    }
}

void Operador::purgarDatos(Busqueda b, ABB *arbol, MemoriaCache *mc) {
    cout << "\n*********** PURGADO ***********\n";
    b.purgar();
    cout << "Árbol:" << endl;
    arbol->PreordenIndice(arbol->getRaiz());
    cout << "\nMemoria Caché:" << endl;
    mc->imprimerCache();
}

void Operador::reindexar(ABB *arbol, LecturaArchivos la, MemoriaCache *mc) {
    cout << "\n*********** REINDEXAR ***********\n";
    ABB arbolInterno, arbolTemp;
    arbolInterno = la.leerClientes(arbolInterno, 0);
    arbolTemp = la.leerArchivoIndex();
    arbol = &arbolTemp;
    cout << "Árbol:" << endl;
    arbol->PreordenIndice(arbol->getRaiz());
    cout << "\nMemoria Caché:" << endl;
    mc->imprimerCache();
}

void Operador::insertarDato(MemoriaCache *mc, Busqueda b, ABB *arbol) {
    cout << "\n********** INSERTAR NUEVO ELEMENTO **********\n";
    string cedula, nombre;
    cout << "\nDigite el nombre:";
    getline(cin, nombre, '\n');
    cout << "Digite la cédula:";
    getline(cin, cedula, '\n');
    int numCedula = convertirNumero(cedula);
    if (numCedula != 0) {
        b.insertarElemento(numCedula, nombre, arbol, mc);
        cout << "Árbol:" << endl;
        arbol->PreordenIndice(arbol->getRaiz());
        cout << "\nMemoria Caché:" << endl;
        mc->imprimerCache();
    } else
        cout << "Hubo un error" << endl;

}


Operador::~Operador() {
}


