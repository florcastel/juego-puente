#include <iostream>
#include "menu.h"
#include "juego.h"
#include "formato.h"
#include "rlutil.h"

using namespace std;

int seleccionarOpcion(){

    int opcion;
    int opcionValida;
    dibujarBanner();
    mostrarMenu();
    cin >> opcion;
    opcionValida = validarOpcion(opcion);
    return opcionValida;
}


void mostrarMenu(){

    trazarLineaCyan();
    cout << "                     Menu Principal"<< endl;
    trazarLineaCyan();
    cout << "1 - Mostrar la historia" << endl;
    cout << "2 - Jugar Modo Tranqui (gu¡a | ayudita visual)" << endl;
    cout << "3 - Jugar Modo Dif¡cil (solo calculadora)" << endl;
    cout << "4 - Cr‚ditos" << endl;
    trazarLineaCyan();
    cout << "0 - Salir" << endl;
    trazarLineaCyan();
    cout << endl;
    cout << "Opci¢n: ";
}


int validarOpcion(int opcion){

    while(opcion <0 || opcion >4 ){
        cout << "Opci¢n incorrecta."<<endl;
        cout << "Ingrese una opci¢n v lida: ";
        cin >> opcion;
    }
    return opcion;
}


//esta variable opci¢n si necesito pasar por referencia para pisarla
//si el usuario se arrepiente de apretar 0 para salir, vuelve al while del main

void ejecutarOpcion(int &opcion){

    switch(opcion){
    case 1:
        mostrarHistoria();
        break;
    case 2:
        jugar();
        break;
   case 3:
        //jugarHard();
        cout << "Pr¢ximamente...\n";
        break;
    case 4:
        mostrarCreditos();
        break;
    case 0:
        char confirmacion;
        cout << "¨Est s seguro que quer‚s salir? (s/n): ";
        cin >> confirmacion;
        if (confirmacion == 's' || confirmacion == 'S') {
            cout << "Gracias por probar mi juego!" << endl;
        } else if (confirmacion == 'n' || confirmacion == 'N') {
            cout << "OK! Volviendo al Men£ Principal."<< endl;
            opcion = -1;
        } else {
            cout << "Tecla incorrecta! Volviendo al Men£ Principal."<< endl;
            opcion = -1;
        }
        break;
    }
}


