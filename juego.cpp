#include <iostream>
#include "menu.h"
#include "juego.h"
#include "formato.h"
#include "funciones.h"
#include "rlutil.h"
using namespace std;


void jugar(){
    rlutil::cls();
    int acuMinutos=0, turno=1;
    bool banderaCruce=false;
	string inicioPuente[4] = {"Yo", "Cami", "Tom s", "Bauti"};
	string finPuente[4]={" "," "," "," "};
	cout << "\nListos para cruzar el puente!!\n";

    do{
        acuMinutos=hacerCruce(acuMinutos, inicioPuente,finPuente, turno, banderaCruce);
    }while(acuMinutos<15 && !banderaCruce);
    if(banderaCruce&&acuMinutos<=15){
        dibujarBannerExito();
    }else{
        cout << "\nNo pudieron cruzar todos a tiempo :( " << endl;
    }
    cout << "\nTiempo total: " << acuMinutos << " minutos."<<endl;
}


int hacerCruce(int acuMinutos, string v1[],string v2[], int &turno, bool &banderaCruce){
    char persona1, persona2;
    int minutos;
    cout << "Presion  cualquier tecla para continuar...\n";
    rlutil::anykey();
    mostrarPersonajes();

    if (turno==1){
        cout << "\nEleg¡ dos personas para cruzar el puente y escrib¡ las iniciales.\n";
        cout << "Inicial de la Persona 1 (Y/C/T/B):  ";
        persona1= ingresarYValidarLetra(1,v1,v2);
        actualizarVectores(v1, v2, persona1);
        cout << "Inicial de la Persona 2 (Y/C/T/B):  ";
        persona2= ingresarYValidarLetra(1,v1,v2);
        actualizarVectores(v1, v2, persona2);
        int minutos1=buscarMinutos(persona1);
        int minutos2=buscarMinutos(persona2);
        if(minutos1>minutos2){
            minutos=minutos1;
        }else{
            minutos=minutos2;
        }

        turno=2;
    }else if(turno==2){
            cout << "\nEleg¡ a una persona para que vuelva con la linterna.\n";
            cout << "Ahora escrib¡ la inicial de esa persona (Y/C/T/B):  ";
        persona1= ingresarYValidarLetra(2,v1,v2);
        actualizarVectores(v2, v1, persona1);
        minutos=buscarMinutos(persona1);
        turno=1;
    }

	acuMinutos+=minutos;
	rlutil::cls();
	cout << "\nEl ultimo cruce sum¢: " << minutos << " minutos.\n";
	cout << "El tiempo total acumulado hasta ahora es: " << acuMinutos << " minutos.\n"<<endl;
	cout << "\nEn el otro lado del puente quedaron:\n";
	cout << " _______\n";
    mostrarVector(v2);
    cout << "\nY en el inicio est n:\n"<<endl;
    mostrarVector(v1);
    cout <<"|_______|\n";

    banderaCruce = chequearCruceCompleto(v1);

	return acuMinutos;
}



int ingresarYValidarMinutos(){
    int minutos;
    while (true) {
        cin >> minutos;
        if(minutos ==1||minutos ==2||minutos ==5||minutos ==8)
           return minutos;
        else
           cout << "Error. Intent  de nuevo." << endl;
        }
    }


char ingresarYValidarLetra(int turno,string v1[], string v2[]){
    char letra;
    while (true) {
        cin >> letra;
        letra=toupper(letra);

        if(letra =='Y'||letra =='C'||letra =='T'||letra =='B'){
            if (turno==1){
                for(int i=0;i<4;i++){
                    if (v1[i].front() ==letra)
                        return letra;
                }
             }else if (turno==2){
                for(int i=0;i<4;i++){
                    if (v2[i].front() ==letra)
                        return letra;
                }
             }
            cout << "Error. Esa persona est  del otro lado, ingres  otra: ";
        }else{
            cout << "Error. Intent  de nuevo: ";
        }

    }
}

int buscarMinutos(char persona){
        switch (persona) {
            case 'Y':
                return 1;
            case 'C':
                return 2;
            case 'T':
                return 5;
            case 'B':
                return 8;
            default:
                cout << "Error. Letra no v lida. Intent  de nuevo." << endl;
        }
}


void actualizarVectores(string v1[], string v2[], char letra){
    switch (letra) {
            case 'Y':
                v1[0]=" ";
                v2[0]="Yo";
                break;
            case 'C':
                v1[1]=" ";
                v2[1]="Cami";
                break;
            case 'T':
                v1[2]=" ";
                v2[2]="Tom s";
                break;
            case 'B':
                v1[3]=" ";
                v2[3]="Bauti";
                break;
    }
 }


bool chequearCruceCompleto(std::string v1[]){
    int cont=0;
     for(int i=0;i<4;i++){
        if (v1[i]==" ")
            cont++;
    }
    if (cont==4){
        return true;
    }else{
        return false;
    }
}


