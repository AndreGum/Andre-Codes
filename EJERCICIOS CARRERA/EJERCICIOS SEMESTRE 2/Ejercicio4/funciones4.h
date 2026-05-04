#include<stdio.h>
#include<string.h>
int menu();
int ComparacionCon2Rangos(int a, int b);
void limpiarbuffer();
void limpiarSaltodelinea(char cadena[]);
float ComparacionCon2Rangosfloat(float a, float b);
void registrarnombre(char cadena[], int n);
void verinventario(char nombres[10][20], float precio[10], int stock[10], int cont);
int registrarproducto(char nombres[10][20], float precio[10], int stock[10], int cont);
void MAXIMOSyMinimos(char nombres[10][20], float precio[10],int cont);
void Buscarnombre(char nombres[10][20],float precio[10], int stock[10], int cont);