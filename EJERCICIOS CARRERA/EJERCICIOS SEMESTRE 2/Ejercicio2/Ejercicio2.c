#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    const int NUMERO_ESTUDIANTESCOLEGIO = 5;
    float califi[NUMERO_ESTUDIANTESCOLEGIO][3][3] = {0};
    char nombres[NUMERO_ESTUDIANTESCOLEGIO][20];
    char asignatura[3][20] = {"Matematica", "Fisica", "Quimica"};
    int opcion = 0, opcion2, aux, contadorAlumnos = 0, estudiantesregristr = 0, alumnoseleccionado;
    int nombrecorrecto = 0, opcion3, opcion4, controlpromedios[NUMERO_ESTUDIANTESCOLEGIO] = {0};
    int contadormateria[3] = {0};
    float promedio1[NUMERO_ESTUDIANTESCOLEGIO][3] = {0};
    float promedio2[NUMERO_ESTUDIANTESCOLEGIO] = {0};
    float promedio3[NUMERO_ESTUDIANTESCOLEGIO][3] = {0};
    float comparador, max = 0, min = 0;

    do
    {
        printf("\n-----Gestion de Notas de Estudiantes------\n");
        printf("\n Seleccione una opcion: \n");
        printf("1. Registrar Alumnos \n");
        printf("2. Registrar Las calificaciones \n");
        printf("3. Promedio por alumno\n");
        printf("4. Promedio por asignatura \n");
        printf("5. Calificacion mas alta y baja por estudiante \n");
        printf("6. Calificacion mas alta y baja por asignatura \n");
        printf("7. Estudiantes aprobados y reprobados por asignatura\n");
        printf("8. Salir \n");
        printf("Numero de Estudiantes totales que se pueden registrar: %d \n", NUMERO_ESTUDIANTESCOLEGIO);
        printf("Numero de Estudiantes registrados: %d \n", contadorAlumnos);
        printf("---->");
        fflush(stdin);
        aux = scanf("%d", &opcion);
        if (aux != 1 || opcion <= 0 || opcion > 8)
        {
            printf("\n!ERROR AL SELECCIONAR LAS OPCIONES, VUELVA A INTENTARLO\n");
        }
        else
        {
            if (contadorAlumnos > NUMERO_ESTUDIANTESCOLEGIO)
            {
                printf("\nEL NUMERO MAXIMO DE ESTUDIANTES YA SE HA REGISTRAO, SELECCIONA OTRA OPCION\n");
            }
            else
            {

                switch (opcion)
                {
                case 1:
                    do
                    {

                        printf("Ingrese el nombre del alumno %d\n", contadorAlumnos + 1);
                        fflush(stdin);
                        fgets(nombres[contadorAlumnos], 20, stdin);
                        nombres[contadorAlumnos][strcspn(nombres[contadorAlumnos], "\n")] = '\0';
                        printf("Esta correcto el nombre: %s \n", nombres[contadorAlumnos]);
                        printf("0.Reescribir nombre 1.Esta correcto\n");
                        printf("---->");
                        fflush(stdin);
                        aux = scanf("%d", &nombrecorrecto);
                        while (aux != 1 || nombrecorrecto < 0 || nombrecorrecto > 1)
                        {
                            printf("!OPCION NO VALIDA, VUELVA A INTENTAR\n");
                            printf("---->");
                            fflush(stdin);
                            aux = scanf("%d", &nombrecorrecto);
                        }
                        while (nombrecorrecto == 0)
                        {

                            printf("Ingrese el nombre del alumno %d\n", contadorAlumnos + 1);
                            fflush(stdin);
                            fgets(nombres[contadorAlumnos], 20, stdin);
                            nombres[contadorAlumnos][strcspn(nombres[contadorAlumnos], "\n")] = '\0';
                            printf("Esta correcto el nombre: %s \n", nombres[contadorAlumnos]);
                            printf("0.Reescribir nombre 1.Esta correcto\n");
                            printf("---->");
                            fflush(stdin);
                            aux = scanf("%d", &nombrecorrecto);
                            while (aux != 1 || nombrecorrecto < 0 || nombrecorrecto > 1)
                            {
                                printf("!OPCION NO VALIDA, VUELVA A INTENTAR\n");
                                printf("---->");
                                fflush(stdin);
                                aux = scanf("%d", &nombrecorrecto);
                            }
                        }
                        contadorAlumnos++;
                        printf("Desea continuar? 1.Si 2.No\n");
                        fflush(stdin);
                        aux = scanf("%d", &opcion2);
                        while (aux != 1 || opcion2 < 1 || opcion2 > 2)
                        {
                            printf("!ERROR AL SELECCIONAR LAS OPCION, VUELVA A INTENTARLO\n");
                            printf("---->");
                            fflush(stdin);
                            aux = scanf("%d", &opcion2);
                        }

                    } while (opcion2 != 2);
                    opcion2 = 0;
                    break;
                case 2:
                    if (contadorAlumnos == 0)
                    {
                        printf("\nEsta opcion no funciona porque todavia no se ha ingresado ningun alumno\n");
                    }
                    else
                    {
                        do
                        {
                            printf("Escoje el estudiante del que quieras ingresar las notas\n");
                            for (int i = 0; i < contadorAlumnos; i++)
                            {
                                printf("%d. %s \n", i + 1, nombres[i]);
                            }
                            printf("--->");
                            fflush(stdin);
                            aux = scanf("%d", &alumnoseleccionado);
                            while (aux != 1 || alumnoseleccionado <= 0 || alumnoseleccionado > contadorAlumnos)
                            {
                                printf("!ERROR AL SELECCIONAR EL ESTUDIANTE, VUELVA A SELECCIONARLO\n");
                                fflush(stdin);
                                aux = scanf("%d", &alumnoseleccionado);
                            }
                            contadormateria[0] = 0;
                            contadormateria[1] = 0;
                            contadormateria[2] = 0;
                            do
                            {
                                printf("\nEscoje la materia en la que quieres guardar las notas de %s \n", nombres[alumnoseleccionado - 1]);
                                printf("1. %s\n", asignatura[0]);
                                printf("2. %s\n", asignatura[1]);
                                printf("3. %s\n", asignatura[2]);
                                printf("--->");
                                fflush(stdin);
                                aux = scanf("%d", &opcion4);
                                while (aux != 1 || opcion4 <= 0 || opcion4 > 3)
                                {
                                    printf("!ERROR AL SELECCIONAR LA ASIGNATURA, VUELVA A SELECCIONARLO\n");
                                    printf("---->");
                                    fflush(stdin);
                                    aux = scanf("%d", &opcion4);
                                }

                                switch (opcion4)
                                {
                                case 1:
                                    if (contadormateria[0] == 1)
                                    {
                                        printf("\nLAS 3 NOTAS YA HAN SIDO REGISTRADAS DE ESTE ESTUDIANTE EN MATEMATICAS");
                                    }
                                    else
                                    {
                                        for (int i = 0; i < 3; i++)
                                        {
                                            printf("Ingresa la nota %d\n", i + 1);
                                            printf("--->");
                                            fflush(stdin);
                                            aux = scanf("%f", &califi[alumnoseleccionado - 1][0][i]);
                                            while (aux != 1 || califi[alumnoseleccionado - 1][0][i] < 0 || califi[alumnoseleccionado - 1][0][i] > 10)
                                            {
                                                printf("ERROR AL INGRESAR LA NOTA TIENE QUE SER MAYOR A 0 Y MENOR A 10 VUELVE A INTENTAR\n");
                                                printf("---->");
                                                fflush(stdin);
                                                aux = scanf("%f", &califi[alumnoseleccionado - 1][0][i]);
                                            }
                                        }
                                        promedio1[alumnoseleccionado - 1][0] = (califi[alumnoseleccionado - 1][0][0] + califi[alumnoseleccionado - 1][0][1] + califi[alumnoseleccionado - 1][0][2]) / 3;
                                        promedio2[alumnoseleccionado - 1] += promedio1[alumnoseleccionado - 1][0];
                                        promedio3[alumnoseleccionado - 1][0] = promedio1[alumnoseleccionado - 1][0];
                                        contadormateria[0] = 1;
                                    }
                                    opcion4 = 0;
                                    break;
                                case 2:
                                    if (contadormateria[1] == 1)
                                    {
                                        printf("\nLAS 3 NOTAS YA HAN SIDO REGISTRADAS DE ESTE ESTUDIANTE EN FISICA ");
                                    }
                                    else
                                    {
                                        for (int i = 0; i < 3; i++)
                                        {
                                            printf("Ingresa la nota %d\n", i + 1);
                                            printf("--->");
                                            fflush(stdin);
                                            aux = scanf("%f", &califi[alumnoseleccionado - 1][1][i]);
                                            while (aux != 1 || califi[alumnoseleccionado - 1][1][i] < 0 || califi[alumnoseleccionado - 1][1][i] > 10)
                                            {
                                                printf("ERROR AL INGRESAR LA NOTA TIENE QUE SER MAYOR A 0 Y MENOR A 10 VUELVE A INTENTAR\n");
                                                printf("---->");
                                                fflush(stdin);
                                                aux = scanf("%f", &califi[alumnoseleccionado - 1][1][i]);
                                            }
                                        }
                                        promedio1[alumnoseleccionado - 1][1] = (califi[alumnoseleccionado - 1][1][0] + califi[alumnoseleccionado - 1][1][1] + califi[alumnoseleccionado - 1][1][2]) / 3;
                                        promedio2[alumnoseleccionado - 1] += promedio1[alumnoseleccionado - 1][1];
                                        promedio3[alumnoseleccionado - 1][1] = promedio1[alumnoseleccionado - 1][1];
                                        ;
                                        contadormateria[1] = 1;
                                    }
                                    opcion4 = 0;
                                    break;
                                case 3:
                                    if (contadormateria[2] == 1)
                                    {
                                        printf("\nLAS 3 NOTAS YA HAN SIDO REGISTRADAS DE ESTE ESTUDIANTE EN QUIMICA ");
                                    }
                                    else
                                    {
                                        for (int i = 0; i < 3; i++)
                                        {
                                            printf("Ingresa la nota %d\n", i + 1);
                                            printf("--->");
                                            fflush(stdin);
                                            aux = scanf("%f", &califi[alumnoseleccionado - 1][2][i]);
                                            while (aux != 1 || califi[alumnoseleccionado - 1][2][i] < 0 || califi[alumnoseleccionado - 1][2][i] > 10)
                                            {
                                                printf("ERROR AL INGRESAR LA NOTA TIENE QUE SER MAYOR A 0 Y MENOR A 10 VUELVE A INTENTAR\n");
                                                printf("---->");
                                                fflush(stdin);
                                                aux = scanf("%f", &califi[alumnoseleccionado - 1][2][i]);
                                            }
                                        }
                                        promedio1[alumnoseleccionado - 1][2] = (califi[alumnoseleccionado - 1][2][0] + califi[alumnoseleccionado - 1][2][1] + califi[alumnoseleccionado - 1][2][2]) / 3;
                                        promedio2[alumnoseleccionado - 1] += promedio1[alumnoseleccionado - 1][2];
                                        promedio3[alumnoseleccionado - 1][2] = promedio1[alumnoseleccionado - 1][2];
                                        contadormateria[2] = 1;
                                    }
                                    opcion4 = 0;
                                    break;
                                }
                                printf("\nDesea continuar con las notas? 1. Si  2.No\n");
                                fflush(stdin);
                                aux = scanf("%d", &opcion2);
                                while (aux != 1 || opcion2 < 1 || opcion2 > 2)
                                {
                                    printf("!ERROR AL SELECCIONAR LAS OPCION, VUELVA A INTENTARLO\n");
                                    printf("---->");
                                    fflush(stdin);
                                    aux = scanf("%d", &opcion2);
                                }
                                if (contadormateria[0] == 1 && contadormateria[1] == 1 && contadormateria[2] == 1)
                                {
                                    promedio2[alumnoseleccionado - 1] = (promedio2[alumnoseleccionado - 1]) / 3;
                                    controlpromedios[alumnoseleccionado - 1] = 1;
                                }

                            } while (opcion2 != 2);
                            printf("Quieres agregar las notas de otro estudiante? 1. Si 2. No\n");
                            printf("---->");
                            fflush(stdin);
                            aux = scanf("%d", &opcion3);
                            while (aux != 1 || opcion3 < 1 || opcion3 > 2)
                            {
                                printf("!ERROR AL SELECCIONAR LAS OPCION, VUELVA A INTENTARLO\n");
                                printf("---->");
                                fflush(stdin);
                                aux = scanf("%d", &opcion3);
                            }

                        } while (opcion3 != 2);
                    }
                    opcion2 = 0;
                    break;
                case 3:
                    if (contadorAlumnos == 0)
                    {
                        printf("\nEsta opcion no funciona porque todavia no se ha ingresado ningun alumno\n");
                    }
                    else
                    {
                        printf("\nEl promedio de las 3 materias de cada estudiante es:\n");
                        for (int i = 0; i < contadorAlumnos; i++)
                        {
                            if (controlpromedios[i] == 1)
                            {
                                printf("%d.EL promedio de %s entre las 3 materias: %f \n", i + 1, nombres[i], promedio2[i]);
                            }
                            else
                            {
                                printf("%d.El estudiante %s no tiene las 3 notas registradas de las 3 materias todavia(NO HAY PROMEDIO)\n", i + 1, nombres[i]);
                            }
                        }
                    }
                    opcion2 = 0;
                    break;
                case 4:
                    if (contadorAlumnos == 0)
                    {
                        printf("\nEsta opcion no funciona porque todavia no se ha ingresado ningun alumno\n");
                    }
                    else
                    {
                        printf("\nEl promedio por cada asignatura de cada estudiante es:\n");
                        for (int i = 0; i < contadorAlumnos; i++)
                        {
                            for (int j = 0; j < 1; j++)
                            {
                                printf("%d.Los promedios de %s entre cada materia son:\n", i + 1, nombres[i]);
                                printf("%s: %f \n", asignatura[0], promedio1[i][j]);
                                printf("%s: %f \n", asignatura[1], promedio1[i][j + 1]);
                                printf("%s: %f \n", asignatura[2], promedio1[i][j + 2]);
                            }
                        }
                    }

                    opcion2 = 0;
                    break;
                case 5:
                    if (contadorAlumnos == 0)
                    {
                        printf("\nEsta opcion no funciona porque todavia no se ha ingresado ningun alumno\n");
                    }
                    else
                    {
                        for (int i = 0; i < contadorAlumnos; i++)
                        {
                            max = promedio3[i][0];
                            min = promedio3[i][0];
                            for (int j = 1; j < 3; j++)
                            {
                                comparador = promedio3[i][j];
                                if (comparador > max)
                                {
                                    max = comparador;
                                }
                                if (comparador < min)
                                {
                                    min = comparador;
                                }
                            
                                
                            }
                            printf("La calificacion maxima alcanzada entre todas las materias de %s es de %.2f, y la minima es de %.2f\n", nombres[i], max, min);
                        }
                        
                    }

                    opcion2 = 0;
                    break;
                case 6:
                if (contadorAlumnos == 0)
                    {
                        printf("\nEsta opcion no funciona porque todavia no se ha ingresado ningun alumno\n");
                    }
                    else
                    {
                        for (int i = 0; i < contadorAlumnos; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                max = califi[i][j][0];
                                min = califi[i][j][0];
                                for (int x = 1; x < 3; x++)
                                {
                                    comparador = califi[i][j][x];
                               if (comparador > max)
                                    {
                                        max = comparador;
                                    }
                                    if (comparador < min)
                                    {
                                        min = comparador;
                                    }
                                }
                                
                               printf("La calificacion maxima alcanzada en %s de %s es de %.2f, y la minima es de %.2f\n", asignatura[j], nombres[i], max, min);
                               comparador=0;
                               min=0;
                               max=0;
                            }
                            max=0;
                            min=0;
                        }
                        
                    }
                opcion2 = 0;
                comparador=0;
                    break;
                case 7:
                 if (contadorAlumnos == 0)
                    {
                        printf("\nEsta opcion no funciona porque todavia no se ha ingresado ningun alumno\n");
                    }
                    else
                    {
                        for (int i = 0; i < contadorAlumnos; i++)
                        {
                            
                            for (int j = 0; j < 3; j++)
                            {
                                comparador = promedio3[i][j];
                                if (comparador>=6)
                                {
                                    printf("%s ha aprobado la materia de %s, con un promedio de: %f\n", nombres[i], asignatura[j], promedio3[i][j]);

                                }else{
                                    printf("El estudiante %s no ha aprobado la materia de %s, con un promedio de: %f\n", nombres[i], asignatura[j], promedio3[i][j]);
                                }
                                
                            
                                
                            }
                            
                        }
                        
                    }

                    opcion2 = 0;
                    break;
                    case 8:
                    opcion=8;

                default:
                    break;
                }
            }
        }
    } while (opcion != 8);
    printf("\nEl programa ha finalizado, gracias por su paciencia :3\n");

    return 0;
}