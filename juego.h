#pragma once

void jugar();
void mostrarPersonajes();
char ingresarYValidarLetra(int turno,std::string v1[], std::string v2[]);
//int ingresarYValidarMinutos();
int buscarMinutos(char persona);
int hacerCruce(int tiempo, std::string v1[], std::string v2[], int &turno,bool &banderaCruce);
void actualizarVectores(std::string v1[], std::string v2[], char letra);
bool chequearCruceCompleto(std::string v1[]);
