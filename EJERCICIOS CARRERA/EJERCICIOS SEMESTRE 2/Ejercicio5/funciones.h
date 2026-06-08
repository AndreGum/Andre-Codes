#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct 
{
   char Disponible[10];
   char Prestado[10];
}Disponibilidad;

typedef struct 
{
    int ID;
    char Titulo[100];
    char Autor[50];
    int Fechadepublicacion;
    char DisponibleOrPrestado[10];
    Disponibilidad Uso;
    
}Libro;

int menu();
int ValidadordeEnteros(int a, int b);
float ValidadordeReales(float a, float b);
void LimpiarBuffer();