#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
int menu(){
    int opc;
    printf("\n-----------GESTOR DE LIBROS--------------\n");
     //El estado lo volvi automaticamente disponible porque no puedes registrar un libro que ya tengas prestado 
    printf("1. Registrar nuevo ID de Libro\n");
    printf("2. Ver Lista Completa de Libros Ingresados hasta el momento\n");
    printf("3. Buscar informacion de un Libro por ID\n");
    //la funcionalidad actualizar estado la puse en buscar informacion para no reutilizar la funcion Buscar por ID y hacerlo todo directo, para cambiar el estado solo lo muevo automaticamente a prestado para que el usuario no ponga otras cosas
    printf("4. Eliminar Libro\n");
    printf("5. Salir\n");
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

int RegistrarLibros(Libro *LibrosNuevos, int *n){
   if (*n!=10)
    {
   ControladorDeID(LibrosNuevos, n);
   printf("Ingresa el Titulo del Libro (maximo 100 caracteres) %d: \n", *n+1);
   registrarnombre(LibrosNuevos[*n].Titulo,100);
   printf("Ingresa el nombre del autor (maximo 50 caracteres) del Libro  %d: \n", *n+1);
   registrarnombre(LibrosNuevos[*n].Autor,50);
   printf("Ingresa la fecha de publicacion del Libro  %d: \n", *n+1);
   LibrosNuevos[*n].Fechadepublicacion=ValidadordeEnteros(1,2026);
   printf("AVISO: El Estado serA automaticamente DISPOIBLE porque un libro se registra cuando aun no esta disponible no cuando ya esta prestado\n");
   strcpy(LibrosNuevos[*n].Uso.Disponible, "Disponible");
   printf("SE HA REGISTRADO EL LIBRO CON EXITO\n");
    return (*n)++;

    }else{
        printf("\nYA SE HAN INGRESADO TODOS LOS LIBROS POSIBLES, ESCOJE OTRA OPCION\n");
        return 0;
    }
   
}


void MostrarInformacion (int *n, Libro *LibroIngresado){
    if (*n==0)
    {
        printf("\n Todavia no se ha ingresado ningun libro \n");
    
    }else{
        printf("\nLa informacion de los libros ingresadas hasta ahora es:\n");
        printf("#\t\t\tID\t\t\tTitulo\t\t\tAutor\t\t\tFechaDePublicacion\t\t\tEstado\n");
        for (int i = 0; i < *n; i++)
        {
        printf("%d\t\t\t\t%d\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t%s\n",i+1,LibroIngresado[i].ID,LibroIngresado[i].Titulo,LibroIngresado[i].Autor,LibroIngresado[i].Fechadepublicacion,LibroIngresado[i].Uso.Disponible);
        }
    }
}



void registrarnombre(char *cadena, int n){
 fgets(cadena,n,stdin);
 cadena[strcspn(cadena, "\n")]='\0';
}

void ControladorDeID(Libro *LibrosNuevos, int *n){
    int controladorDebusqueda;
   
    printf("Ingresa el ID de 5 digitos del Libro %d: \n", *n+1);
    printf("ID DISCLAIMER: El ID es unico, por lo que no se podra agregar otro igual a no ser que se elimine la informacion del libro\n");
    do
    {
        controladorDebusqueda=0;
        LibrosNuevos[*n].ID=ValidadordeEnteros(10000,99999);
    for (int i = 0; i < *n; i++)
    {
        if (LibrosNuevos[i].ID==LibrosNuevos[*n].ID)
        {
           controladorDebusqueda=1;
           printf("\n ERROR ID YA IGRESADO, VUEVLE A INGRESARLO\n");
           break;
        }
    }
    } while (controladorDebusqueda!=0);
      printf("Se ha ingresado el ID con exito\n");
    
      
}

void BuscarPorIDyActualizarEstado(int *n, Libro *LibrosNuevos) {
    int BuscarID,EditaEstado;

    if (*n == 0) {
        printf("\n Todavia no se ha ingresado ningun libro \n");
        return;
    }
    printf("\nIngresa el ID (5 digitos) del libro que deseas buscar:\n ");
    printf("--->");
     BuscarID = ValidadordeEnteros(10000, 99999);
    for (int i = 0; i < *n; i++) {
        
        if (LibrosNuevos[i].ID == BuscarID) {
            printf("El Libro se ha encontrado la informacion del libro %d es: \n", i+1);
            printf("El ID del libro %d es: %d\n", i+1, LibrosNuevos[i].ID);
            printf("El Titulo del libro %d es: %s\n",i+1, LibrosNuevos[i].Titulo);
            printf("El Autor del libro %d es: %s\n",i+1, LibrosNuevos[i].Autor);
            printf("La Fecha de publicacion del libro %d es: %d\n",i+1, LibrosNuevos[i].Fechadepublicacion);
            printf("El Estado del libro %d es: %s\n",i+1, LibrosNuevos[i].Uso.Disponible);
            printf("Si desea actualizar el estado del libro seleccione 1, si desea continuar seleccione 2\n");
            printf("--->");
            EditaEstado=ValidadordeEnteros(1,2);
            if (EditaEstado==1)
            {
        if (strcmp(LibrosNuevos[i].Uso.Disponible, "Disponible") == 0) {
            
           
            strcpy(LibrosNuevos[i].Uso.Disponible, "Prestado");
            
        } else {
            

            strcpy(LibrosNuevos[i].Uso.Disponible, "Disponible");
        }
        printf("\n El estado del libro %s ahora es: %s\n", LibrosNuevos[i].Titulo, LibrosNuevos[i].Uso.Disponible);

            }
            

           return;
        }
    }
        printf("\n  No se encontro ningun libro registrado con el ID: %d\n", BuscarID);
    
}

void EliminarLibro(int *n, Libro *LibrosNuevos) {
    int Eliminar;

    if (*n == 0) {
        printf("\n  Todavia no se ha ingresado ningun libro.\n");
        return;
    }

    printf("\nIngresa el ID (5 digitos) del libro que deseas ELIMINAR:\n---> ");
    Eliminar = ValidadordeEnteros(10000, 99999);

    for (int i = 0; i < *n; i++) {
        
        if (LibrosNuevos[i].ID == Eliminar) {
            

            for (int j = i; j < *n - 1; j++) {
                LibrosNuevos[j] = LibrosNuevos[j + 1]; 
            }
            
            (*n)--;
        
            printf("El libro seleccionado se ha eliminado.\n");
            return; 
        }
    }

  
    printf("\n No se encontro ningun libro con el ID: %d\n", Eliminar);
}