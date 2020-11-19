//
// Created by Chiro on 5/7/2020.
//

#include "../hearder/LecturaArchivos.h"

int MAX;

int LecturaArchivos::convertirNumero(string numS) {
    int Numero;
    stringstream geek(numS);
    geek >> Numero;
    return Numero;
}

ABB LecturaArchivos::leerClientes(ABB arbolCompleto, int first) {
    string nombreArch = "..\\archivos\\Clientes.txt";
    string temp = "..\\archivos\\temp.txt";
    ifstream ar(nombreArch);
    remove(temp.c_str());
    string s, ante = "";
    int ind = 1;
    int maximo = 0;
    while (!ar.eof()) {
        getline(ar, s);
        string word, cedula, nombre, borrado = "";
        int i = 0;
        for (auto x : s) {
            if (x == ';' || x == '\n') {
                switch (i) {
                    case 0:
                        cedula = word;
                        word = "";
                        break;
                    case 1:
                        nombre = word;
                        word = "";
                        break;
                    case 2:
                        borrado = word;
                        word = "";
                        break;
                }
                i++;
            } else
                word = word += x;
        }
        if (nombre == "")
            nombre = word;
        else
            borrado = word;
        int cedulaNum = convertirNumero(cedula);
        if (borrado == "") {
            NodoBB *aux = arbolCompleto.buscarElementoIndice(cedulaNum);
            if (ante != s && s != "") {
                if (aux == NULL) {
                    crearArchivoTemp(temp, s, 1);
                    arbolCompleto.InsertaNodo(&ind, word, cedulaNum);
                    ind++;
                } else {
                    crearArchivoTemp(temp, s, 0);
                    cout << "El elemento ya fue creado: " << cedulaNum << endl;
                }
            }
            ante = s;
        } else {
            crearArchivoTemp(temp, s, 1);
        }
        if (s != "")
            maximo++;
    }
    MAX = maximo;
    ar.close();
    if (first == 0) {
        remove(nombreArch.c_str());
        actualizarClientes(nombreArch, temp);
        remove(temp.c_str());
    }
    crearArchivoIndex(arbolCompleto);
    return arbolCompleto;
}

ABB LecturaArchivos::leerArchivoIndex() {
    ABB arbol;
    string nombreArch = "..\\archivos\\indice.txt";
    ifstream ar(nombreArch);
    string s, ante = "";
    int ind = 1;
    while (!ar.eof()) {
        getline(ar, s);
        string word, indice, cedula = "";
        int i = 0;
        for (auto x : s) {
            if (x == ';' || x == '\n') {
                switch (i) {
                    case 0:
                        indice = word;
                        word = "";
                        break;
                    case 1:
                        cedula = word;
                        word = "";
                        break;
                }
                i++;
            } else
                word = word += x;
        }
        cedula = word;
        int indiceNum = convertirNumero(indice);
        int cedulaNum = convertirNumero(cedula);
        //NodoBB *aux = arbol.buscarElemento(cedulaNum);
        //if (aux == NULL) {
        if (ante != s && s != "") {
            arbol.InsertaNodo(indiceNum, cedulaNum);
            ind++;
            ante = s;
        }
        //}
    }
    ar.close();
    return arbol;
}

void LecturaArchivos::crearArchivoIndex(ABB arbol) {
    string nombreArch = "..\\archivos\\indice.txt";
    ofstream file;
    remove(nombreArch.c_str());
    file.open(nombreArch, ios::app | ios::out);
    NodoBB *aux = arbol.getRaiz();
    while (aux) {
        file << aux->getIndice() << ";" << aux->getCedula() << "\n";
        aux = aux->getHder();
    }
    file.close();
}

void LecturaArchivos::buscar(int indice, MemoriaCache *memoria, int pCedula) {
    string nombreArch = "..\\archivos\\Clientes.txt";
    ifstream ar(nombreArch);
    string s, ante = "";
    int ind = 1;
    memoria->setTope(0);
    bool flag = false;
    while (!ar.eof()) {
        getline(ar, s);
        string word, cedula, nombre, borrado = "";
        int i = 0;
        if (ind == indice) {
            for (auto x : s) {
                if (x == ';' || x == '\n') {
                    switch (i) {
                        case 0:
                            cedula = word;
                            word = "";
                            break;
                        case 1:
                            nombre = word;
                            word = "";
                            break;
                    }
                    i++;
                } else
                    word = word += x;
            }
            if (nombre == "")
                nombre = word;
            else
                borrado = word;
            int num = convertirNumero(cedula);
            if (ante != s && s != "") {
                if (memoria->getTope() < 20) {
                    if ((borrado == "" && num == pCedula) || (flag && borrado == "")) {
                        int ced = convertirNumero(cedula);
                        memoria->llenarMemoria(ced, nombre, memoria->getTope());
                        ind = indice;
                        ante = s;
                        flag = true;
                    }
                } else
                    break;
            }
        } else
            ind++;
    }
    if (memoria->getTope() < 20) {
        llenarMemoria(memoria, memoria->getTope(), 1);
    }
}

void LecturaArchivos::llenarMemoria(MemoriaCache *memoria, int tope, int indice) {
    string nombreArch = "..\\archivos\\Clientes.txt";
    ifstream ar(nombreArch);
    string s;
    int ind = 1;
    while (!ar.eof()) {
        getline(ar, s);
        string word, cedula, nombre, borrado = "";
        int i = 0;
        if (ind == indice) {
            if (tope < 20) {
                for (auto x : s) {
                    if (x == ';' || x == '\n') {
                        switch (i) {
                            case 0:
                                cedula = word;
                                word = "";
                                break;
                            case 1:
                                nombre = word;
                                word = "";
                                break;
                            case 2:
                                borrado = word;
                                word = "";
                                break;
                        }
                        i++;
                    } else
                        word = word += x;
                }
                if (nombre == "")
                    nombre = word;
                else
                    borrado = word;
                if (borrado == "" && s != "") {
                    int ced = convertirNumero(cedula);
                    memoria->llenarMemoria(ced, nombre, memoria->getTope());
                    tope++;
                }
            } else
                break;
        } else {
            ind++;
        }
    }
}

