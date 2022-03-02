#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>

struct MBR
{
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature;
    char *mbr_fit;
};

void FDISK(char *x, char *y, char *z, char *v)
{
    printf("%s %s %s %s %s\n", "Esta prueba es de mkdisk split:", x, y, z, v);
    char igual[] = "=";

    char *split = strtok(x, igual);
    printf(" %s\n", split);

    int s = 0;

    int u = 0;

    int a = 0;

    int w = 0;

    char *path[100];
    char *size[100];
    char *unit[100];
    char *name[100];

    // unit[0] = "m";

    printf("%s %d %d %d %d\n", "Prueba de parametros:", a, s, u, w);

    while (split != NULL)
    {
        if (strcmp(split, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    path[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    size[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    unit[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-name") == 0)
        {
            w = w + 1;
            printf("Analizando comando, procesando instruccion name... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-name") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    name[0] = split;
                    break;
                }
            }
            break;
        }
        else
        {
            printf(" \n");
            printf("ERROR/Advbertencia: comando inexistente u variable nula\n");
            printf(" \n");
            break;
        }
    }

    char *divi = strtok(y, igual);
    printf(" %s\n", divi);

    while (divi != NULL)
    {
        if (strcmp(divi, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    path[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    size[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    unit[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-name") == 0)
        {
            w = w + 1;
            printf("Analizando comando, procesando instruccion name... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-name") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    name[0] = divi;
                    break;
                }
            }
            break;
        }
        else
        {
            printf(" \n");
            printf("ERROR/Advbertencia: comando inexistente u variable nula\n");
            printf(" \n");
            break;
        }
    }
    printf("%s %d %d %d %d\n", "Prueba de parametros:", a, s, u, w);

    char *separar = strtok(z, igual);
    printf(" %s\n", separar);

    while (separar != NULL)
    {
        if (strcmp(separar, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s", separar);
                }
                else
                {
                    printf(" %s", separar);
                    path[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    size[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    unit[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-name") == 0)
        {
            w = w + 1;
            printf("Analizando comando, procesando instruccion name... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-name") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    name[0] = separar;
                    break;
                }
            }
            break;
        }
        else
        {
            printf(" \n");
            printf("ERROR/Advbertencia: comando inexistente u variable nula\n");
            printf(" \n");
            break;
        }
    }

    printf("Prueba de la llegada\n");

    char *otra = strtok(v, igual);
    printf(" %s\n", otra);

    while (otra != NULL)
    {
        if (strcmp(otra, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (otra != NULL)
            {
                if (strcmp(otra, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    otra = strtok(NULL, " ");
                    printf(" %s", otra);
                }
                else
                {
                    printf(" %s", otra);
                    path[0] = otra;
                    break;
                }
            }
            break;
        }
        else if (strcmp(otra, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (otra != NULL)
            {
                if (strcmp(otra, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    otra = strtok(NULL, " ");
                    printf(" %s\n", otra);
                }
                else
                {
                    printf(" %s\n", otra);
                    size[0] = otra;
                    break;
                }
            }
            break;
        }
        else if (strcmp(otra, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (otra != NULL)
            {
                if (strcmp(otra, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    otra = strtok(NULL, " ");
                    printf(" %s\n", otra);
                }
                else
                {
                    printf(" %s\n", otra);
                    unit[0] = otra;
                    break;
                }
            }
            break;
        }
        else if (strcmp(otra, "-name") == 0)
        {
            w = w + 1;
            printf("Analizando comando, procesando instruccion name... \n");
            printf("Analizando..... \n");
            while (otra != NULL)
            {
                if (strcmp(otra, "-name") == 0)
                {
                    printf("Analizando..... \n");
                    otra = strtok(NULL, " ");
                    printf(" %s", otra);
                }
                else
                {
                    printf(" %s", otra);
                    name[0] = otra;
                    break;
                }
            }
            break;
        }
        else
        {
            printf(" \n");
            printf("ERROR/Advbertencia: comando inexistente u variable nula\n");
            printf(" \n");
            break;
        }
    }

    printf("Prueba de la llegada\n");

    printf("%s %d %d %d %d\n", "Prueba de parametros:", a, s, u, w);

    printf("TERMINAR PROCESAMIENTO FDISK\n");

    if (a == 1 && s == 1 && w == 1 && (u == 0 || u == 1))
    {
        FILE *arch1;
        path[0][strcspn(path[0], "\n")] = 0;
        arch1 = fopen(path[0], "ab");
        if (arch1 == NULL)
            exit(1);

        MBR master;
        int cont = 0;
        printf(" Creando Archivo....\n");

        time_t t;

        t = time(NULL);

        if (strcmp(unit[0], "m") == 0)
        {
            master.mbr_tamano = strtol(size[0], NULL, 10) * 1000000;
            master.mbr_fecha_creacion = t;
            master.mbr_dsk_signature = rand() % 500;

            fwrite(&master, strtol(size[0], NULL, 10) * 1000000, 1, arch1);
        }
        else if (strcmp(unit[0], "b") == 0)
        {
            master.mbr_tamano = strtol(size[0], NULL, 10);
            master.mbr_fecha_creacion = t;
            master.mbr_dsk_signature = rand() % 500;

            fwrite(&master, strtol(size[0], NULL, 10), 1, arch1);
        }
        else if (strcmp(unit[0], "k") == 0)
        {
            master.mbr_tamano = strtol(size[0], NULL, 10) * 125;
            master.mbr_fecha_creacion = t;
            master.mbr_dsk_signature = rand() % 500;

            fwrite(&master, strtol(size[0], NULL, 10) * 125, 1, arch1);
        }
        else
        {
            master.mbr_tamano = strtol(size[0], NULL, 10) * 1000000;
            master.mbr_fecha_creacion = t;
            master.mbr_dsk_signature = rand() % 500;

            fwrite(&master, strtol(size[0], NULL, 10) * 1000000, 1, arch1);
        }

        fclose(arch1);
        printf(" \n");
        printf("Termino de carga de Datos\n");

        printf(" \n");
    }
    else
    {
        printf(" \n");
        printf("ERROR: Falta de parametros obligatorios o exceso del mismo parametro\n");
        printf(" \n");
    }
}

void MKDISK(char *x, char *y, char *z, char *v)
{

    printf("%s %s %s %s %s\n", "Esta prueba es de mkdisk split:", x, y, z, v);
    char igual[] = "=";

    int s = 0;

    int u = 0;

    int a = 0;

    int f = 0;

    char *path[100];
    char *size[100];
    char *unit[100];
    char *fit[100];

    fit[0] = "FF";
    unit[0] = "m";

    // unit[0] = "m";

    printf("%s %d %d %d\n", "Prueba de parametros:", a, s, u);

    char *split = strtok(x, igual);
    printf(" %s\n", split);

    while (split != NULL)
    {
        if (strcmp(split, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    path[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    size[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    unit[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-fit") == 0)
        {
            f = f + 1;
            printf("Analizando comando, procesando instruccion fit... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-fit") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    fit[0] = split;
                    break;
                }
            }
            break;
        }
        else
        {
            printf(" \n");
            printf("ERROR/Advbertencia: comando inexistente u variable nula\n");
            printf(" \n");
            break;
        }
    }

    char *divi = strtok(y, igual);
    printf(" %s\n", divi);

    while (divi != NULL)
    {
        if (strcmp(divi, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    path[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    size[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    unit[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-fit") == 0)
        {
            f = f + 1;
            printf("Analizando comando, procesando instruccion fit... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-fit") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    fit[0] = divi;
                    break;
                }
            }
            break;
        }
        else
        {
            printf(" \n");
            printf("ERROR/Advbertencia: comando inexistente u variable nula\n");
            printf(" \n");
            break;
        }
    }
    printf("%s %d %d %d\n", "Prueba de parametros:", a, s, u);

    char *separar = strtok(z, igual);
    printf(" %s\n", separar);

    while (separar != NULL)
    {
        if (strcmp(separar, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s", separar);
                }
                else
                {
                    printf(" %s", separar);
                    path[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    size[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    unit[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-fit") == 0)
        {
            f = f + 1;
            printf("Analizando comando, procesando instruccion fit... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-fit") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    fit[0] = separar;
                    break;
                }
            }
            break;
        }
        else
        {
            printf(" \n");
            printf("ERROR/Advbertencia: comando inexistente u variable nula\n");
            printf(" \n");
            break;
        }
    }

    char *otra = strtok(v, igual);
    printf(" %s\n", otra);

    while (otra != NULL)
    {
        if (strcmp(otra, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (otra != NULL)
            {
                if (strcmp(otra, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    otra = strtok(NULL, " ");
                    printf(" %s", otra);
                }
                else
                {
                    printf(" %s", otra);
                    path[0] = otra;
                    break;
                }
            }
            break;
        }
        else if (strcmp(otra, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (otra != NULL)
            {
                if (strcmp(otra, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    otra = strtok(NULL, " ");
                    printf(" %s\n", otra);
                }
                else
                {
                    printf(" %s\n", otra);
                    size[0] = otra;
                    break;
                }
            }
            break;
        }
        else if (strcmp(otra, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (otra != NULL)
            {
                if (strcmp(otra, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    otra = strtok(NULL, " ");
                    printf(" %s\n", otra);
                }
                else
                {
                    printf(" %s\n", otra);
                    unit[0] = otra;
                    break;
                }
            }
            break;
        }
        else if (strcmp(otra, "-fit") == 0)
        {
            f = f + 1;
            printf("Analizando comando, procesando instruccion fit... \n");
            printf("Analizando..... \n");
            while (otra != NULL)
            {
                if (strcmp(otra, "-fit") == 0)
                {
                    printf("Analizando..... \n");
                    otra = strtok(NULL, " ");
                    printf(" %s\n", otra);
                }
                else
                {
                    printf(" %s\n", otra);
                    fit[0] = otra;
                    break;
                }
            }
            break;
        }
        else
        {
            printf(" \n");
            printf("ERROR/Advbertencia: comando inexistente u variable nula\n");
            printf(" \n");
            break;
        }
    }

    printf("Prueba de la llegada\n");

    printf("%s %d %d %d\n", "Prueba de parametros:", a, s, u);

    if (a == 1 && s == 1 && (u == 0 || u == 1) && (f == 0 || f == 1))
    {
        // Espera
        printf(" \n");
        FILE *arch;
        // char nombre;
        printf("%s %s\n", "Esta es la direccion PATH:", path[0]);

        path[0][strcspn(path[0], "\n")] = 0;

        arch = fopen(path[0], "wb");

        if (arch == NULL)
            exit(1);
        fclose(arch);

        printf(" \n");

        FILE *arch1;
        arch1 = fopen(path[0], "ab");
        if (arch1 == NULL)
            exit(1);

        MBR master;
        int cont = 0;
        printf(" Creando Archivo....\n");

        time_t t;

        t = time(NULL);

        if ((strcmp(fit[0], "BF") == 0) || (strcmp(fit[0], "FF") == 0) || (strcmp(fit[0], "WF") == 0))
        {
            if (strcmp(unit[0], "m") == 0)
            {
                master.mbr_tamano = strtol(size[0], NULL, 10) * 1024 * 1024;
                master.mbr_fecha_creacion = t;
                master.mbr_dsk_signature = rand() % 500;
                master.mbr_fit = fit[0];

                printf("%s %d\n", "Este es el tamaño:", master.mbr_tamano);

                fwrite(&master, master.mbr_tamano, 1, arch1);
            }
            else if (strcmp(unit[0], "k") == 0)
            {
                master.mbr_tamano = strtol(size[0], NULL, 10) * 1024;
                master.mbr_fecha_creacion = t;
                master.mbr_dsk_signature = rand() % 500;
                master.mbr_fit = fit[0];

                printf("%s %d\n", "Este es el tamaño:", master.mbr_tamano);

                fwrite(&master, master.mbr_tamano, 1, arch1);
            }
            else
            {
                printf(" \n");
                printf("ERROR/Advertencia: valor inexistente u variable nula\n");
                printf(" \n");
            }
        }
        else
        {
            printf(" \n");
            printf("ERROR/Advertencia: valor inexistente u variable nula\n");
            printf(" \n");
        }

        fclose(arch1);
        printf(" \n");
        printf("Creacion de Archivo Terminada\n");

        printf(" \n");
    }
    else
    {
        printf(" \n");
        printf("ERROR: Falta de parametros obligatorios o exceso del mismo parametro\n");
        printf(" \n");
    }
}

void REP()
{
    printf(" \n");
    printf("Procesando.... \n");

    FILE *arch;
    arch = fopen("Archivo_Binario.dk", "rb");
    if (arch == NULL)
        exit(1);

    MBR maestro;
    fread(&maestro, sizeof(MBR), 1, arch);

    printf("Tamaño: ");

    printf("%d\n", maestro.mbr_tamano);
    printf("Fecha de Creacion: ");
    printf("%ld\n", maestro.mbr_fecha_creacion);
    printf("Signature: ");
    printf("%d", maestro.mbr_dsk_signature);

    // while((maestro.Id_profesor = getchar()) != '\n' && maestro.Id_profesor != EOF);
    fread(&maestro, sizeof(MBR), 1, arch);
    printf("\n");

    fclose(arch);
    printf("Muestra Terminada... \n");
    printf("Procesamiento Terminado\n");
}

void EXEC(char *x)
{
    printf("%s %s\n", "Esta prueba es de split:", x);
    char igual[] = "=";

    char espacio[] = " ";

    int cont = 0;

    char *split = strtok(x, igual);

    char *mknum[200];

    mknum[0] = NULL;
    mknum[1] = NULL;
    mknum[2] = NULL;
    mknum[3] = NULL;

    if (strcmp(split, "-path") == 0)
    {
        printf("Buscando direccion entre archivos... \n");
        printf("Analizando..... \n");
        while (split != NULL)
        {
            if (strcmp(split, "-path") == 0)
            {
                printf("Analizando..... \n");
                split = strtok(NULL, " ");
            }
            else
            {
                printf(" %s\n", split); // printing each token

                printf(" \n");
                printf("Abriendo script \n");

                printf(" %s\n", split);

                char t = *split;

                split[strcspn(split, "\n")] = 0;

                if (strcmp(split, "/home/manuel/Descargas/hola.txt") == 0)
                {
                    printf("Deberia funcionar \n");
                }
                else
                {
                    printf("No es igual \n");
                }

                // printf(" %s\n", t);

                FILE *arch;
                arch = fopen(split, "r");
                char contenido[200];

                printf(" %s\n", split);

                if (arch == NULL)
                {
                    exit(1);
                }
                else
                {

                    printf(" %s\n", split);

                    printf("Procesando...\n");

                    // fread(contenido, 30, 1, arch);
                    while (feof(arch) == 0)
                    {
                        printf("Procesando...\n");

                        fgets(contenido, 200, arch);

                        printf("%s", contenido);
                        // printf("ERRORRR");

                        char *opcion = strtok(contenido, espacio);

                        if (strcmp(opcion, "exit\n") == 0)
                        {
                            printf("Cerrando CDM \n");
                        }
                        else if (strcmp(opcion, "mkdisk") == 0)
                        {
                            printf("EJECUTANDO: Comando mkdisk \n");
                            printf("Analizando..... \n");
                            while (opcion != NULL)
                            {
                                if (strcmp(opcion, "mkdisk") == 0)
                                {
                                    printf("Analizando..... \n");
                                    opcion = strtok(NULL, " ");
                                }
                                else
                                {
                                    // printf(" %s\n", opcion); // printing each token
                                    //  MKDISK(opcion);
                                    //   split = strtok(NULL, " ");
                                    mknum[cont] = opcion;
                                    // MKDISK(split);
                                    printf(" %s\n", mknum[cont]);

                                    cont = cont + 1;
                                    opcion = strtok(NULL, " ");
                                }
                            }
                            MKDISK(mknum[0], mknum[1], mknum[2], mknum[3]);
                            cont = 0;
                            mknum[0] = NULL;
                            mknum[1] = NULL;
                            mknum[2] = NULL;
                            mknum[3] = NULL;
                        }
                        else if (strcmp(opcion, "fdisk") == 0)
                        {
                            printf("EJECUTANDO: Comando fdisk \n");
                            printf("Analizando..... \n");
                            while (opcion != NULL)
                            {
                                if (strcmp(opcion, "fdisk") == 0)
                                {
                                    printf("Analizando..... \n");
                                    opcion = strtok(NULL, " ");
                                }
                                else
                                {
                                    // printf(" %s\n", opcion); // printing each token
                                    //  MKDISK(opcion);
                                    //   split = strtok(NULL, " ");
                                    mknum[cont] = opcion;
                                    // MKDISK(split);
                                    printf(" %s\n", mknum[cont]);

                                    cont = cont + 1;
                                    opcion = strtok(NULL, " ");
                                }
                            }
                            FDISK(mknum[0], mknum[1], mknum[2], mknum[3]);
                            cont = 0;
                            mknum[0] = NULL;
                            mknum[1] = NULL;
                            mknum[2] = NULL;
                            mknum[3] = NULL;
                        }
                        else if (strcmp(opcion, "rep\n") == 0)
                        {
                            printf("EJECUTANDO: Comando rep \n");
                            printf("Analizando..... \n");
                            REP();
                        }
                        else
                        {
                            printf(" \n");
                            printf("ERROR: Utilice un comando existente y/o instruccion adecuada\n");
                            printf(" \n");
                        }

                        // while((maestro.Id_profesor = getchar()) != '\n' && maestro.Id_profesor != EOF);
                        // fread(contenido, sizeof(contenido), 1, arch);
                        printf("\n");
                    }
                }
                fclose(arch);

                split = strtok(NULL, " ");

                break;
            }
        }
    }
    else
    {
        printf(" \n");
        printf("ERROR: Utilice un comando existente y/o instruccion adecuada\n");
        printf(" \n");
    }
}

int main()
{

    char cmd[200];

    char espacio[] = " ";

    int cont = 0;

    char *mknum[200];

    mknum[0] = NULL;
    mknum[1] = NULL;
    mknum[2] = NULL;
    mknum[3] = NULL;

    printf("\n");

    do
    {
        // printf("Prueba: ");

        fgets(cmd, 200, stdin);

        // printf(" \n");
        // printf("%s %s\n", "Esta prueba es de split: ", cmd);

        char *split = strtok(cmd, espacio);

        // printf("%s %s\n", "Esta prueba es de split: ", cmd);
        //  printf(" \n");

        if (strcmp(split, "exit") == 0)
        {
            printf("Cerrando CDM \n");
        }
        else if (strcmp(split, "mkdisk") == 0)
        {
            printf("EJECUTANDO: Comando mkdisk \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "mkdisk") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                }
                else
                {
                    // printf(" %s\n", split); // printing each token

                    mknum[cont] = split;
                    // MKDISK(split);
                    printf(" %s\n", mknum[cont]);

                    cont = cont + 1;
                    split = strtok(NULL, " ");
                }
            }
            MKDISK(mknum[0], mknum[1], mknum[2], mknum[3]);
            cont = 0;
            mknum[0] = NULL;
            mknum[1] = NULL;
            mknum[2] = NULL;
            mknum[3] = NULL;
        }
        else if (strcmp(split, "rep") == 0)
        {
            printf("EJECUTANDO: Comando rep \n");
            printf("Analizando..... \n");
            REP();
        }
        else if (strcmp(split, "exec") == 0)
        {
            printf("EJECUTANDO: Comando exec \n");
            printf("ADVERTENCIA: la dreccion del archivo NO debe tener espacios; Se mostrara ERROR \n");
            while (split != NULL)
            {
                if (strcmp(split, "exec") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                }
                else
                {
                    printf(" %s\n", split); // printing each token
                    EXEC(split);
                    // split = strtok(NULL, " ");
                    break;
                }
            }
        }
        else if (strcmp(split, "fdisk") == 0)
        {
            printf("EJECUTANDO: Comando fdisk \n");
            printf("Analizando... \n");
            while (split != NULL)
            {
                if (strcmp(split, "fdisk") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                }
                else
                {
                    // printf(" %s\n", split); // printing each token

                    mknum[cont] = split;
                    // MKDISK(split);
                    printf(" %s\n", mknum[cont]);

                    cont = cont + 1;
                    split = strtok(NULL, " ");
                }
            }
            FDISK(mknum[0], mknum[1], mknum[2], mknum[3]);
            cont = 0;
            mknum[0] = NULL;
            mknum[1] = NULL;
            mknum[2] = NULL;
            mknum[3] = NULL;
        }
        else
        {
            printf(" \n");
            printf("ERROR: Utilice un comando existente y/o instruccion adecuada\n");
            printf(" \n");
            cont = 0;
        }

    } while (strcmp(cmd, "exit") != 0);
    return 0;
}