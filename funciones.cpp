#include <iostream>
#include "funciones.h"

using namespace std;

void mostrarVector(string v[]){
    int i;
    for(i=0;i<4;i++){
        cout << "| " << v[i] << "\t| "<< endl;
    }
}
