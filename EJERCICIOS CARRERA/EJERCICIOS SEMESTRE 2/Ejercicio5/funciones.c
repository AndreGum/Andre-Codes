#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
int menu(){
    int opc;
    printf("\n-----------GESTOR DE LIBROS--------------\n");
    printf("1. Registrar nuevo ID de Libro\n");
    printf("2. Ver Lista Completa de Libros Ingresados hasta el momento\n");
    printf("3. Buscar informacion de un Libro por Titulo o ID\n");
    printf("4. Actualizar el estado de un Libro\n");
    printf("5. Eliminar Libro\n");
    printf("6. Salirssdsdsds\n");
    printf("--->");
    opc=ValidadordeEnteros(1,6);
    return opc;
}

int ValidadordeEnteros(int a, int b){
    int aux, D;
    aux=scanf("%d", &D);
    LimpiarBuffer();
    while (aux!=1||a>D||D>b)
    {
        printf("\n ERROR DE TIPO DE DATO, VUELVA A INGRESARLO\n");
        printf("--->");
        aux=scanf("%d", &D);
        LimpiarBuffer();
    }
    return D;
}

float ValidadordeReales(float a, float b){
    int aux; float D;
    aux=scanf("%f", &D);
    LimpiarBuffer();
    while (aux!=1||a>D||D>b)
    {
        printf("\n ERROR DE TIPO DE DATO, VUELVA A INGRESARLO\n");
        printf("--->");
        aux=scanf("%f", &D);
        LimpiarBuffer();
    }
    return D;
}

void LimpiarBuffer(){
    int c;
    while ((c=getchar())!= '\n' && c!= EOF);
}

int RegistrarLibros(Libro *LibrosNuevos, int *n, int *baseDedatos){
    
   ControladorDeID(LibrosNuevos, n, baseDedatos);
   printf("Ingresa el Titulo del del Libro (maximo 100 caracteres) %d: \n", *n+1);


}

void registrarnombreControl(Libro *LibrosNuevos, int *n){
    int controladorDebusqueda;
    
    do
    {
        controladorDebusqueda=0;
        fgets(LibrosNuevos[*n].Titulo,100,stdin);
        LibrosNuevos[*n].Titulo[strcspn(LibrosNuevos[*n].Titulo, "\n")]='\0';
    } while (controladorDebusqueda!=0);
    
    
}

void ControladorDeID(Libro *LibrosNuevos, int *n,int *baseDedatos){
    int controladorDebusqueda;
    printf("Ingresa el ID de 5 digitos del Libro %d: \n", *n+1);
    printf("ID DISCLAIMER: El ID es unico, por lo que no se podra agregar otro igual a no ser que se elimine la informacion del libro\n");
    do
    {
        controladorDebusqueda=0;
        LibrosNuevos[*n].ID=ValidadordeEnteros(10000,99999);
    for (int i = 0; i < *n; i++)
    {
        if (baseDedatos[i]==LibrosNuevos[*n].ID)
        {
           controladorDebusqueda=1;
           printf("\n ERROR ID YA IGRESADO, VUEVLE A INGRESARLO\n");
           break;
        }
    }
    } while (controladorDebusqueda!=0);
      printf("Se ha ingresado el ID con exito\n");
      baseDedatos[*n] = LibrosNuevos[*n].ID;
}