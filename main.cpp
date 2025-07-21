#include "menu.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

int main()
{
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);

    int opcion;

    do{
        rlutil::cls();
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion);
        cout << "Presion  cualquier tecla para continuar...\n";
        rlutil::anykey();

    }while(opcion!=0);

    return 0;
}
