#include "../hearder/phc.h"
//#include <iostream>

using namespace std;

int main() {
    LecturaArchivos la;
    ABB arbol, arbol1;
    Busqueda b;
    MemoriaCache mc;

    Operador op;
    op.operaciones(arbol, la, b, mc);
//    while(true){
//        string h = "goal como esyas";
//        cout << h << endl;
//        getline(cin, h, '\n');
//        cout << h << endl;
//    }

    return 0;
}