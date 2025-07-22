#include <iostream>
#include "menu.h"
#include "juego.h"
#include "formato.h"
#include "funciones.h"
#include "rlutil.h"
using namespace std;


void jugar(){
    rlutil::cls();
    const int CANTIDAD_PERSONAS = 4;
    const char INICIALES[CANTIDAD_PERSONAS] = {'Y', 'C', 'T', 'B'};
    const int MINUTOS[CANTIDAD_PERSONAS] = {1, 2, 5, 8};
    int acuMinutos=0, turno=1;
    bool banderaCruce=false;
	string inicioPuente[CANTIDAD_PERSONAS] = {"Yo", "Cami", "Tom s", "Bauti"};
	string finPuente[CANTIDAD_PERSONAS]={" "," "," "," "};
	cout << "\nListos para cruzar el puente!!\n";

    do{
        acuMinutos=hacerCruce(acuMinutos, inicioPuente,finPuente, turno, banderaCruce, INICIALES, MINUTOS, CANTIDAD_PERSONAS);
    }while(acuMinutos<15 && !banderaCruce);
    if(banderaCruce&&acuMinutos<=15){
        dibujarBannerExito();
    }else{
        cout << "\nNo pudieron cruzar todos a tiempo :( " << endl;
    }
    cout << "\nTiempo total: " << acuMinutos << " minutos."<<endl;
}


int hacerCruce(int acuMinutos, string v1[],string v2[], int &turno, bool &banderaCruce, const char iniciales[], const int minutos[], int cant){
    char persona1, persona2;
    int minutosCruce;
    cout << "Presion  cualquier tecla para continuar...\n";
    rlutil::anykey();
    mostrarPersonajes();

    if (turno==1){
        cout << "\nEleg¡ dos personas para cruzar el puente y escrib¡ las iniciales.\n";
        cout << "Inicial de la Persona 1 (Y/C/T/B):  ";
        cin >>persona1;
        persona1= validarLetra(1,v1,v2, cant, persona1);
        actualizarVectores(v1, v2, persona1);
        cout << "Inicial de la Persona 2 (Y/C/T/B):  ";
        cin >>persona2;
        while(persona1==toupper(persona2)){
            cout << "Ingresaste 2 veces la misma persona.\n";
            cout << "Ingres  la inicial de la Persona 2 (Y/C/T/B):  ";
            cin >>persona2;
        }
        persona2= validarLetra(1,v1,v2, cant, persona2);
        actualizarVectores(v1, v2, persona2);
        int minutos1=buscarMinutos(persona1, iniciales, minutos,cant);
        int minutos2=buscarMinutos(persona2, iniciales, minutos,cant);
        if(minutos1>minutos2){
            minutosCruce=minutos1;
        }else{
            minutosCruce=minutos2;
        }

        turno=2;
    }else if(turno==2){
        cout << "\nEleg¡ a una persona para que vuelva con la linterna.\n";
        cout << "Ahora escrib¡ la inicial de esa persona (Y/C/T/B):  ";
        cin >>persona1;
        persona1= validarLetra(2,v1,v2, cant,persona1);
        actualizarVectores(v2, v1, persona1);
        minutosCruce=buscarMinutos(persona1, iniciales, minutos, cant);
        turno=1;
    }

	acuMinutos+=minutosCruce;
	rlutil::cls();
	cout << "\nEl ultimo cruce sum¢: " << minutosCruce << " minutos.\n";
	cout << "El tiempo total acumulado hasta ahora es: " << acuMinutos << " minutos.\n"<<endl;
	cout << "\nEn el otro lado del puente quedaron:\n";
	rlutil::setColor(rlutil::LIGHTGREEN);
	cout << " _______\n";
    mostrarVector(v2);
    rlutil::setColor(rlutil::WHITE);
    cout << "\nY en el inicio est n:\n"<<endl;
    rlutil::setColor(rlutil::LIGHTGREEN);
    mostrarVector(v1);
    cout <<"|_______|\n";
    rlutil::setColor(rlutil::WHITE);
    banderaCruce = chequearCruceCompleto(v1);
	return acuMinutos;
}


//para calculos a mano - juego en modo dif¡cil
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


char validarLetra(int turno,string v1[], string v2[], int cant, char letra){
    while (true) {
        letra=toupper(letra);
        if(letra =='Y'||letra =='C'||letra =='T'||letra =='B'){
            if (turno==1){
                for(int i=0;i<cant;i++){
                    if (v1[i].front() ==letra)
                        return letra;
                }
             }else if (turno==2){
                for(int i=0;i<cant;i++){
                    if (v2[i].front() ==letra)
                        return letra;
                }
             }
            cout << "Error. Esa persona est  del otro lado, ingres  otra: ";
        }else{
            cout << "Error. Intent  de nuevo: ";
        }
    cin >> letra;
    }
}

int buscarMinutos(char persona, const char iniciales[], const int minutos[], const int cant){
        for (int i = 0; i < cant; ++i) {
            if (iniciales[i] == persona) {
                return minutos[i];
            }
        }
        cout << "Error. Letra no v lida. Intent  de nuevo." << endl;
        return 0;
}

//TODO
//esta func est  hardcodeada con el vector del problema, hay que refactorizar para que sea escalable
//como hice con las funciones anteriores
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


