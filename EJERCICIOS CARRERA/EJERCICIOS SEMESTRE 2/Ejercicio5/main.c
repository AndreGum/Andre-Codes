#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    Libro LibrosARegistrar[10];
    int contadorDeLibros=0, Contcont=0,opc=0;
    do
    {
     
    opc=menu();
    switch (opc)
    {
    case 1:
         RegistrarLibros(LibrosARegistrar, &contadorDeLibros);
        opc=0;
        break;
     case 2:
       MostrarInformacion(&contadorDeLibros, LibrosARegistrar);
        opc=0;
        break;
     case 3:
     BuscarPorIDyActualizarEstado(&contadorDeLibros, LibrosARegistrar);
        opc=0;
        break;
     case 4:
     EliminarLibro(&contadorDeLibros, LibrosARegistrar);
        opc=0;
        break;
     case 5:
        
        break;
    }
    } while (opc!=5);
    printf("\nSe cerro el programa");
  


    return 0;
}