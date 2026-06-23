#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct 
{
   char Disponible[10];

}Disponibilidad;

typedef struct 
{
    int ID;
    char Titulo[100];
    char Autor[50];
    int Fechadepublicacion;
    Disponibilidad Uso;

}Libro;

int menu();
int ValidadordeEnteros(int a, int b);
float ValidadordeReales(float a, float b);
void LimpiarBuffer();
int RegistrarLibros(Libro *LibrosNuevos, int *n);
void MostrarInformacion (int *n, Libro *LibroIngresado);
void registrarnombre(char *cadena, int n);
void ControladorDeID(Libro *LibrosNuevos, int *n);
void BuscarPorIDyActualizarEstado(int *n, Libro *LibrosNuevos);
void EliminarLibro(int *n, Libro *LibrosNuevos);