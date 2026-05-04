#include <stdio.h>
#include "funciones4.h"
int main (int argc, char *argv[]) {
    char nombres[10][20];
    float precio[10];
    int stock[10];
    int opc=0, opc2, cont=0, cont2=0;
    do
    {
        opc=menu();
        switch (opc)
        {
        case 1:
        do
        {
            if (cont<10)
        {
            
            cont=registrarproducto(nombres,precio,stock,cont);
            printf("Deseas registrar otro producto? 1.Si 2.No\n");
            printf("---->");
            opc2=ComparacionCon2Rangos(1,2);

        }else{
            printf("Ya se ingresaron todos los productos posibles, escoje otra opcion\n");
        }
        } while (opc2!=2);
        opc2=0;
        
        
        
            opc=0;
            break;
        case 2:
            if (cont<=0)
            {
                printf("\nTodavia no se ingresa ningun producto, vuelve a seleccionar una opcion\n");
            }else{
                verinventario(nombres,precio,stock,cont);
            }
            
            opc=0;
            break;
        case 3:
            if (cont<=0)
            {
                printf("\nTodavia no se ingresa ningun producto, vuelve a seleccionar una opcion\n");
            }else{
                MAXIMOSyMinimos(nombres,precio,cont);
            }
            
            opc=0;
            break;
        case 4:
              if (cont<=0)
            {
                printf("\nTodavia no se ingresa ningun producto, vuelve a seleccionar una opcion\n");
            }else{
               do
               {
                Buscarnombre(nombres,precio,stock,cont);
                printf("Deseas buscar otro producto? 1.Si 2.No\n");
                printf("---->");
            opc2=ComparacionCon2Rangos(1,2);
            } while (opc2!=2);
            }
            opc2=0;
            opc=0;
            break;
        case 5:
            
            opc=5;
            break;
            
        default:
            break;
        }

    } while (opc!=5);
    printf("\n EL PROGRAMA SE HA CERRADO");
    return 0;
}