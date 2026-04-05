#include <stdio.h>

int main (int argc, char *argv[]) {
    int aux, opcion, cantidadenstock=0, salida=0, controlproducto=0;
    int vender, descuentocontrol=0, nada=0, aumento, descuento, cantidadescuento;
    char ID[11];
    char Nombre[31];
    float preciounitario, Total=0, descuento2, subtotal, dinerodescontado;
    do
    {
        printf("\n-----Gestion de Venta de Productos------\n");
        printf("\n Seleccione una opcion: \n");
        printf("1. Registrar Datos Del Producto \n");
        printf("2. Vender Unidades Del Producto \n");
        printf("3. Rebastecer el Producto \n");
        printf("4. Consultar informacion del producto \n");
        printf("5. Calcular y mostrar las ganancias obtenidas \n");
        printf("6. Agregar descuentos \n");
        printf("7. Salir \n");
        printf("Stock Actual= %d\n", cantidadenstock);
        printf("--->");
        fflush(stdin);
        aux= scanf("%d",&opcion);
        if (aux!=1 || opcion<0 || opcion>7)
        {
            printf("\n!ERROR AL INGRESAR LOS DATOS, VUELVA A INTENTARLO\n");
        }else{
             switch (opcion){
                case 1:
                if (controlproducto==0)
                {
                     printf("\nIngresa el ID de tu producto--->"); 
                     fflush(stdin); fgets(ID,11,stdin);
                     printf("\nIngresa el nombre del producto-->");
                     fflush(stdin); fgets(Nombre,31,stdin);
                     printf("\nIngresa la cantidad en stock-->");
                      fflush(stdin); aux= scanf("%d", &cantidadenstock);
                     while (aux!=1 || cantidadenstock<0)
                    {
                           printf("\n!ERROR AL INGRESAR EL STOCK, VUELVA A INTENTARLO\n");
                           printf("\nIngresa la cantidad en stock-->");
                            fflush(stdin); aux= scanf("%d", &cantidadenstock);
                     }
                     printf("\nIngresa el precio unitario-->");
                      fflush(stdin); aux= scanf("%f", &preciounitario);
                     while (aux!=1 || preciounitario<=0)
                    {
                            printf("\n!ERROR AL INGRESAR EL PRECIO, VUELVA A INTENTARLO\n");
                            printf("\nIngresa la cantidad en stock-->");
                             fflush(stdin); aux= scanf("%f", &preciounitario);
                    }
                    printf("\nLa proxima vez que use esta opcion solo le permitira cambiar el ID, el nombre o el precio unitario en caso de haber error");
                    controlproducto=1;
                    nada=1;
                }else{
                    printf("\nIngresa el ID de tu producto--->"); 
                     fflush(stdin); fgets(ID,11,stdin);
                     printf("\nIngresa el nombre del producto-->");
                     fflush(stdin); fgets(Nombre,31,stdin);
                    printf("\nIngresa el precio unitario-->");
                      fflush(stdin); aux= scanf("%f", &preciounitario);
                     while (aux!=1 || preciounitario<=0)
                    {
                            printf("\n!ERROR AL INGRESAR EL PRECIO, VUELVA A INTENTARLO\n");
                            printf("\nIngresa el precio unitario-->");
                             fflush(stdin); aux= scanf("%f", &preciounitario);
                    }
                    printf("\nLOS DATOS DEL PRODUCTO HAN CAMBIADO, MAS INFORMACION EN LA OPCION 4\n");
                }
                break;
                case 2:
                if (cantidadenstock==0)
                {
                    printf("\nTODAVIA NO SE HA INGRESADO UN PRODUCTO O FALTA REABASTECER\n");
                }else{
                    printf("\nIngresa cuantas unidades quisiera vender-->");
                     fflush(stdin); aux= scanf("%d", &vender);
                     while (aux!=1 || vender<0 || vender>cantidadenstock)
                    {
                            printf("\n!ERROR AL INGRESAR CUANTOS PRODUCTOS DESEAS VENDER, VUELVA A INTENTARLO(El numero no tiene que sobrepasar el stock)\n");
                            printf("\nIngresa cuantas unidades quisiera vender-->");
                            fflush(stdin); aux= scanf("%d", &vender);
                    }
                    if (descuentocontrol==0)
                    {
                         Total=Total+(vender*preciounitario);
                         printf("\nEl producto se ha vendido con exito\n");
                    }else{
                        if (vender>=cantidadescuento)
                        {
                            subtotal=vender*preciounitario;
                            dinerodescontado=subtotal*descuento2;
                            Total=Total+(subtotal-dinerodescontado);
                            printf("\nEl descuento del %d porciento por vender %d unidades se ha aplicado con exito y se ha vendido con exito\n", descuento, cantidadescuento);
                        }else{
                            Total=Total+(vender*preciounitario);
                            printf("\nEl producto se ha vendido con exito\n");
                        }
                        
                        
                    }
                    cantidadenstock=cantidadenstock-vender;
                }
                break;
                case 3:
                if (nada==0)
                {
                    printf("\nNO PUEDES USAR LA OPCION DE REABASTECER PORQUE TODAVIA NO INGRESAS UN PRODUCTO\n");
                }else{
                    printf("\nIngresa la cantidad de unidades que quieres agregarle al stock-->");
                      fflush(stdin); aux= scanf("%d", &aumento);
                      while (aux!=1 || aumento<0)
                    {
                           printf("\n!ERROR AL INGRESAR EL AUMENTO, VUELVA A INTENTARLO\n");
                           printf("\nIngresa la cantidad de unidades que quieres agregarle al stock-->");
                            fflush(stdin); aux= scanf("%d", &aumento);
                    }
                    cantidadenstock=cantidadenstock+aumento;
                }
                break;

                case 4:
                if (nada==0)
                {
                    printf("\nNO PUEDES REVISAR LA INFORMACION PORQUE TODAVIA NO INGRESAS UN PRODUCTO\n");
                }else{
                    printf("\nEl ID de tu producto es -----> %s\n", ID);
                    printf("El Nombre del producto es -----> %s\n", Nombre);
                    printf("El stock de tu producto es -----> %d\n", cantidadenstock);
                    printf("\nEl precio unitario de tu producto es -----> %.2f\n", preciounitario);
                }
                break;
                case 5:
                if (nada==0)
                {
                    printf("\nNO PUEDES REVISAR LAS GANANCIAS PORQUE TODAVIA NO INGRESAS UN PRODUCTO\n");
                }else{
                    printf("\nEl total de Ganancias hasta el momentos es de ---> %.2f$\n", Total);
                }
                break;
                case 6:
                if (nada==0)
                {
                    printf("\nNO PUEDES AGREGAR DESCUENTOS PORQUE TODAVIA NO INGRESAS UN PRODUCTO\n");
                }else{ 
                    printf("\nAgrega la cantidad que quieras agregar de descuento---> ");
                    fflush(stdin); aux= scanf("%d", &descuento);
                     while (aux!=1 || descuento<0 || descuento>100)
                    {
                           printf("\n!ERROR AL INGRESAR EL DECUENTO, VUELVA A INTENTARLO\n");
                           printf("\nAgrega la cantidad que quieras añadir de descuento---> ");
                            fflush(stdin); aux= scanf("%d", &descuento);
                    }
                    descuento2=descuento/100.0;

                    printf("\nAgrega en que caso quieres que se aplique el descuento (ejemplo se aplicara al vender 30 productos)");
                    fflush(stdin); aux= scanf("%d", &cantidadescuento);
                     while (aux!=1 || cantidadescuento<0)
                    {
                           printf("\n!ERROR AL INGRESAR LA CANTIDAD DE UNIDADES POR DESCUENTO, VUELVA A INTENTARLO\n");
                           printf("\nAgrega la cantidad que quieras añadir de unidades por descuento---> ");
                            fflush(stdin); aux= scanf("%d", &cantidadescuento);
                    }
                    descuentocontrol=1;
                }
                break;
                case 7:
                salida=1;
                break;
                default:
             }
            }
    } while (salida==0);
    printf("El programa se ha cerrado con exito :)");
    return 0;
}