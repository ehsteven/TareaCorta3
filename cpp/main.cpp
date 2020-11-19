#include "../hearder/phc.h"
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Spanish");
    LecturaArchivos la;
    ABB arbol;
    Busqueda b;
    MemoriaCache mc;

    Operador op;
    op.operaciones(arbol, la, b, mc);

    return 0;
}