void LecturaArchivos::marcarEliminados(int cedula) {
    string nombreArch = "..\\archivos\\Clientes.txt";
    string temp = "..\\archivos\\temp.txt";
    ifstream ar(nombreArch);
    remove(temp.c_str());
    string s;
    int ind = 0;
    while (!ar.eof()) {
        getline(ar, s);
        string word, cedula1, nombre, borrado = "";
        int i = 0;
        for (auto x : s) {
            if (x == ';' || x == '\n') {
                switch (i) {
                    case 0:
                        cedula1 = word;
                        word = "";
                        break;
                    case 1:
                        nombre = word;
                        word = "";
                        break;
                    case 2:
                        borrado = word;
                        word = "";
                        break;
                }
                i++;
            } else
                word = word += x;
        }
        if (nombre == "")
            nombre = word;
        else
            borrado = word;

        int cedulaNum = convertirNumero(cedula1);
        if (cedulaNum == cedula && borrado != "")
            crearArchivoTemp(temp, s, 1);
        else if (cedulaNum == cedula)
            crearArchivoTemp(temp, s, 0);
        else
            crearArchivoTemp(temp, s, 1);
    }
    ar.close();
    remove(nombreArch.c_str());
    actualizarClientes(nombreArch, temp);
    remove(temp.c_str());
}

void LecturaArchivos::actualizarClientes(string cliente, string temp) {
    ifstream ar(temp);
    string s, ante;
    while (!ar.eof()) {
        ante = s;
        getline(ar, s);
        if (s != ante && s != "")
            crearArchivoTemp(cliente, s, 1);
    }
    ar.close();
}

void LecturaArchivos::crearArchivoTemp(string archivo, string cadena, int tipo) {
    string nombreArch = archivo;
    ofstream file;
    file.open(nombreArch, ios::app | ios::out);
    if (tipo == 0)
        file << cadena << ";1" << "\n";
    else
        file << cadena << "\n";
    file.close();
}

void LecturaArchivos::insertar(int cedula, string nombre, ABB *arbol, MemoriaCache *mc) {
    NodoBB *aux = arbol->buscarElemento(cedula);
    if (aux != NULL) {
        cout << "El numero de cedula ya fue ingresado" << endl;
        return;
    }
    mc->setTope(0);
    string nombreArch = "..\\archivos\\Clientes.txt";
    ofstream file;
    file.open(nombreArch, ios::app | ios::out);
    file << cedula << ";" << nombre << "\n";
    file.close();
    int indiceTotal = insertarIndice();
    string archIndice = "..\\archivos\\indice.txt";
    ofstream file1;
    file1.open(archIndice, ios::app | ios::out);
    file1 << indiceTotal << ";" << cedula << "\n";
    file1.close();
    arbol->InsertaNodo(indiceTotal, cedula);
    mc->llenarMemoria(cedula, nombre, mc->getTope());
    int borrado = cantidadBorradosAntes20();
    llenarMemoria(mc, mc->getTope(), (indiceTotal + borrado) - 20);
    cout << "Se ha ingresado correctamente\n" << endl;
}

int LecturaArchivos::insertarIndice() {
    string nombreArch = "..\\archivos\\indice.txt";
    ifstream ar(nombreArch);
    string s;
    int ind = 0;
    while (!ar.eof()) {
        getline(ar, s);
        ind++;
    }
    ar.close();
    return ind;
}

void LecturaArchivos::purgar() {
    string nombreArch = "..\\archivos\\Clientes.txt";
    string temp = "..\\archivos\\temp.txt";
    ifstream ar(nombreArch);
    remove(temp.c_str());
    string s, ante = "";
    int ind = 1;
    ABB arboltemp;
    while (!ar.eof()) {
        getline(ar, s);
        string word, cedula, nombre, borrado = "";
        int i = 0;
        for (auto x : s) {
            if (x == ';' || x == '\n') {
                switch (i) {
                    case 0:
                        cedula = word;
                        word = "";
                        break;
                    case 1:
                        nombre = word;
                        word = "";
                        break;
                    case 2:
                        borrado = word;
                        word = "";
                        break;
                }
                i++;
            } else
                word = word += x;
        }
        if (nombre == "")
            nombre = word;
        else
            borrado = word;
        if (ante != s) {
            if (borrado == "") {
                crearArchivoTemp(temp, s, 1);
                int numeroCed = convertirNumero(cedula);
                arboltemp.InsertaNodo(&ind, nombre, numeroCed);
                ind++;
                ante = s;
            }
        }
    }
    ar.close();
    remove(nombreArch.c_str());
    actualizarClientes(nombreArch, temp);
    remove(temp.c_str());
}

int LecturaArchivos::cantidadBorradosAntes20() {
    string nombreArch = "..\\archivos\\Clientes.txt";
    ifstream ar(nombreArch);
    string s;
    int ind = 0, total = 0;
    while (!ar.eof()) {
        getline(ar, s);
        string word, cedula, nombre, borrado = "";
        int i = 0;
        for (auto x : s) {
            if (x == ';' || x == '\n') {
                switch (i) {
                    case 0:
                        cedula = word;
                        word = "";
                        break;
                    case 1:
                        nombre = word;
                        word = "";
                        break;
                }
                i++;
            } else
                word = word += x;
        }
        if (nombre == "")
            continue;
        else {
            total++;
        }
    }
    return total;
}