#include "../hearder/phc.h"
#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Spanish");
    LecturaArchivos la;
    ABB arbol, arbol1;
    Busqueda b;
    MemoriaCache mc;

    Operador op;
    op.operaciones(arbol, la, b, mc);

    return 0;
}