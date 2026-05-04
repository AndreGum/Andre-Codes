#include <stdio.h>
#include<string.h>
#include "funciones4.h"
int menu(){
    int opc=0;
    printf("\n--------REGISTRADORA DE PRODUCTOS-------\n");
    printf("1. Registrar Producto \n");
    printf("2. Ver inventario \n");
    printf("3. Encontrar el producto mas caro y mas barato\n");
    printf("4. Buscar producto por nombre\n");
    printf("5. Salir\n");
    printf("--->");
    opc=ComparacionCon2Rangos(1,5);
    return opc;

}

int ComparacionCon2Rangos(int a, int b){
    int opc, aux;
    aux=scanf("%d", &opc);
    limpiarbuffer();
    do
    {
         while (aux!=1 || opc<a || opc>b)
    {
        printf("ERROR, LA OPCION ES INCORRECTA, VUEVLA A INGRESARLA\n");
        printf("---->");
        aux=scanf("%d", &opc);
        limpiarbuffer();
    }
    } while (aux!=1 || opc<a || opc>b);
    return opc;
}

void limpiarbuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limpiarSaltodelinea(char cadena[]){
    
    cadena[strcspn(cadena, "\n")] = '\0';

}

int registrarproducto(char nombres[10][20], float precio[10], int stock[10], int cont){
   printf("\nIngresa el nombre del producto %d:\n", cont+1);
   registrarnombre(nombres[cont], 20);
   printf("\nIngresa el precio del producto %d:\n", cont+1);
   precio[cont]=ComparacionCon2Rangosfloat(0.1, 99999);
   printf("\nIngresa el stock del producto %d:\n", cont+1);
   stock[cont]=ComparacionCon2Rangos(1, 99999);
   return cont+1;


}

void verinventario(char nombres[10][20], float precio[10], int stock[10], int cont){
float preciototal=0;
float totalinventario=0;
float promedioprecio=0;
    printf("\n#\t\tNombre\t\tPrecio\t\tStock\t\tTotal\n");
for (int i = 0; i < cont; i++)
{
    preciototal=precio[i]*stock[i];
    totalinventario+=preciototal;
    promedioprecio+=precio[i];
    printf("%d\t\t%s\t\t%.2f\t\t%d\t\t%.2f\n", i+1,nombres[i],precio[i],stock[i], preciototal);
    preciototal=0;
}
printf("El precio total de todo el inventario es de: %.2f\n", totalinventario);
totalinventario=0; 
promedioprecio/=cont;
printf("El promedio total de todo el inventario es de: %.2f\n", promedioprecio);


}

void registrarnombre(char cadena[], int n){
    fgets(cadena,n,stdin);
    limpiarSaltodelinea(cadena);
}


float ComparacionCon2Rangosfloat(float a, float b){
    int aux;
    float opc;
    aux=scanf("%f", &opc);
    limpiarbuffer();
    do
    {
         while (aux!=1 || opc<a || opc>b)
    {
        printf("ERROR, El VALOR INGRESADO ES INCORRECTO, VUEVLA A INGRESARLA\n");
        printf("---->");
        aux=scanf("%f", &opc);
        limpiarbuffer();
    }
    } while (aux!=1 || opc<a || opc>b);
    return opc;
}
void MAXIMOSyMinimos(char nombres[10][20], float precio[10],int cont){
   float MAX=precio[0];
   float MIN=precio[0];
   float comparador;
   int indice1=0, indice2=0;
    for (int i = 0; i < cont; i++)
    {           
    comparador = precio[i];
                                if (comparador > MAX)
                                {
                                    MAX = comparador;
                                    indice1=i;

                                }
                                if (comparador < MIN)
                                {
                                    MIN = comparador;
                                    indice2=i;
                                }
                            
                                
                            
     
    }
    printf("El producto %d: %s es el mas caro de todo el inventario con un precio de %.2f\n", indice1+1, nombres[indice1], MAX);
     printf("El producto %d: %s es el mas barato de todo el inventario con un precio de %.2f\n", indice2+1, nombres[indice2], MIN);
}
void Buscarnombre(char nombres[10][20],float precio[10], int stock[10], int cont){
    char buscarnombre[20];
    int loencontraste=0;
    printf("Ingrese el nombre del producto que desea buscar\n");
    registrarnombre(buscarnombre,20);
    
    for (int i = 0; i < cont; i++) {
        
        if (strcmp(buscarnombre, nombres[i]) == 0) {
            
            printf("El Producto se ha encontrado, el producto es:\n");
            printf("#%d\t\tNombre:%s\t\tPrecio:%.2f\t\tStock:%d\n", i+1, nombres[i],precio[i],stock[i]);
            loencontraste= 1; 
            
        }
    }
    if (loencontraste==0)
    {
        printf("El Producto no se encuentra en la base de datos del inventario \n");
    }
    
}