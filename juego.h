#pragma once

void jugar();
void mostrarPersonajes();
char validarLetra(int turno,std::string v1[], std::string v2[], int cant, char letra);
int ingresarYValidarMinutos();
int buscarMinutos(char persona,const char iniciales[],const int minutos[],const int cant);
int hacerCruce(int tiempo, std::string v1[], std::string v2[], int &turno,bool &banderaCruce, const char iniciales[], const int minutos[], int cant);
void actualizarVectores(std::string v1[], std::string v2[], char letra);
bool chequearCruceCompleto(std::string v1[]);
