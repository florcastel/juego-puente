#include <iostream>
#include "rlutil.h"

using namespace std;

void trazarLineaCyan() {
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "--------------------------------------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void dibujarBanner(){
    cout << R"(
  ___ _        _   ___ ___ ___ _____ ___   _  ___
 | __| |      /_\ / __| __| _ \_   _|_ _| | |/ _ \
 | _|| |__   / _ \ (__| _||   / | |  | | || | (_) |
 |___|____| /_/ \_\___|___|_|_\ |_| |___\__/ \___/

    ___  ___ _      ___ _   _ ___ _  _ _____ ___
   |   \| __| |    | _ \ | | | __| \| |_   _| __|
   | |) | _|| |__  |  _/ |_| | _|| .` | | | | _|
   |___/|___|____| |_|  \___/|___|_|\_| |_| |___|

        )" << endl;

}

void dibujarBanner2(){
    cout << R"(
    _                 _   _  _             _      _   ____                   _
   / \   ___ ___ _ __| |_(_)(_) ___     __| | ___| | |  _ \ _   _  ___ _ __ | |_ ___
  / _ \ / __/ _ \ '__| __| || |/ _ \   / _` |/ _ \ | | |_) | | | |/ _ \ '_ \| __/ _ \
 / ___ \ (_|  __/ |  | |_| || | (_) | | (_| |  __/ | |  __/| |_| |  __/ | | | ||  __/
/_/   \_\___\___|_|   \__|_|/ |\___/   \__,_|\___|_| |_|    \__,_|\___|_| |_|\__\___|
                          |__/

        )" << endl;

}
void dibujarBannerExito(){
    cout << "\nFELICITACIONES!!\n";
    cout << R"(
       ____                 _       _     _
      |  _ \ ___  ___  ___ | |_   _(_)___| |_ ___
      | |_) / _ \/ __|/ _ \| \ \ / / / __| __/ _ \
      |  _ <  __/\__ \ (_) | |\ V /| \__ \ ||  __/
      |_| \_\___||___/\___/|_| \_/ |_|___/\__\___|
      _                   _     _                        _
  ___| |  _ __  _ __ ___ | |__ | | ___ _ __ ___   __ _  | |
 / _ \ | | '_ \| '__/ _ \| '_ \| |/ _ \ '_ ` _ \ / _` | | |
|  __/ | | |_) | | | (_) | |_) | |  __/ | | | | | (_| | |_|
 \___|_| | .__/|_|  \___/|_.__/|_|\___|_| |_| |_|\__,_| (_)
         |_|

        )" << endl;

}



void mostrarHistoria(){
    rlutil::cls();
    cout << R"(
                            El Problema del Puente

Imagin  que est s pasando un finde en un bosque con tus amigos. Para llegar a la
caba¤a donde van a dormir, tienen que cruzar un puente colgante. El puente soporta
hasta 2 personas, y despu‚s de pasar esas 2, siempre debe volver 1 al inicio para
llevarle la £nica linterna que tienen al siguiente que cruce, porque est  oscuro y
pueden pisar alguna tabla suelta.
Para complicar m s las cosas, solo tienen 15 minutos como m ximo para que todos
crucen antes de que se los coma un oso que los viene siguiendo AAaaAAaaaAahh!!

DATO IMPORTANTE: cada amigo tarda diferente tiempo en cruzar, vos tard s 1 minuto,
Cami 2, Tom s 5 y Bauti 8.

Suerteeee


                  |                                                     |
                 /                                                       \
                /                      o      o                           \
  o  \ o /     /                      /|\    /|\                           \
 /|\   |      /_____________________________________________________________\
 / \  / \     | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
              ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^




)" << endl;

}

void mostrarPersonajes(){
rlutil::setColor(rlutil::LIGHTCYAN);
    cout << R"(
 -------------------------
| Personajes y tiempos:   |
 -------------------------
| Yo = 1 minuto,          |
| Cami = 2 minutos,       |
| Tom s = 5 minutos,      |
| Bauti = 8 minutos.      |
 -------------------------
)";
rlutil::setColor(rlutil::WHITE);
}


void mostrarCreditos(){
    rlutil::cls();
    cout << "Cr‚ditos:"<< endl;
    cout << R"(
                 ######    ######    ######
                 ######    ######    ######
                 #######   ######   ######
                  #######  ######  ######
                   #####################
                     #################
                        ###########
                 ##########################
                 ##########################
                 ##########################
                      ################
                    ####################
                  #######################
                 #######   ######   ######
                 ######    ######    ######
                 ######    ######    ######


           UTN - UNIVERSIDAD TECNOLOGICA NACIONAL
              FACULTAD REGIONAL GENERAL PACHECO
         Tecnicatura Universitaria en Programaci¢n
                  Alumna: F.C. | A¤o: 2025

        )" << endl;

}

void mostrarTextoResaltado(string mensaje){
    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    cout << mensaje << endl;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
}



/*


                ##     ## ######## ###   ##
                ##     ##    ##    ####  ##
                ##     ##    ##    ## ## ##
                ##     ##    ##    ##  ####
                 #######     ##    ##   ###


*/
