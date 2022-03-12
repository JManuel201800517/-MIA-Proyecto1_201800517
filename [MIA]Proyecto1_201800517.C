#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>

struct SuperBloque
{
    int s_filesystem_type;
    int s_inodes_count;
    int s_blocks_count;
    int s_free_blocks_count;
    int s_free_inodes_count;
    time_t s_mtime;
    time_t s_umtime;
    int s_mnt_count;
    int s_magic;
    int s_inode_size;
    int s_block_size;
    int s_firts_ino;
    int s_first_blo;
    int s_bm_inode_start;
    int s_bm_block_start;
    int s_inode_start;
    int s_block_start;
};

struct TablaInodos
{
    int i_uid;
    int I_gid;
    int i_size;
    time_t i_atime;
    time_t i_ctime;
    time_t i_mtime;
    int i_block;
    char i_type[5];
    int i_perm;
};

struct ContenidoCarpeta
{
    char b_name[12];
    int b_inodo;
};

struct BloqueCarpeta
{
    ContenidoCarpeta b_content[4];
};

struct BloqueApuntadores
{
    int b_pointers[16];
};

struct BloqueArchivo
{
    char b_content[64];
};

struct Datos
{
    char Disco[100];
    char name[16];
    char letra[10];
    int numero;
};

struct Montado
{
    char Disco[100];
    char id[10];
    char name[16];
};

struct Particion
{
    char part_status[5];
    char part_type[5];
    char part_fit[5];
    int part_start;
    int part_size;
    char part_name[16];
};

struct EBR
{
    char part_status[5];
    char part_fit[5];
    int part_start;
    int part_size;
    int part_next;
    char part_name[16];
};

struct MBR
{
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature;
    char mbr_fit[5];
    Particion mbr_partcion[4];
};

struct Usuario
{

    int UID;
    char Tipo[10];
    char Grupo[10];
    char Usuario[10];
    char Contrasenia[10];
};

struct Grupo
{
    int GID;
    char Tipo[10];
    char Grupo[10];
};

struct EXT2
{
    SuperBloque Super_Bloque;
    int Bitmap_Inodos;
    int Bitmap_Bloques;
    TablaInodos Inodos;
    BloqueCarpeta Bloque_Carpeta;
    BloqueArchivo Bloque_Archivo;
    BloqueApuntadores Bloque_Apuntatadores;
};

struct EXT3
{
    SuperBloque Super_Bloque;
    int Journaling;
    int Bitmap_Inodos;
    int Bitmap_Bloques;
    TablaInodos Inodos;
    BloqueCarpeta Bloque_Carpeta;
    BloqueArchivo Bloque_Archivo;
    BloqueApuntadores Bloque_Apuntadores;
};

int variablecuenta = 0;

Montado montar[100];

bool login = false;

char ID_UTILIZADO[10];

char User_Actual[10];

void LOGOUT()
{

    if (login == true)
    {
        login = false;
        strcpy(ID_UTILIZADO, "\0");
        strcpy(User_Actual, "\0");
        printf("Cerrando Login....\n");
        chdir("..");
        printf("Sesion Cerrada\n");
    }
    else
    {
        printf(" \n");
        printf("ERROR: No hay sesion iniciada....\n");
        printf("RECOMENDACION: Se debe iniciar sesion primero antes de poder cerrarla....\n");
        printf(" \n");
    }
}

void LOGIN(char *x, char *y, char *z)
{
    printf("%s %s %s %s\n", "Esta prueba es de login split:", x, y, z);
    char igual[] = "=";

    int s = 0;

    int u = 0;

    int a = 0;

    int part = 0;

    char *id[100];
    char *usuario[100];
    char *password[100];

    printf("%s %d %d %d\n", "Prueba de parametros:", a, s, u);

    char *split = strtok(x, igual);
    printf(" %s\n", split);

    for (size_t i = 0; i < strlen(split); ++i)
    {
        split[i] = tolower((unsigned char)split[i]);
        // printf(" %c\n", split[i]);
    }

    while (split != NULL)
    {
        if (strcmp(split, "-id") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion id... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-id") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    id[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-usuario") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion usuario... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-usuario") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    usuario[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-password") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion password... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-password") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    password[0] = split;
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

    for (size_t i = 0; i < strlen(divi); ++i)
    {
        divi[i] = tolower((unsigned char)divi[i]);
        // printf(" %c\n", split[i]);
    }

    while (divi != NULL)
    {
        if (strcmp(divi, "-id") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion id... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-id") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    id[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-usuario") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion usuario... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-usuario") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    usuario[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-password") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion password... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-password") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    password[0] = divi;
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

    for (size_t i = 0; i < strlen(separar); ++i)
    {
        separar[i] = tolower((unsigned char)separar[i]);
        // printf(" %c\n", split[i]);
    }

    while (separar != NULL)
    {
        if (strcmp(separar, "-id") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion id... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-id") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s", separar);
                }
                else
                {
                    printf(" %s", separar);
                    id[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-usuario") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion usuario... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-usuario") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    usuario[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-password") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion password... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-password") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    password[0] = separar;
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

    if (a == 1 && s == 1 && u == 1)
    {
        if (login == false)
        {

            chdir(id[0]);

            FILE *arch1;
            arch1 = fopen("users.txt", "rb");
            if (arch1 == NULL)
                exit(1);

            Usuario user;
            int cont = 0;
            int existe = 1;
            printf(" Leyendo Archivo users.txt....\n");

            time_t t;

            t = time(NULL);

            fread(&user, sizeof(Usuario), 1, arch1);

            while (!feof(arch1))
            {

                if (user.Usuario == usuario[0] && user.Contrasenia == password[0])
                {
                    strcpy(ID_UTILIZADO, id[0]);
                    strcpy(User_Actual, usuario[0]);
                    login = true;
                    existe = 0;

                    break;
                }
                else
                {
                    printf(" \n");
                    printf("Buscando Datos.....\n");
                    printf(" \n");
                }

                fread(&user, sizeof(Usuario), 1, arch1);
            }
            if (existe == 1)
            {
                printf(" \n");
                printf("Datos no coinciden.....\n");
                printf("Reformular sus parametros.....\n");
                printf(" \n");
            }

            fclose(arch1);
        }
        else
        {
            printf(" \n");
            printf("ERROR: Sesion iniciada con anterioridad....\n");
            printf("RECOMENDACION: Cerrar sesion primero antes de volver a iniciar....\n");
            printf(" \n");
        }
    }
    else
    {
        printf(" \n");
        printf("ERROR: Falta de parametros obligatorios o exceso del mismo parametro\n");
        printf(" \n");
    }
}

void RMDISK(char *x)
{

    printf("%s %s\n", "Esta prueba es de split:", x);
    char igual[] = "=";

    char espacio[] = " ";

    int cont = 0;

    char *split = strtok(x, igual);

    for (size_t i = 0; i < strlen(split); ++i)
    {
        split[i] = tolower((unsigned char)split[i]);
        // printf(" %c\n", split[i]);
    }

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

                /*if (strcmp(split, "/home/manuel/Descargas/hola.txt") == 0)
                {
                    printf("Deberia funcionar \n");
                }
                else
                {
                    printf("No es igual \n");
                }*/

                // printf(" %s\n", t);
                FILE *archivo;
                archivo = fopen(split, "w");
                // fprintf(archivo,"Hola Mundo");
                fclose(archivo);

                if (remove(split) == 0) // Eliminamos el archivo
                    printf("El archivo fue eliminado satisfactoriamente\n");
                else
                    printf("No se pudo eliminar el archivo\n");

                // system("PAUSE");
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

void MKFS(char *x, char *y, char *z)
{

    printf("%s %s %s %s\n", "Esta prueba es de mkfs split:", x, y, z);
    char igual[] = "=";

    int s = 0;

    int u = 0;

    int a = 0;

    int part = 0;

    char dd[5] = "2fs";
    char d1[5] = "Full";

    char *id[100];
    char *type[100];
    char *fs[100];

    printf("%s %d %d %d\n", "Prueba de parametros:", a, s, u);

    char *split = strtok(x, igual);
    printf(" %s\n", split);

    for (size_t i = 0; i < strlen(split); ++i)
    {
        split[i] = tolower((unsigned char)split[i]);
        // printf(" %c\n", split[i]);
    }

    while (split != NULL)
    {
        if (strcmp(split, "-id") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion id... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-id") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    id[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-type") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion type... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-type") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    type[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-fs") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion fs... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-fs") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    fs[0] = split;
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

    for (size_t i = 0; i < strlen(divi); ++i)
    {
        divi[i] = tolower((unsigned char)divi[i]);
        // printf(" %c\n", split[i]);
    }

    while (divi != NULL)
    {
        if (strcmp(divi, "-id") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion id... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-id") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    id[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-type") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion type... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-type") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    type[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-fs") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion fs... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-fs") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    fs[0] = divi;
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

    for (size_t i = 0; i < strlen(separar); ++i)
    {
        separar[i] = tolower((unsigned char)separar[i]);
        // printf(" %c\n", split[i]);
    }

    while (separar != NULL)
    {
        if (strcmp(separar, "-id") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion id... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-id") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s", separar);
                }
                else
                {
                    printf(" %s", separar);
                    id[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-type") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion type... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-type") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    type[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-fs") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion fs... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-fs") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    fs[0] = separar;
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

    if (a == 1 && (s == 1 || s == 0) && (u == 1 || u == 0))
    {

        id[0][strcspn(id[0], "\n")] = 0;
        type[0][strcspn(type[0], "\n")] = 0;
        fs[0][strcspn(fs[0], "\n")] = 0;

        chdir(id[0]);

        if (u == 0)
        {
            printf("Valor Fit establecido automaticamente\n");
            fs[0] = dd;
        }
        else
        {
            printf("Print Encontrado\n");
        }
        if (s == 0)
        {
            printf("Valor Unit establecido automaticamente\n");
            type[0] = d1;
        }
        else
        {
            printf("Print Encontrado\n");
        }

        printf(" \n");
        FILE *arch;
        // char nombre;
        printf("%s %s\n", "Esta es la direccion PATH:", "users.txt");

        arch = fopen("users.txt", "wb");

        if (arch == NULL)
            exit(1);
        fclose(arch);

        printf("Creando archivo users.txt.......\n");
        FILE *arch1;
        arch1 = fopen("users.txt", "ab");
        if (arch1 == NULL)
            exit(1);

        Usuario user;
        Grupo group;
        int cont = 0;
        printf(" Creando Archivo....\n");

        time_t t;

        t = time(NULL);

        group.GID = 1;
        strcpy(group.Tipo, "G");
        strcpy(group.Grupo, "root");

        // int byte = sizeof(Usuario) + sizeof(Grupo);

        fwrite(&group, sizeof(Grupo), 1, arch1);

        user.UID = 1;
        strcpy(user.Tipo, "U");
        strcpy(user.Grupo, "root");
        strcpy(user.Usuario, "root");
        stpcpy(user.Contrasenia, "123");

        fwrite(&user, sizeof(Usuario), 1, arch1);

        fclose(arch1);
        printf(" \n");
        printf("Creacion de Archivo Users.txt Terminada\n");

        printf(" \n");

        chdir("..");
    }
    else
    {
        printf(" \n");
        printf("ERROR: Falta de parametros obligatorios o exceso del mismo parametro\n");
        printf(" \n");
    }
}

void MOUNT(char *x, char *y)
{
    printf("%s %s %s\n", "Esta prueba es de mount split:", x, y);
    char igual[] = "=";

    int s = 0;

    int a = 0;

    int part = 0;

    char *path[100];
    char *name[100];

    // char *cero[100];

    // char *sino[100];

    // printf("%s %d %d %d\n", "Prueba de parametros:", a, s, u);

    char *split = strtok(x, igual);
    printf(" %s\n", split);

    for (size_t i = 0; i < strlen(split); ++i)
    {
        split[i] = tolower((unsigned char)split[i]);
        // printf(" %c\n", split[i]);
    }

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
        else if (strcmp(split, "-name") == 0)
        {
            s = s + 1;
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

    for (size_t i = 0; i < strlen(divi); ++i)
    {
        divi[i] = tolower((unsigned char)divi[i]);
        // printf(" %c\n", split[i]);
    }

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
        else if (strcmp(divi, "-name") == 0)
        {
            s = s + 1;
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
    printf("%s %d %d\n", "Prueba de parametros:", a, s);

    path[0][strcspn(path[0], "\n")] = 0;
    name[0][strcspn(name[0], "\n")] = 0;

    if (a == 1 && s == 1)
    {
        FILE *arch1;
        arch1 = fopen(path[0], "r+b");
        if (arch1 == NULL)
            exit(1);

        MBR master;
        int cont = 0;
        int existe = 1;
        printf(" Actualizando Archivo....\n");

        time_t t;

        t = time(NULL);

        fread(&master, sizeof(MBR), 1, arch1);

        while (!feof(arch1))
        {
            if (name[0] == master.mbr_partcion[0].part_name)
            {
                int pos = ftell(arch1) - sizeof(MBR);
                strcpy(master.mbr_partcion[0].part_status, "1");

                fseek(arch1, pos, SEEK_SET);
                fwrite(&master, sizeof(MBR), 1, arch1);
                printf("Se modifico los datos de la particion.\n");
                printf("PARTICION ACTIVADA.........\n");
                existe = 1;

                printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                // Montado montar;

                char diccionario[] = {
                    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                    'w', 'x', 'y', 'z',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                    'W', 'X', 'Y', 'Z'};

                char diccionario1[11];

                char car[] = "17";

                char jj = diccionario1[rand() % 11];

                char ID[100];

                sprintf(diccionario1, "%d", rand() % 11);

                strcat(strcpy(ID, car), diccionario1);

                char cadena[2];
                char caracter = diccionario[rand() % 53];
                cadena[0] = caracter;
                cadena[1] = '\0';

                strcat(ID, cadena);

                strcpy(montar[variablecuenta].Disco, path[0]);
                strcpy(montar[variablecuenta].name, name[0]);
                strcpy(montar[variablecuenta].id, ID);

                variablecuenta = variablecuenta + 1;

                mkdir(ID, 0777);

                break;
            }
            else
            {
                if (name[0] == master.mbr_partcion[1].part_name)
                {
                    int pos = ftell(arch1) - sizeof(MBR);
                    strcpy(master.mbr_partcion[1].part_status, "1");

                    fseek(arch1, pos, SEEK_SET);
                    fwrite(&master, sizeof(MBR), 1, arch1);
                    printf("Se modifico los datos de la particion.\n");
                    printf("PARTICION ACTIVADA.........\n");
                    existe = 1;

                    printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                    printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                    printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                    printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                    printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                    printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                    // Montado montar;

                    char diccionario[] = {
                        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                        'w', 'x', 'y', 'z',
                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                        'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                        'W', 'X', 'Y', 'Z'};

                    char diccionario1[11];

                    char car[] = "17";

                    char jj = diccionario1[rand() % 11];

                    char ID[100];

                    sprintf(diccionario1, "%d", rand() % 11);

                    strcat(strcpy(ID, car), diccionario1);

                    char cadena[2];
                    char caracter = diccionario[rand() % 53];
                    cadena[0] = caracter;
                    cadena[1] = '\0';

                    strcat(ID, cadena);

                    strcpy(montar[variablecuenta].Disco, path[0]);
                    strcpy(montar[variablecuenta].name, name[0]);
                    strcpy(montar[variablecuenta].id, ID);

                    variablecuenta = variablecuenta + 1;

                    mkdir(ID, 0777);

                    break;
                }
                else
                {
                    if (name[0] == master.mbr_partcion[2].part_name)
                    {
                        int pos = ftell(arch1) - sizeof(MBR);
                        strcpy(master.mbr_partcion[2].part_status, "1");

                        fseek(arch1, pos, SEEK_SET);
                        fwrite(&master, sizeof(MBR), 1, arch1);
                        printf("Se modifico los datos de la particion.\n");
                        printf("PARTICION ACTIVADA.........\n");
                        existe = 1;

                        printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                        printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                        printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                        printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                        printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                        printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                        // Montado montar;

                        char diccionario[] = {
                            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                            'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                            'w', 'x', 'y', 'z',
                            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                            'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                            'W', 'X', 'Y', 'Z'};

                        char diccionario1[11];

                        char car[] = "17";

                        char jj = diccionario1[rand() % 11];

                        char ID[100];

                        sprintf(diccionario1, "%d", rand() % 11);

                        strcat(strcpy(ID, car), diccionario1);

                        char cadena[2];
                        char caracter = diccionario[rand() % 53];
                        cadena[0] = caracter;
                        cadena[1] = '\0';

                        strcat(ID, cadena);

                        strcpy(montar[variablecuenta].Disco, path[0]);
                        strcpy(montar[variablecuenta].name, name[0]);
                        strcpy(montar[variablecuenta].id, ID);

                        variablecuenta = variablecuenta + 1;

                        mkdir(ID, 0777);

                        break;
                    }
                    else
                    {
                        if (name[0] == master.mbr_partcion[3].part_name)
                        {
                            int pos = ftell(arch1) - sizeof(MBR);
                            strcpy(master.mbr_partcion[3].part_status, "1");

                            fseek(arch1, pos, SEEK_SET);
                            fwrite(&master, sizeof(MBR), 1, arch1);
                            printf("Se modifico los datos de la particion.\n");
                            printf("PARTICION ACTIVADA.........\n");
                            existe = 1;

                            printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                            printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                            printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                            printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                            printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                            printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                            // Montado montar;

                            char diccionario[] = {
                                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                                'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z',
                                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                                'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                                'W', 'X', 'Y', 'Z'};

                            char diccionario1[11];

                            char car[] = "17";

                            char jj = diccionario1[rand() % 11];

                            char ID[100];

                            sprintf(diccionario1, "%d", rand() % 11);

                            strcat(strcpy(ID, car), diccionario1);

                            char cadena[2];
                            char caracter = diccionario[rand() % 53];
                            cadena[0] = caracter;
                            cadena[1] = '\0';

                            strcat(ID, cadena);

                            strcpy(montar[variablecuenta].Disco, path[0]);
                            strcpy(montar[variablecuenta].name, name[0]);
                            strcpy(montar[variablecuenta].id, ID);

                            variablecuenta = variablecuenta + 1;

                            mkdir(ID, 0777);

                            break;
                        }
                        else
                        {
                            printf("NO HAY PARTICIONES CONCORDANTES\n");
                            printf(" \n");
                            printf("ERROR/Advertencia: NO SE PUEDE ENCONTRAR LA PARTCION\n");
                            printf(" \n");
                            break;
                        }
                    }
                }
            }

            fread(&master, sizeof(MBR), 1, arch1);
        }

        fclose(arch1);
    }
    else
    {
        printf(" \n");
        printf("ERROR: Falta de parametros obligatorios o exceso del mismo parametro\n");
        printf(" \n");
    }
}

void UNMOUNT(char *x)
{
    printf("%s %s\n", "Esta prueba es de unmount split:", x);
    char igual[] = "=";

    int a = 0;

    int part = 0;

    char *id[100];

    // char *cero[100];

    // char *sino[100];

    // printf("%s %d %d %d\n", "Prueba de parametros:", a, s, u);

    char *split = strtok(x, igual);
    printf(" %s\n", split);

    for (size_t i = 0; i < strlen(split); ++i)
    {
        split[i] = tolower((unsigned char)split[i]);
        // printf(" %c\n", split[i]);
    }

    while (split != NULL)
    {
        if (strcmp(split, "-id") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion id... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-id") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    id[0] = split;
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

    id[0][strcspn(id[0], "\n")] = 0;

    if (a == 1)
    {
        for (int ss = 0; ss < variablecuenta; ss++)
        {

            if (id[0] == montar[ss].id)
            {

                FILE *arch1;
                arch1 = fopen(montar[ss].Disco, "r+b");
                if (arch1 == NULL)
                    exit(1);

                MBR master;
                int cont = 0;
                int existe = 1;
                printf(" Actualizando Archivo....\n");

                time_t t;

                t = time(NULL);

                fread(&master, sizeof(MBR), 1, arch1);

                while (!feof(arch1))
                {
                    if (montar[ss].name == master.mbr_partcion[0].part_name)
                    {
                        int pos = ftell(arch1) - sizeof(MBR);
                        strcpy(master.mbr_partcion[0].part_status, "0");

                        fseek(arch1, pos, SEEK_SET);
                        fwrite(&master, sizeof(MBR), 1, arch1);
                        printf("Se modifico los datos de la particion.\n");
                        printf("PARTICION DESACTIVADA.........\n");
                        existe = 1;

                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                        // Montado montar;

                        strcpy(montar[ss].Disco, "\0");
                        strcpy(montar[ss].name, "\0");
                        strcpy(montar[ss].id, "\0");

                        rmdir(id[0]);

                        break;
                    }
                    else
                    {
                        if (montar[ss].name == master.mbr_partcion[1].part_name)
                        {
                            int pos = ftell(arch1) - sizeof(MBR);
                            strcpy(master.mbr_partcion[1].part_status, "0");

                            fseek(arch1, pos, SEEK_SET);
                            fwrite(&master, sizeof(MBR), 1, arch1);
                            printf("Se modifico los datos de la particion.\n");
                            printf("PARTICION DESACTIVADA.........\n");
                            existe = 1;

                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                            // Montado montar;

                            strcpy(montar[ss].Disco, "\0");
                            strcpy(montar[ss].name, "\0");
                            strcpy(montar[ss].id, "\0");

                            rmdir(id[0]);

                            break;
                        }
                        else
                        {
                            if (montar[ss].name == master.mbr_partcion[2].part_name)
                            {
                                int pos = ftell(arch1) - sizeof(MBR);
                                strcpy(master.mbr_partcion[2].part_status, "0");

                                fseek(arch1, pos, SEEK_SET);
                                fwrite(&master, sizeof(MBR), 1, arch1);
                                printf("Se modifico los datos de la particion.\n");
                                printf("PARTICION DESACTIVADA.........\n");
                                existe = 1;

                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                // Montado montar;

                                strcpy(montar[ss].Disco, "\0");
                                strcpy(montar[ss].name, "\0");
                                strcpy(montar[ss].id, "\0");

                                rmdir(id[0]);

                                break;
                            }
                            else
                            {
                                if (montar[ss].name == master.mbr_partcion[3].part_name)
                                {
                                    int pos = ftell(arch1) - sizeof(MBR);
                                    strcpy(master.mbr_partcion[3].part_status, "0");

                                    fseek(arch1, pos, SEEK_SET);
                                    fwrite(&master, sizeof(MBR), 1, arch1);
                                    printf("Se modifico los datos de la particion.\n");
                                    printf("PARTICION DESACTIVADA.........\n");
                                    existe = 1;

                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                    // Montado montar;

                                    strcpy(montar[ss].Disco, "\0");
                                    strcpy(montar[ss].name, "\0");
                                    strcpy(montar[ss].id, "\0");

                                    rmdir(id[0]);

                                    break;
                                }
                                else
                                {
                                    printf("NO HAY MAS PARTICIONES\n");
                                    printf(" \n");
                                    printf("ERROR/Advertencia: NO SE PUEDE ENCONTRAR LA PARTCION\n");
                                    printf(" \n");
                                    break;
                                }
                            }
                        }
                    }

                    fread(&master, sizeof(MBR), 1, arch1);
                }

                fclose(arch1);
            }
            else
            {
                printf(" \n");
                printf("Buscando las particiones....\n");
                printf("Analizando las particiones....\n");
                printf(" \n");
            }
        }
    }
    else
    {
        printf(" \n");
        printf("ERROR: Falta de parametros obligatorios o exceso del mismo parametro\n");
        printf(" \n");
    }
}

void FDISK(char *x, char *y, char *z, char *v, char *ty, char *fi, char *del)
{
    printf("%s %s %s %s %s %s %s %s\n", "Esta prueba es de fdisk split:", x, y, z, v, ty, fi, del);
    char igual[] = "=";

    int s = 0;

    int u = 0;

    int a = 0;

    int w = 0;

    int ty1 = 0;

    int fi1 = 0;

    int del1 = 0;

    char *path[100];
    char *size[100];
    char *unit[100];
    char *name[100];
    char *type[100];
    char *fit[100];
    char *delet[100];

    char dd[5] = "W";
    char d1[5] = "K";
    char hu[5] = "P";
    char ru[5] = "0";
    char ru1[5] = "\0";

    // unit[0] = "m";

    // printf("%s %d %d %d %d\n", "Prueba de parametros:", a, s, u, w);

    char *split = strtok(x, igual);
    printf(" %s\n", split);

    for (size_t i = 0; i < strlen(split); ++i)
    {
        split[i] = tolower((unsigned char)split[i]);
        // printf(" %c\n", split[i]);
    }

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
        else if (strcmp(split, "-type") == 0)
        {
            ty1 = ty1 + 1;
            printf("Analizando comando, procesando instruccion type... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-type") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    type[0] = split;
                    break;
                }
            }
            break;
        }
        else if (strcmp(split, "-fit") == 0)
        {
            fi1 = fi1 + 1;
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
        else if (strcmp(split, "-delete") == 0)
        {
            del1 = del1 + 1;
            printf("Analizando comando, procesando instruccion delete... \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "-delete") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                    printf(" %s\n", split);
                }
                else
                {
                    printf(" %s\n", split);
                    delet[0] = split;
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

    for (size_t i = 0; i < strlen(divi); ++i)
    {
        divi[i] = tolower((unsigned char)divi[i]);
        // printf(" %c\n", split[i]);
    }

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
        else if (strcmp(divi, "-type") == 0)
        {
            ty1 = ty1 + 1;
            printf("Analizando comando, procesando instruccion type... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-type") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    type[0] = divi;
                    break;
                }
            }
            break;
        }
        else if (strcmp(divi, "-fit") == 0)
        {
            fi1 = fi1 + 1;
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
        else if (strcmp(divi, "-delete") == 0)
        {
            del1 = del1 + 1;
            printf("Analizando comando, procesando instruccion delete... \n");
            printf("Analizando..... \n");
            while (divi != NULL)
            {
                if (strcmp(divi, "-delete") == 0)
                {
                    printf("Analizando..... \n");
                    divi = strtok(NULL, " ");
                    printf(" %s\n", divi);
                }
                else
                {
                    printf(" %s\n", divi);
                    delet[0] = divi;
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

    for (size_t i = 0; i < strlen(separar); ++i)
    {
        separar[i] = tolower((unsigned char)separar[i]);
        // printf(" %c\n", split[i]);
    }

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
        else if (strcmp(separar, "-type") == 0)
        {
            ty1 = ty1 + 1;
            printf("Analizando comando, procesando instruccion type... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-type") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    type[0] = separar;
                    break;
                }
            }
            break;
        }
        else if (strcmp(separar, "-fit") == 0)
        {
            fi1 = fi1 + 1;
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
        else if (strcmp(separar, "-delete") == 0)
        {
            del1 = del1 + 1;
            printf("Analizando comando, procesando instruccion delete... \n");
            printf("Analizando..... \n");
            while (separar != NULL)
            {
                if (strcmp(separar, "-delete") == 0)
                {
                    printf("Analizando..... \n");
                    separar = strtok(NULL, " ");
                    printf(" %s\n", separar);
                }
                else
                {
                    printf(" %s\n", separar);
                    delet[0] = separar;
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

    for (size_t i = 0; i < strlen(otra); ++i)
    {
        otra[i] = tolower((unsigned char)otra[i]);
        // printf(" %c\n", split[i]);
    }

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
        else if (strcmp(otra, "-type") == 0)
        {
            ty1 = ty1 + 1;
            printf("Analizando comando, procesando instruccion type... \n");
            printf("Analizando..... \n");
            while (otra != NULL)
            {
                if (strcmp(otra, "-type") == 0)
                {
                    printf("Analizando..... \n");
                    otra = strtok(NULL, " ");
                    printf(" %s\n", otra);
                }
                else
                {
                    printf(" %s\n", otra);
                    type[0] = otra;
                    break;
                }
            }
            break;
        }
        else if (strcmp(otra, "-fit") == 0)
        {
            fi1 = fi1 + 1;
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
        else if (strcmp(otra, "-delete") == 0)
        {
            del1 = del1 + 1;
            printf("Analizando comando, procesando instruccion delete... \n");
            printf("Analizando..... \n");
            while (otra != NULL)
            {
                if (strcmp(otra, "-delete") == 0)
                {
                    printf("Analizando..... \n");
                    otra = strtok(NULL, " ");
                    printf(" %s\n", otra);
                }
                else
                {
                    printf(" %s\n", otra);
                    delet[0] = otra;
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

    char *mas = strtok(ty, igual);
    printf(" %s\n", mas);

    for (size_t i = 0; i < strlen(mas); ++i)
    {
        mas[i] = tolower((unsigned char)mas[i]);
        // printf(" %c\n", split[i]);
    }

    while (mas != NULL)
    {
        if (strcmp(mas, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (mas != NULL)
            {
                if (strcmp(mas, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    mas = strtok(NULL, " ");
                    printf(" %s", mas);
                }
                else
                {
                    printf(" %s", mas);
                    path[0] = mas;
                    break;
                }
            }
            break;
        }
        else if (strcmp(mas, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (mas != NULL)
            {
                if (strcmp(mas, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    mas = strtok(NULL, " ");
                    printf(" %s\n", mas);
                }
                else
                {
                    printf(" %s\n", mas);
                    size[0] = mas;
                    break;
                }
            }
            break;
        }
        else if (strcmp(mas, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (mas != NULL)
            {
                if (strcmp(mas, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    mas = strtok(NULL, " ");
                    printf(" %s\n", mas);
                }
                else
                {
                    printf(" %s\n", mas);
                    unit[0] = mas;
                    break;
                }
            }
            break;
        }
        else if (strcmp(mas, "-name") == 0)
        {
            w = w + 1;
            printf("Analizando comando, procesando instruccion name... \n");
            printf("Analizando..... \n");
            while (mas != NULL)
            {
                if (strcmp(mas, "-name") == 0)
                {
                    printf("Analizando..... \n");
                    mas = strtok(NULL, " ");
                    printf(" %s", mas);
                }
                else
                {
                    printf(" %s", mas);
                    name[0] = mas;
                    break;
                }
            }
            break;
        }
        else if (strcmp(mas, "-type") == 0)
        {
            ty1 = ty1 + 1;
            printf("Analizando comando, procesando instruccion type... \n");
            printf("Analizando..... \n");
            while (mas != NULL)
            {
                if (strcmp(mas, "-type") == 0)
                {
                    printf("Analizando..... \n");
                    mas = strtok(NULL, " ");
                    printf(" %s\n", mas);
                }
                else
                {
                    printf(" %s\n", mas);
                    type[0] = mas;
                    break;
                }
            }
            break;
        }
        else if (strcmp(mas, "-fit") == 0)
        {
            fi1 = fi1 + 1;
            printf("Analizando comando, procesando instruccion fit... \n");
            printf("Analizando..... \n");
            while (mas != NULL)
            {
                if (strcmp(mas, "-fit") == 0)
                {
                    printf("Analizando..... \n");
                    mas = strtok(NULL, " ");
                    printf(" %s\n", mas);
                }
                else
                {
                    printf(" %s\n", mas);
                    fit[0] = mas;
                    break;
                }
            }
            break;
        }
        else if (strcmp(mas, "-delete") == 0)
        {
            del1 = del1 + 1;
            printf("Analizando comando, procesando instruccion delete... \n");
            printf("Analizando..... \n");
            while (mas != NULL)
            {
                if (strcmp(mas, "-delete") == 0)
                {
                    printf("Analizando..... \n");
                    mas = strtok(NULL, " ");
                    printf(" %s\n", mas);
                }
                else
                {
                    printf(" %s\n", mas);
                    delet[0] = mas;
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

    char *duo = strtok(fi, igual);
    printf(" %s\n", duo);

    for (size_t i = 0; i < strlen(duo); ++i)
    {
        duo[i] = tolower((unsigned char)duo[i]);
        // printf(" %c\n", split[i]);
    }

    while (duo != NULL)
    {
        if (strcmp(duo, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (duo != NULL)
            {
                if (strcmp(duo, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    duo = strtok(NULL, " ");
                    printf(" %s", duo);
                }
                else
                {
                    printf(" %s", duo);
                    path[0] = duo;
                    break;
                }
            }
            break;
        }
        else if (strcmp(duo, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (duo != NULL)
            {
                if (strcmp(duo, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    duo = strtok(NULL, " ");
                    printf(" %s\n", duo);
                }
                else
                {
                    printf(" %s\n", duo);
                    size[0] = duo;
                    break;
                }
            }
            break;
        }
        else if (strcmp(duo, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (duo != NULL)
            {
                if (strcmp(duo, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    duo = strtok(NULL, " ");
                    printf(" %s\n", duo);
                }
                else
                {
                    printf(" %s\n", duo);
                    unit[0] = duo;
                    break;
                }
            }
            break;
        }
        else if (strcmp(duo, "-name") == 0)
        {
            w = w + 1;
            printf("Analizando comando, procesando instruccion name... \n");
            printf("Analizando..... \n");
            while (duo != NULL)
            {
                if (strcmp(duo, "-name") == 0)
                {
                    printf("Analizando..... \n");
                    duo = strtok(NULL, " ");
                    printf(" %s", duo);
                }
                else
                {
                    printf(" %s", duo);
                    name[0] = duo;
                    break;
                }
            }
            break;
        }
        else if (strcmp(duo, "-type") == 0)
        {
            ty1 = ty1 + 1;
            printf("Analizando comando, procesando instruccion type... \n");
            printf("Analizando..... \n");
            while (duo != NULL)
            {
                if (strcmp(duo, "-type") == 0)
                {
                    printf("Analizando..... \n");
                    duo = strtok(NULL, " ");
                    printf(" %s\n", duo);
                }
                else
                {
                    printf(" %s\n", duo);
                    type[0] = duo;
                    break;
                }
            }
            break;
        }
        else if (strcmp(duo, "-fit") == 0)
        {
            fi1 = fi1 + 1;
            printf("Analizando comando, procesando instruccion fit... \n");
            printf("Analizando..... \n");
            while (duo != NULL)
            {
                if (strcmp(duo, "-fit") == 0)
                {
                    printf("Analizando..... \n");
                    duo = strtok(NULL, " ");
                    printf(" %s\n", duo);
                }
                else
                {
                    printf(" %s\n", duo);
                    fit[0] = duo;
                    break;
                }
            }
            break;
        }
        else if (strcmp(duo, "-delete") == 0)
        {
            del1 = del1 + 1;
            printf("Analizando comando, procesando instruccion delete... \n");
            printf("Analizando..... \n");
            while (duo != NULL)
            {
                if (strcmp(duo, "-delete") == 0)
                {
                    printf("Analizando..... \n");
                    duo = strtok(NULL, " ");
                    printf(" %s\n", duo);
                }
                else
                {
                    printf(" %s\n", duo);
                    delet[0] = duo;
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

    char *elim = strtok(del, igual);
    printf(" %s\n", elim);

    for (size_t i = 0; i < strlen(elim); ++i)
    {
        elim[i] = tolower((unsigned char)elim[i]);
        // printf(" %c\n", split[i]);
    }

    while (elim != NULL)
    {
        if (strcmp(elim, "-path") == 0)
        {
            a = a + 1;
            printf("Analizando comando, procesando instruccion path... \n");
            printf("Analizando..... \n");
            while (elim != NULL)
            {
                if (strcmp(elim, "-path") == 0)
                {
                    printf("Analizando..... \n");
                    elim = strtok(NULL, " ");
                    printf(" %s", elim);
                }
                else
                {
                    printf(" %s", elim);
                    path[0] = elim;
                    break;
                }
            }
            break;
        }
        else if (strcmp(elim, "-size") == 0)
        {
            s = s + 1;
            printf("Analizando comando, procesando instruccion size... \n");
            printf("Analizando..... \n");
            while (elim != NULL)
            {
                if (strcmp(elim, "-size") == 0)
                {
                    printf("Analizando..... \n");
                    elim = strtok(NULL, " ");
                    printf(" %s\n", elim);
                }
                else
                {
                    printf(" %s\n", elim);
                    size[0] = elim;
                    break;
                }
            }
            break;
        }
        else if (strcmp(elim, "-unit") == 0)
        {
            u = u + 1;
            printf("Analizando comando, procesando instruccion unit... \n");
            printf("Analizando..... \n");
            while (elim != NULL)
            {
                if (strcmp(elim, "-unit") == 0)
                {
                    printf("Analizando..... \n");
                    elim = strtok(NULL, " ");
                    printf(" %s\n", elim);
                }
                else
                {
                    printf(" %s\n", elim);
                    unit[0] = elim;
                    break;
                }
            }
            break;
        }
        else if (strcmp(elim, "-name") == 0)
        {
            w = w + 1;
            printf("Analizando comando, procesando instruccion name... \n");
            printf("Analizando..... \n");
            while (elim != NULL)
            {
                if (strcmp(elim, "-name") == 0)
                {
                    printf("Analizando..... \n");
                    elim = strtok(NULL, " ");
                    printf(" %s", elim);
                }
                else
                {
                    printf(" %s", elim);
                    name[0] = elim;
                    break;
                }
            }
            break;
        }
        else if (strcmp(elim, "-type") == 0)
        {
            ty1 = ty1 + 1;
            printf("Analizando comando, procesando instruccion type... \n");
            printf("Analizando..... \n");
            while (elim != NULL)
            {
                if (strcmp(elim, "-type") == 0)
                {
                    printf("Analizando..... \n");
                    elim = strtok(NULL, " ");
                    printf(" %s\n", elim);
                }
                else
                {
                    printf(" %s\n", elim);
                    type[0] = elim;
                    break;
                }
            }
            break;
        }
        else if (strcmp(elim, "-fit") == 0)
        {
            fi1 = fi1 + 1;
            printf("Analizando comando, procesando instruccion fit... \n");
            printf("Analizando..... \n");
            while (elim != NULL)
            {
                if (strcmp(elim, "-fit") == 0)
                {
                    printf("Analizando..... \n");
                    elim = strtok(NULL, " ");
                    printf(" %s\n", elim);
                }
                else
                {
                    printf(" %s\n", elim);
                    fit[0] = elim;
                    break;
                }
            }
            break;
        }
        else if (strcmp(elim, "-delete") == 0)
        {
            del1 = del1 + 1;
            printf("Analizando comando, procesando instruccion delete... \n");
            printf("Analizando..... \n");
            while (elim != NULL)
            {
                if (strcmp(elim, "-delete") == 0)
                {
                    printf("Analizando..... \n");
                    elim = strtok(NULL, " ");
                    printf(" %s\n", elim);
                }
                else
                {
                    printf(" %s\n", elim);
                    delet[0] = elim;
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

    if (a == 1 && s == 1 && w == 1 && (u == 0 || u == 1) && (ty1 == 0 || ty1 == 1) && (fi1 == 0 || fi1 == 1) && (del1 == 0 || del1 == 1))
    {

        if (strtol(size[0], NULL, 10) <= 0)
        {
            printf(" \n");
            printf("ERROR NO SE PUEDE LLEVAR A CABO DICHA OPERACION\n");
            printf(" \n");
        }
        else
        {
            if (fi1 == 0)
            {
                printf("Valor Fit establecido automaticamente\n");
                fit[0] = dd;
            }
            else
            {
                printf("Print Encontrado\n");
            }
            if (u == 0)
            {
                printf("Valor Unit establecido automaticamente\n");
                unit[0] = d1;
            }
            else
            {
                printf("Print Encontrado\n");
            }
            if (ty1 == 0)
            {
                printf("Valor Type establecido automaticamente\n");
                type[0] = hu;
            }
            else
            {
                printf("Print Encontrado\n");
            }

            path[0][strcspn(path[0], "\n")] = 0;
            fit[0][strcspn(fit[0], "\n")] = 0;
            delet[0][strcspn(delet[0], "\n")] = 0;
            size[0][strcspn(size[0], "\n")] = 0;
            name[0][strcspn(name[0], "\n")] = 0;

            if ((strcmp(fit[0], "B") == 0) || (strcmp(fit[0], "F") == 0) || (strcmp(fit[0], "W") == 0) || (strcmp(fit[0], "BF") == 0) || (strcmp(fit[0], "FF") == 0) || (strcmp(fit[0], "WF") == 0))
            {
                type[0][strcspn(type[0], "\n")] = 0;

                if ((strcmp(type[0], "P") == 0) || (strcmp(type[0], "E") == 0) || (strcmp(type[0], "L") == 0))
                {
                    if (del1 == 0)
                    {
                        unit[0][strcspn(unit[0], "\n")] = 0;

                        if ((strcmp(unit[0], "m") == 0) || (strcmp(unit[0], "M") == 0))
                        {
                            FILE *arch1;
                            arch1 = fopen(path[0], "r+b");
                            if (arch1 == NULL)
                                exit(1);

                            MBR master;
                            int cont = 0;
                            int existe = 1;
                            printf(" Actualizando Archivo....\n");

                            time_t t;

                            t = time(NULL);

                            fread(&master, sizeof(MBR), 1, arch1);

                            while (!feof(arch1))
                            {
                                if (master.mbr_partcion[0].part_start == -1)
                                {
                                    printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                    printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                    printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                    printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                    printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                    if (strtol(size[0], NULL, 10) <= master.mbr_tamano)
                                    {
                                        name[0][strcspn(name[0], "\n")] = 0;

                                        if (name[0] != master.mbr_partcion[0].part_name)
                                        {

                                            int pos = ftell(arch1) - sizeof(MBR);
                                            strcpy(master.mbr_partcion[0].part_type, type[0]);
                                            strcpy(master.mbr_partcion[0].part_fit, fit[0]);
                                            strcpy(master.mbr_partcion[0].part_name, name[0]);
                                            master.mbr_partcion[0].part_start = pos;
                                            strcpy(master.mbr_partcion[0].part_status, ru);
                                            master.mbr_partcion[0].part_size = strtol(size[0], NULL, 10) * 1024 * 1024;

                                            fseek(arch1, pos, SEEK_SET);
                                            fwrite(&master, sizeof(MBR), 1, arch1);
                                            printf("Se modifico los datos de la particion.\n");
                                            existe = 1;

                                            printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                            break;
                                        }
                                        else
                                        {
                                            printf("NO ENTRO A LA MODIFICACION\n");
                                            printf(" \n");
                                            printf("Particion Repetida\n");
                                            printf(" \n");
                                            existe = 0;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        printf("NO ENTRO A LA MODIFICACION\n");
                                        printf(" \n");
                                        printf("ERROR/Advertencia: Particion muy grande\n");
                                        printf(" \n");
                                        break;
                                    }
                                }
                                else
                                {
                                    if (master.mbr_partcion[1].part_start == -1)
                                    {
                                        printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                        if (strtol(size[0], NULL, 10) <= master.mbr_tamano - master.mbr_partcion[0].part_size)
                                        {
                                            name[0][strcspn(name[0], "\n")] = 0;

                                            if (name[0] != master.mbr_partcion[1].part_name)
                                            {
                                                int pos = ftell(arch1) - sizeof(MBR);
                                                strcpy(master.mbr_partcion[1].part_type, type[0]);
                                                strcpy(master.mbr_partcion[1].part_fit, fit[0]);
                                                strcpy(master.mbr_partcion[1].part_name, name[0]);
                                                master.mbr_partcion[1].part_start = pos;
                                                strcpy(master.mbr_partcion[1].part_status, ru);
                                                master.mbr_partcion[1].part_size = strtol(size[0], NULL, 10) * 1024 * 1024;

                                                fseek(arch1, pos, SEEK_SET);
                                                fwrite(&master, sizeof(MBR), 1, arch1);
                                                printf("Se modifico los datos de la particion.\n");
                                                existe = 1;

                                                printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                                break;
                                            }
                                            else
                                            {
                                                printf("NO ENTRO A LA MODIFICACION\n");
                                                printf(" \n");
                                                printf("Particion Repetida\n");
                                                printf(" \n");
                                                existe = 0;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            printf("NO ENTRO A LA MODIFICACION\n");
                                            printf(" \n");
                                            printf("ERROR/Advertencia: Particion muy grande\n");
                                            printf(" \n");
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if (master.mbr_partcion[2].part_start == -1)
                                        {
                                            printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                            if (strtol(size[0], NULL, 10) <= master.mbr_tamano - master.mbr_partcion[0].part_size - master.mbr_partcion[1].part_size)
                                            {
                                                name[0][strcspn(name[0], "\n")] = 0;

                                                if (name[0] != master.mbr_partcion[2].part_name)
                                                {
                                                    int pos = ftell(arch1) - sizeof(MBR);
                                                    strcpy(master.mbr_partcion[2].part_type, type[0]);
                                                    strcpy(master.mbr_partcion[2].part_fit, fit[0]);
                                                    strcpy(master.mbr_partcion[2].part_name, name[0]);
                                                    strcpy(master.mbr_partcion[2].part_status, ru);
                                                    master.mbr_partcion[2].part_start = pos;
                                                    master.mbr_partcion[2].part_size = strtol(size[0], NULL, 10) * 1024 * 1024;

                                                    fseek(arch1, pos, SEEK_SET);
                                                    fwrite(&master, sizeof(MBR), 1, arch1);
                                                    printf("Se modifico los datos de la particion.\n");
                                                    existe = 1;

                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);
                                                    break;
                                                }
                                                else
                                                {
                                                    printf("NO ENTRO A LA MODIFICACION\n");
                                                    printf(" \n");
                                                    printf("Particion Repetida\n");
                                                    printf(" \n");
                                                    existe = 0;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                printf("NO ENTRO A LA MODIFICACION\n");
                                                printf(" \n");
                                                printf("ERROR/Advertencia: Particion muy grande\n");
                                                printf(" \n");
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            if (master.mbr_partcion[3].part_start == -1)
                                            {
                                                printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                if (strtol(size[0], NULL, 10) <= master.mbr_tamano - master.mbr_partcion[0].part_size - master.mbr_partcion[1].part_size - master.mbr_partcion[2].part_size)
                                                {
                                                    name[0][strcspn(name[0], "\n")] = 0;

                                                    if (name[0] != master.mbr_partcion[3].part_name)
                                                    {
                                                        int pos = ftell(arch1) - sizeof(MBR);
                                                        strcpy(master.mbr_partcion[3].part_type, type[0]);
                                                        strcpy(master.mbr_partcion[3].part_fit, fit[0]);
                                                        strcpy(master.mbr_partcion[3].part_name, name[0]);
                                                        master.mbr_partcion[3].part_start = pos;
                                                        strcpy(master.mbr_partcion[3].part_status, ru);
                                                        master.mbr_partcion[3].part_size = strtol(size[0], NULL, 10) * 1024 * 1024;

                                                        fseek(arch1, pos, SEEK_SET);
                                                        fwrite(&master, sizeof(MBR), 1, arch1);
                                                        printf("Se modifico los datos de la particion.\n");
                                                        existe = 1;

                                                        printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                        printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                        printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                        printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                        printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        printf("NO ENTRO A LA MODIFICACION\n");
                                                        printf(" \n");
                                                        printf("Particion Repetida\n");
                                                        printf(" \n");
                                                        existe = 0;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    printf("NO ENTRO A LA MODIFICACION\n");
                                                    printf(" \n");
                                                    printf("ERROR/Advertencia: Particion muy grande\n");
                                                    printf(" \n");
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                printf("NO HAY MAS PARTICIONES\n");
                                                printf(" \n");
                                                printf("ERROR/Advertencia: NO SE PUEDEN HACER MAS PARTICIONES\n");
                                                printf(" \n");
                                                break;
                                            }
                                        }
                                    }
                                }

                                fread(&master, sizeof(MBR), 1, arch1);
                            }

                            if (existe == 0)
                                printf("Ya existe la particion\n");
                            fclose(arch1);
                        }
                        else if ((strcmp(unit[0], "b") == 0) || (strcmp(unit[0], "B") == 0))
                        {
                            FILE *arch1;
                            arch1 = fopen(path[0], "r+b");
                            if (arch1 == NULL)
                                exit(1);

                            MBR master;
                            int cont = 0;
                            int existe = 1;
                            printf(" Actualizando Archivo....\n");

                            time_t t;

                            t = time(NULL);

                            fread(&master, sizeof(MBR), 1, arch1);

                            while (!feof(arch1))
                            {
                                if (master.mbr_partcion[0].part_start == -1)
                                {
                                    printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                    printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                    printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                    printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                    printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                    if (strtol(size[0], NULL, 10) <= master.mbr_tamano)
                                    {
                                        name[0][strcspn(name[0], "\n")] = 0;

                                        if (name[0] != master.mbr_partcion[0].part_name)
                                        {
                                            int pos = ftell(arch1) - sizeof(MBR);
                                            strcpy(master.mbr_partcion[0].part_type, type[0]);
                                            strcpy(master.mbr_partcion[0].part_fit, fit[0]);
                                            strcpy(master.mbr_partcion[0].part_name, name[0]);
                                            master.mbr_partcion[0].part_start = pos;
                                            strcpy(master.mbr_partcion[0].part_status, ru);
                                            master.mbr_partcion[0].part_size = strtol(size[0], NULL, 10);

                                            fseek(arch1, pos, SEEK_SET);
                                            fwrite(&master, sizeof(MBR), 1, arch1);
                                            printf("Se modifico los datos de la particion.\n");
                                            existe = 1;

                                            printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                            break;
                                        }
                                        else
                                        {
                                            printf("NO ENTRO A LA MODIFICACION\n");
                                            printf(" \n");
                                            printf("Particion Repetida\n");
                                            printf(" \n");
                                            existe = 0;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        printf("NO ENTRO A LA MODIFICACION\n");
                                        printf(" \n");
                                        printf("ERROR/Advertencia: Particion muy grande\n");
                                        printf(" \n");
                                        break;
                                    }
                                }
                                else
                                {
                                    if (master.mbr_partcion[1].part_start == -1)
                                    {
                                        printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                        if (strtol(size[0], NULL, 10) <= master.mbr_tamano - master.mbr_partcion[0].part_size)
                                        {
                                            name[0][strcspn(name[0], "\n")] = 0;

                                            if (name[0] != master.mbr_partcion[1].part_name)
                                            {
                                                int pos = ftell(arch1) - sizeof(MBR);
                                                strcpy(master.mbr_partcion[1].part_type, type[0]);
                                                strcpy(master.mbr_partcion[1].part_fit, fit[0]);
                                                strcpy(master.mbr_partcion[1].part_name, name[0]);
                                                master.mbr_partcion[1].part_start = pos;
                                                strcpy(master.mbr_partcion[1].part_status, ru);
                                                master.mbr_partcion[1].part_size = strtol(size[0], NULL, 10);

                                                fseek(arch1, pos, SEEK_SET);
                                                fwrite(&master, sizeof(MBR), 1, arch1);
                                                printf("Se modifico los datos de la particion.\n");
                                                existe = 1;

                                                printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                                break;
                                            }
                                            else
                                            {
                                                printf("NO ENTRO A LA MODIFICACION\n");
                                                printf(" \n");
                                                printf("Particion Repetida\n");
                                                printf(" \n");
                                                existe = 0;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            printf("NO ENTRO A LA MODIFICACION\n");
                                            printf(" \n");
                                            printf("ERROR/Advertencia: Particion muy grande\n");
                                            printf(" \n");
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if (master.mbr_partcion[2].part_start == -1)
                                        {
                                            printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                            if (strtol(size[0], NULL, 10) <= master.mbr_tamano - master.mbr_partcion[0].part_size - master.mbr_partcion[1].part_size)
                                            {
                                                name[0][strcspn(name[0], "\n")] = 0;

                                                if (name[0] != master.mbr_partcion[2].part_name)
                                                {
                                                    int pos = ftell(arch1) - sizeof(MBR);
                                                    strcpy(master.mbr_partcion[2].part_type, type[0]);
                                                    strcpy(master.mbr_partcion[2].part_fit, fit[0]);
                                                    strcpy(master.mbr_partcion[2].part_name, name[0]);
                                                    master.mbr_partcion[2].part_start = pos;
                                                    strcpy(master.mbr_partcion[2].part_status, ru);
                                                    master.mbr_partcion[2].part_size = strtol(size[0], NULL, 10);

                                                    fseek(arch1, pos, SEEK_SET);
                                                    fwrite(&master, sizeof(MBR), 1, arch1);
                                                    printf("Se modifico los datos de la particion.\n");
                                                    existe = 1;

                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);
                                                    break;
                                                }
                                                else
                                                {
                                                    printf("NO ENTRO A LA MODIFICACION\n");
                                                    printf(" \n");
                                                    printf("Particion Repetida\n");
                                                    printf(" \n");
                                                    existe = 0;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                printf("NO ENTRO A LA MODIFICACION\n");
                                                printf(" \n");
                                                printf("ERROR/Advertencia: Particion muy grande\n");
                                                printf(" \n");
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            if (master.mbr_partcion[3].part_start == -1)
                                            {
                                                printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                if (strtol(size[0], NULL, 10) <= master.mbr_tamano - master.mbr_partcion[0].part_size - master.mbr_partcion[1].part_size - master.mbr_partcion[2].part_size)
                                                {
                                                    name[0][strcspn(name[0], "\n")] = 0;

                                                    if (name[0] != master.mbr_partcion[3].part_name)
                                                    {
                                                        int pos = ftell(arch1) - sizeof(MBR);
                                                        strcpy(master.mbr_partcion[3].part_type, type[0]);
                                                        strcpy(master.mbr_partcion[3].part_fit, fit[0]);
                                                        strcpy(master.mbr_partcion[3].part_name, name[0]);
                                                        master.mbr_partcion[3].part_start = pos;
                                                        strcpy(master.mbr_partcion[3].part_status, ru);
                                                        master.mbr_partcion[3].part_size = strtol(size[0], NULL, 10);

                                                        fseek(arch1, pos, SEEK_SET);
                                                        fwrite(&master, sizeof(MBR), 1, arch1);
                                                        printf("Se modifico los datos de la particion.\n");
                                                        existe = 1;

                                                        printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                        printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                        printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                        printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                        printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        printf("NO ENTRO A LA MODIFICACION\n");
                                                        printf(" \n");
                                                        printf("Particion Repetida\n");
                                                        printf(" \n");
                                                        existe = 0;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    printf("NO ENTRO A LA MODIFICACION\n");
                                                    printf(" \n");
                                                    printf("ERROR/Advertencia: Particion muy grande\n");
                                                    printf(" \n");
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                printf("NO HAY MAS PARTICIONES\n");
                                                printf(" \n");
                                                printf("ERROR/Advertencia: NO SE PUEDEN HACER MAS PARTICIONES\n");
                                                printf(" \n");
                                                break;
                                            }
                                        }
                                    }
                                }

                                fread(&master, sizeof(MBR), 1, arch1);
                            }

                            if (existe == 0)
                                printf("Ya existe la particion\n");
                            fclose(arch1);
                        }
                        else if ((strcmp(unit[0], "k") == 0) || (strcmp(unit[0], "K") == 0))
                        {
                            FILE *arch1;
                            arch1 = fopen(path[0], "r+b");
                            if (arch1 == NULL)
                                exit(1);

                            MBR master;
                            int cont = 0;
                            int existe = 1;
                            printf(" Actualizando Archivo....\n");

                            time_t t;

                            t = time(NULL);

                            fread(&master, sizeof(MBR), 1, arch1);

                            while (!feof(arch1))
                            {
                                if (master.mbr_partcion[0].part_start == -1)
                                {
                                    printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                    printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                    printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                    printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                    printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                    if (strtol(size[0], NULL, 10) <= master.mbr_tamano)
                                    {
                                        name[0][strcspn(name[0], "\n")] = 0;

                                        if (name[0] != master.mbr_partcion[0].part_name)
                                        {
                                            int pos = ftell(arch1) - sizeof(MBR);
                                            strcpy(master.mbr_partcion[0].part_type, type[0]);
                                            strcpy(master.mbr_partcion[0].part_fit, fit[0]);
                                            strcpy(master.mbr_partcion[0].part_name, name[0]);
                                            master.mbr_partcion[0].part_start = pos;
                                            strcpy(master.mbr_partcion[0].part_status, ru);
                                            master.mbr_partcion[0].part_size = strtol(size[0], NULL, 10) * 1024;

                                            fseek(arch1, pos, SEEK_SET);
                                            fwrite(&master, sizeof(MBR), 1, arch1);
                                            printf("Se modifico los datos de la particion.\n");
                                            existe = 1;

                                            printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                            break;
                                        }
                                        else
                                        {
                                            printf("NO ENTRO A LA MODIFICACION\n");
                                            printf(" \n");
                                            printf("Particion Repetida\n");
                                            printf(" \n");
                                            existe = 0;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        printf("NO ENTRO A LA MODIFICACION\n");
                                        printf(" \n");
                                        printf("ERROR/Advertencia: Particion muy grande\n");
                                        printf(" \n");
                                        break;
                                    }
                                }
                                else
                                {
                                    if (master.mbr_partcion[1].part_start == -1)
                                    {
                                        printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                        if (strtol(size[0], NULL, 10) <= master.mbr_tamano - master.mbr_partcion[0].part_size)
                                        {
                                            name[0][strcspn(name[0], "\n")] = 0;

                                            if (name[0] != master.mbr_partcion[1].part_name)
                                            {
                                                int pos = ftell(arch1) - sizeof(MBR);
                                                strcpy(master.mbr_partcion[1].part_type, type[0]);
                                                strcpy(master.mbr_partcion[1].part_fit, fit[0]);
                                                strcpy(master.mbr_partcion[1].part_name, name[0]);
                                                master.mbr_partcion[1].part_start = pos;
                                                strcpy(master.mbr_partcion[1].part_status, ru);
                                                master.mbr_partcion[1].part_size = strtol(size[0], NULL, 10) * 1024;

                                                fseek(arch1, pos, SEEK_SET);
                                                fwrite(&master, sizeof(MBR), 1, arch1);
                                                printf("Se modifico los datos de la particion.\n");
                                                existe = 1;

                                                printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                                break;
                                            }
                                            else
                                            {
                                                printf("NO ENTRO A LA MODIFICACION\n");
                                                printf(" \n");
                                                printf("Particion Repetida\n");
                                                printf(" \n");
                                                existe = 0;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            printf("NO ENTRO A LA MODIFICACION\n");
                                            printf(" \n");
                                            printf("ERROR/Advertencia: Particion muy grande\n");
                                            printf(" \n");
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if (master.mbr_partcion[2].part_start == -1)
                                        {
                                            printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                            if (strtol(size[0], NULL, 10) <= master.mbr_tamano - master.mbr_partcion[0].part_size - master.mbr_partcion[1].part_size)
                                            {
                                                name[0][strcspn(name[0], "\n")] = 0;

                                                if (name[0] != master.mbr_partcion[2].part_name)
                                                {
                                                    int pos = ftell(arch1) - sizeof(MBR);
                                                    strcpy(master.mbr_partcion[2].part_type, type[0]);
                                                    strcpy(master.mbr_partcion[2].part_fit, fit[0]);
                                                    strcpy(master.mbr_partcion[2].part_name, name[0]);
                                                    master.mbr_partcion[2].part_start = pos;
                                                    strcpy(master.mbr_partcion[2].part_status, ru);
                                                    master.mbr_partcion[2].part_size = strtol(size[0], NULL, 10) * 1024;

                                                    fseek(arch1, pos, SEEK_SET);
                                                    fwrite(&master, sizeof(MBR), 1, arch1);
                                                    printf("Se modifico los datos de la particion.\n");
                                                    existe = 1;

                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);
                                                    break;
                                                }
                                                else
                                                {
                                                    printf("NO ENTRO A LA MODIFICACION\n");
                                                    printf(" \n");
                                                    printf("Particion Repetida\n");
                                                    printf(" \n");
                                                    existe = 0;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                printf("NO ENTRO A LA MODIFICACION\n");
                                                printf(" \n");
                                                printf("ERROR/Advertencia: Particion muy grande\n");
                                                printf(" \n");
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            if (master.mbr_partcion[3].part_start == -1)
                                            {
                                                printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                if (strtol(size[0], NULL, 10) <= master.mbr_tamano - master.mbr_partcion[0].part_size - master.mbr_partcion[1].part_size - master.mbr_partcion[2].part_size)
                                                {
                                                    name[0][strcspn(name[0], "\n")] = 0;

                                                    if (name[0] != master.mbr_partcion[3].part_name)
                                                    {
                                                        int pos = ftell(arch1) - sizeof(MBR);
                                                        strcpy(master.mbr_partcion[3].part_type, type[0]);
                                                        strcpy(master.mbr_partcion[3].part_fit, fit[0]);
                                                        strcpy(master.mbr_partcion[3].part_name, name[0]);
                                                        master.mbr_partcion[3].part_start = pos;
                                                        strcpy(master.mbr_partcion[3].part_status, ru);
                                                        master.mbr_partcion[3].part_size = strtol(size[0], NULL, 10) * 1024;

                                                        fseek(arch1, pos, SEEK_SET);
                                                        fwrite(&master, sizeof(MBR), 1, arch1);
                                                        printf("Se modifico los datos de la particion.\n");
                                                        existe = 1;

                                                        printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                        printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                        printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                        printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                        printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        printf("NO ENTRO A LA MODIFICACION\n");
                                                        printf(" \n");
                                                        printf("Particion Repetida\n");
                                                        printf(" \n");
                                                        existe = 0;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    printf("NO ENTRO A LA MODIFICACION\n");
                                                    printf(" \n");
                                                    printf("ERROR/Advertencia: Particion muy grande\n");
                                                    printf(" \n");
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                printf("NO HAY MAS PARTICIONES\n");
                                                printf(" \n");
                                                printf("ERROR/Advertencia: NO SE PUEDEN HACER MAS PARTICIONES\n");
                                                printf(" \n");
                                                break;
                                            }
                                        }
                                    }
                                }

                                fread(&master, sizeof(MBR), 1, arch1);
                            }

                            if (existe == 0)
                                printf("Ya existe la particion\n");
                            fclose(arch1);
                        }
                        else
                        {
                            printf("NO ENTRO AL UNIT\n");
                            printf(" \n");
                            printf("ERROR/Advertencia: valor inexistente u variable nula\n");
                            printf(" \n");
                        }
                    }
                    else if (del1 == 1)
                    {
                        if (strcmp(delet[0], "FAST") == 0)
                        {
                            unit[0][strcspn(unit[0], "\n")] = 0;

                            if ((strcmp(unit[0], "m") == 0) || (strcmp(unit[0], "M") == 0))
                            {
                                FILE *arch1;
                                arch1 = fopen(path[0], "r+b");
                                if (arch1 == NULL)
                                    exit(1);

                                MBR master;
                                int cont = 0;
                                int existe = 1;
                                printf(" Actualizando Archivo....\n");

                                time_t t;

                                t = time(NULL);

                                fread(&master, sizeof(MBR), 1, arch1);

                                while (!feof(arch1))
                                {
                                    name[0][strcspn(name[0], "\n")] = 0;

                                    if (name[0] == master.mbr_partcion[0].part_name)
                                    {
                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        delet[0] = ru;

                                        strcpy(master.mbr_partcion[0].part_type, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_fit, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_name, delet[0]);
                                        master.mbr_partcion[0].part_start = 0;
                                        master.mbr_partcion[0].part_size = 0;
                                        int pos = ftell(arch1) - sizeof(MBR);

                                        fseek(arch1, pos, SEEK_SET);
                                        fwrite(&master, sizeof(MBR), 1, arch1);
                                        printf("Se modifico los datos de la particion.\n");
                                        existe = 1;

                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        break;
                                    }
                                    else
                                    {
                                        if (name[0] == master.mbr_partcion[1].part_name)
                                        {
                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            delet[0] = ru;

                                            strcpy(master.mbr_partcion[1].part_type, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_fit, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_name, delet[0]);
                                            master.mbr_partcion[1].part_start = 0;
                                            master.mbr_partcion[1].part_size = 0;
                                            int pos = ftell(arch1) - sizeof(MBR);

                                            fseek(arch1, pos, SEEK_SET);
                                            fwrite(&master, sizeof(MBR), 1, arch1);
                                            printf("Se modifico los datos de la particion.\n");
                                            existe = 1;

                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            break;
                                        }
                                        else
                                        {
                                            if (name[0] == master.mbr_partcion[2].part_name)
                                            {
                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                delet[0] = ru;

                                                strcpy(master.mbr_partcion[2].part_type, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_fit, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_name, delet[0]);
                                                master.mbr_partcion[2].part_start = 0;
                                                master.mbr_partcion[2].part_size = 0;
                                                int pos = ftell(arch1) - sizeof(MBR);

                                                fseek(arch1, pos, SEEK_SET);
                                                fwrite(&master, sizeof(MBR), 1, arch1);
                                                printf("Se modifico los datos de la particion.\n");
                                                existe = 1;

                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                break;
                                            }
                                            else
                                            {
                                                if (name[0] == master.mbr_partcion[3].part_name)
                                                {
                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    delet[0] = ru;

                                                    strcpy(master.mbr_partcion[3].part_type, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_fit, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_name, delet[0]);
                                                    master.mbr_partcion[3].part_start = 0;
                                                    master.mbr_partcion[3].part_size = 0;
                                                    int pos = ftell(arch1) - sizeof(MBR);

                                                    fseek(arch1, pos, SEEK_SET);
                                                    fwrite(&master, sizeof(MBR), 1, arch1);
                                                    printf("Se modifico los datos de la particion.\n");
                                                    existe = 1;

                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    break;
                                                }
                                                else
                                                {
                                                    printf("NO HAY MAS PARTICIONES\n");
                                                    printf(" \n");
                                                    printf("ERROR/Advertencia: No se encontro Particion\n");
                                                    printf(" \n");
                                                    break;
                                                }
                                            }
                                        }
                                    }

                                    fread(&master, sizeof(MBR), 1, arch1);
                                }

                                if (existe == 0)
                                    printf("Ya existe la particion\n");
                                fclose(arch1);
                            }
                            else if ((strcmp(unit[0], "b") == 0) || (strcmp(unit[0], "B") == 0))
                            {
                                FILE *arch1;
                                arch1 = fopen(path[0], "r+b");
                                if (arch1 == NULL)
                                    exit(1);

                                MBR master;
                                int cont = 0;
                                int existe = 1;
                                printf(" Actualizando Archivo....\n");

                                time_t t;

                                t = time(NULL);

                                fread(&master, sizeof(MBR), 1, arch1);

                                while (!feof(arch1))
                                {
                                    name[0][strcspn(name[0], "\n")] = 0;

                                    if (name[0] == master.mbr_partcion[0].part_name)
                                    {
                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        delet[0] = ru;

                                        strcpy(master.mbr_partcion[0].part_type, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_fit, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_name, delet[0]);
                                        master.mbr_partcion[0].part_start = 0;
                                        master.mbr_partcion[0].part_size = 0;
                                        int pos = ftell(arch1) - sizeof(MBR);

                                        fseek(arch1, pos, SEEK_SET);
                                        fwrite(&master, sizeof(MBR), 1, arch1);
                                        printf("Se modifico los datos de la particion.\n");
                                        existe = 1;

                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        break;
                                    }
                                    else
                                    {
                                        if (name[0] == master.mbr_partcion[1].part_name)
                                        {
                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            delet[0] = ru;

                                            strcpy(master.mbr_partcion[1].part_type, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_fit, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_name, delet[0]);
                                            master.mbr_partcion[1].part_start = 0;
                                            master.mbr_partcion[1].part_size = 0;
                                            int pos = ftell(arch1) - sizeof(MBR);

                                            fseek(arch1, pos, SEEK_SET);
                                            fwrite(&master, sizeof(MBR), 1, arch1);
                                            printf("Se modifico los datos de la particion.\n");
                                            existe = 1;

                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            break;
                                        }
                                        else
                                        {
                                            if (name[0] == master.mbr_partcion[2].part_name)
                                            {
                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                delet[0] = ru;

                                                strcpy(master.mbr_partcion[2].part_type, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_fit, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_name, delet[0]);
                                                master.mbr_partcion[2].part_start = 0;
                                                master.mbr_partcion[2].part_size = 0;
                                                int pos = ftell(arch1) - sizeof(MBR);

                                                fseek(arch1, pos, SEEK_SET);
                                                fwrite(&master, sizeof(MBR), 1, arch1);
                                                printf("Se modifico los datos de la particion.\n");
                                                existe = 1;

                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                break;
                                            }
                                            else
                                            {
                                                if (name[0] == master.mbr_partcion[3].part_name)
                                                {
                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    delet[0] = ru;

                                                    strcpy(master.mbr_partcion[3].part_type, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_fit, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_name, delet[0]);
                                                    master.mbr_partcion[3].part_start = 0;
                                                    master.mbr_partcion[3].part_size = 0;
                                                    int pos = ftell(arch1) - sizeof(MBR);

                                                    fseek(arch1, pos, SEEK_SET);
                                                    fwrite(&master, sizeof(MBR), 1, arch1);
                                                    printf("Se modifico los datos de la particion.\n");
                                                    existe = 1;

                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    break;
                                                }
                                                else
                                                {
                                                    printf("NO HAY MAS PARTICIONES\n");
                                                    printf(" \n");
                                                    printf("ERROR/Advertencia: No se encontro Particion\n");
                                                    printf(" \n");
                                                    break;
                                                }
                                            }
                                        }
                                    }

                                    fread(&master, sizeof(MBR), 1, arch1);
                                }

                                if (existe == 0)
                                    printf("Ya existe la particion\n");
                                fclose(arch1);
                            }
                            else if ((strcmp(unit[0], "k") == 0) || (strcmp(unit[0], "K") == 0))
                            {
                                FILE *arch1;
                                arch1 = fopen(path[0], "r+b");
                                if (arch1 == NULL)
                                    exit(1);

                                MBR master;
                                int cont = 0;
                                int existe = 1;
                                printf(" Actualizando Archivo....\n");

                                time_t t;

                                t = time(NULL);

                                fread(&master, sizeof(MBR), 1, arch1);

                                while (!feof(arch1))
                                {
                                    name[0][strcspn(name[0], "\n")] = 0;

                                    if (name[0] == master.mbr_partcion[0].part_name)
                                    {
                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        delet[0] = ru;

                                        strcpy(master.mbr_partcion[0].part_type, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_fit, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_name, delet[0]);
                                        master.mbr_partcion[0].part_start = 0;
                                        master.mbr_partcion[0].part_size = 0;
                                        int pos = ftell(arch1) - sizeof(MBR);

                                        fseek(arch1, pos, SEEK_SET);
                                        fwrite(&master, sizeof(MBR), 1, arch1);
                                        printf("Se modifico los datos de la particion.\n");
                                        existe = 1;

                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        break;
                                    }
                                    else
                                    {
                                        if (name[0] == master.mbr_partcion[1].part_name)
                                        {
                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            delet[0] = ru;

                                            strcpy(master.mbr_partcion[1].part_type, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_fit, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_name, delet[0]);
                                            master.mbr_partcion[1].part_start = 0;
                                            master.mbr_partcion[1].part_size = 0;
                                            int pos = ftell(arch1) - sizeof(MBR);

                                            fseek(arch1, pos, SEEK_SET);
                                            fwrite(&master, sizeof(MBR), 1, arch1);
                                            printf("Se modifico los datos de la particion.\n");
                                            existe = 1;

                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            break;
                                        }
                                        else
                                        {
                                            if (name[0] == master.mbr_partcion[2].part_name)
                                            {
                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                delet[0] = ru;

                                                strcpy(master.mbr_partcion[2].part_type, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_fit, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_name, delet[0]);
                                                master.mbr_partcion[2].part_start = 0;
                                                master.mbr_partcion[2].part_size = 0;
                                                int pos = ftell(arch1) - sizeof(MBR);

                                                fseek(arch1, pos, SEEK_SET);
                                                fwrite(&master, sizeof(MBR), 1, arch1);
                                                printf("Se modifico los datos de la particion.\n");
                                                existe = 1;

                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                break;
                                            }
                                            else
                                            {
                                                if (name[0] == master.mbr_partcion[3].part_name)
                                                {
                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    delet[0] = ru;

                                                    strcpy(master.mbr_partcion[3].part_type, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_fit, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_name, delet[0]);
                                                    master.mbr_partcion[3].part_start = 0;
                                                    master.mbr_partcion[3].part_size = 0;
                                                    int pos = ftell(arch1) - sizeof(MBR);

                                                    fseek(arch1, pos, SEEK_SET);
                                                    fwrite(&master, sizeof(MBR), 1, arch1);
                                                    printf("Se modifico los datos de la particion.\n");
                                                    existe = 1;

                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    break;
                                                }
                                                else
                                                {
                                                    printf("NO HAY MAS PARTICIONES\n");
                                                    printf(" \n");
                                                    printf("ERROR/Advertencia: No se encontro Particion\n");
                                                    printf(" \n");
                                                    break;
                                                }
                                            }
                                        }
                                    }

                                    fread(&master, sizeof(MBR), 1, arch1);
                                }

                                if (existe == 0)
                                    printf("Ya existe la particion\n");
                                fclose(arch1);
                            }
                            else
                            {
                                printf("NO ENTRO AL UNIT\n");
                                printf(" \n");
                                printf("ERROR/Advertencia: valor inexistente u variable nula\n");
                                printf(" \n");
                            }
                        }
                        else if (strcmp(delet[0], "FULL") == 0)
                        {
                            unit[0][strcspn(unit[0], "\n")] = 0;

                            if ((strcmp(unit[0], "m") == 0) || (strcmp(unit[0], "M") == 0))
                            {
                                FILE *arch1;
                                arch1 = fopen(path[0], "r+b");
                                if (arch1 == NULL)
                                    exit(1);

                                MBR master;
                                int cont = 0;
                                int existe = 1;
                                printf(" Actualizando Archivo....\n");

                                time_t t;

                                t = time(NULL);

                                fread(&master, sizeof(MBR), 1, arch1);

                                while (!feof(arch1))
                                {
                                    name[0][strcspn(name[0], "\n")] = 0;

                                    if (name[0] == master.mbr_partcion[0].part_name)
                                    {
                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        delet[0] = ru1;

                                        strcpy(master.mbr_partcion[0].part_type, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_fit, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_name, delet[0]);
                                        master.mbr_partcion[0].part_start = 0;
                                        master.mbr_partcion[0].part_size = 0;
                                        int pos = ftell(arch1) - sizeof(MBR);

                                        fseek(arch1, pos, SEEK_SET);
                                        fwrite(&master, sizeof(MBR), 1, arch1);
                                        printf("Se modifico los datos de la particion.\n");
                                        existe = 1;

                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        break;
                                    }
                                    else
                                    {
                                        if (name[0] == master.mbr_partcion[1].part_name)
                                        {
                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            delet[0] = ru1;

                                            strcpy(master.mbr_partcion[1].part_type, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_fit, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_name, delet[0]);
                                            master.mbr_partcion[1].part_start = 0;
                                            master.mbr_partcion[1].part_size = 0;
                                            int pos = ftell(arch1) - sizeof(MBR);

                                            fseek(arch1, pos, SEEK_SET);
                                            fwrite(&master, sizeof(MBR), 1, arch1);
                                            printf("Se modifico los datos de la particion.\n");
                                            existe = 1;

                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            break;
                                        }
                                        else
                                        {
                                            if (name[0] == master.mbr_partcion[2].part_name)
                                            {
                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                delet[0] = ru1;

                                                strcpy(master.mbr_partcion[2].part_type, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_fit, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_name, delet[0]);
                                                master.mbr_partcion[2].part_start = 0;
                                                master.mbr_partcion[2].part_size = 0;
                                                int pos = ftell(arch1) - sizeof(MBR);

                                                fseek(arch1, pos, SEEK_SET);
                                                fwrite(&master, sizeof(MBR), 1, arch1);
                                                printf("Se modifico los datos de la particion.\n");
                                                existe = 1;

                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                break;
                                            }
                                            else
                                            {
                                                if (name[0] == master.mbr_partcion[3].part_name)
                                                {
                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    delet[0] = ru1;

                                                    strcpy(master.mbr_partcion[3].part_type, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_fit, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_name, delet[0]);
                                                    master.mbr_partcion[3].part_start = 0;
                                                    master.mbr_partcion[3].part_size = 0;
                                                    int pos = ftell(arch1) - sizeof(MBR);

                                                    fseek(arch1, pos, SEEK_SET);
                                                    fwrite(&master, sizeof(MBR), 1, arch1);
                                                    printf("Se modifico los datos de la particion.\n");
                                                    existe = 1;

                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    break;
                                                }
                                                else
                                                {
                                                    printf("NO HAY MAS PARTICIONES\n");
                                                    printf(" \n");
                                                    printf("ERROR/Advertencia: No se encontro Particion\n");
                                                    printf(" \n");
                                                    break;
                                                }
                                            }
                                        }
                                    }

                                    fread(&master, sizeof(MBR), 1, arch1);
                                }

                                if (existe == 0)
                                    printf("Ya existe la particion\n");
                                fclose(arch1);
                            }
                            else if ((strcmp(unit[0], "b") == 0) || (strcmp(unit[0], "B") == 0))
                            {
                                FILE *arch1;
                                arch1 = fopen(path[0], "r+b");
                                if (arch1 == NULL)
                                    exit(1);

                                MBR master;
                                int cont = 0;
                                int existe = 1;
                                printf(" Actualizando Archivo....\n");

                                time_t t;

                                t = time(NULL);

                                fread(&master, sizeof(MBR), 1, arch1);

                                while (!feof(arch1))
                                {
                                    name[0][strcspn(name[0], "\n")] = 0;

                                    if (name[0] == master.mbr_partcion[0].part_name)
                                    {
                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        delet[0] = ru1;

                                        strcpy(master.mbr_partcion[0].part_type, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_fit, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_name, delet[0]);
                                        master.mbr_partcion[0].part_start = 0;
                                        master.mbr_partcion[0].part_size = 0;
                                        int pos = ftell(arch1) - sizeof(MBR);

                                        fseek(arch1, pos, SEEK_SET);
                                        fwrite(&master, sizeof(MBR), 1, arch1);
                                        printf("Se modifico los datos de la particion.\n");
                                        existe = 1;

                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        break;
                                    }
                                    else
                                    {
                                        if (name[0] == master.mbr_partcion[1].part_name)
                                        {
                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            delet[0] = ru1;

                                            strcpy(master.mbr_partcion[1].part_type, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_fit, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_name, delet[0]);
                                            master.mbr_partcion[1].part_start = 0;
                                            master.mbr_partcion[1].part_size = 0;
                                            int pos = ftell(arch1) - sizeof(MBR);

                                            fseek(arch1, pos, SEEK_SET);
                                            fwrite(&master, sizeof(MBR), 1, arch1);
                                            printf("Se modifico los datos de la particion.\n");
                                            existe = 1;

                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            break;
                                        }
                                        else
                                        {
                                            if (name[0] == master.mbr_partcion[2].part_name)
                                            {
                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                delet[0] = ru1;

                                                strcpy(master.mbr_partcion[2].part_type, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_fit, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_name, delet[0]);
                                                master.mbr_partcion[2].part_start = 0;
                                                master.mbr_partcion[2].part_size = 0;
                                                int pos = ftell(arch1) - sizeof(MBR);

                                                fseek(arch1, pos, SEEK_SET);
                                                fwrite(&master, sizeof(MBR), 1, arch1);
                                                printf("Se modifico los datos de la particion.\n");
                                                existe = 1;

                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                break;
                                            }
                                            else
                                            {
                                                if (name[0] == master.mbr_partcion[3].part_name)
                                                {
                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    delet[0] = ru1;

                                                    strcpy(master.mbr_partcion[3].part_type, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_fit, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_name, delet[0]);
                                                    master.mbr_partcion[3].part_start = 0;
                                                    master.mbr_partcion[3].part_size = 0;
                                                    int pos = ftell(arch1) - sizeof(MBR);

                                                    fseek(arch1, pos, SEEK_SET);
                                                    fwrite(&master, sizeof(MBR), 1, arch1);
                                                    printf("Se modifico los datos de la particion.\n");
                                                    existe = 1;

                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    break;
                                                }
                                                else
                                                {
                                                    printf("NO HAY MAS PARTICIONES\n");
                                                    printf(" \n");
                                                    printf("ERROR/Advertencia: No se encontro Particion\n");
                                                    printf(" \n");
                                                    break;
                                                }
                                            }
                                        }
                                    }

                                    fread(&master, sizeof(MBR), 1, arch1);
                                }

                                if (existe == 0)
                                    printf("Ya existe la particion\n");
                                fclose(arch1);
                            }
                            else if ((strcmp(unit[0], "k") == 0) || (strcmp(unit[0], "K") == 0))
                            {
                                FILE *arch1;
                                arch1 = fopen(path[0], "r+b");
                                if (arch1 == NULL)
                                    exit(1);

                                MBR master;
                                int cont = 0;
                                int existe = 1;
                                printf(" Actualizando Archivo....\n");

                                time_t t;

                                t = time(NULL);

                                fread(&master, sizeof(MBR), 1, arch1);

                                while (!feof(arch1))
                                {
                                    name[0][strcspn(name[0], "\n")] = 0;

                                    if (name[0] == master.mbr_partcion[0].part_name)
                                    {
                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        delet[0] = ru1;

                                        strcpy(master.mbr_partcion[0].part_type, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_fit, delet[0]);
                                        strcpy(master.mbr_partcion[0].part_name, delet[0]);
                                        master.mbr_partcion[0].part_start = 0;
                                        master.mbr_partcion[0].part_size = 0;
                                        int pos = ftell(arch1) - sizeof(MBR);

                                        fseek(arch1, pos, SEEK_SET);
                                        fwrite(&master, sizeof(MBR), 1, arch1);
                                        printf("Se modifico los datos de la particion.\n");
                                        existe = 1;

                                        printf("%s %s\n", "Type: ", master.mbr_partcion[0].part_type);
                                        printf("%s %s\n", "Status: ", master.mbr_partcion[0].part_status);
                                        printf("%s %s\n", "Name: ", master.mbr_partcion[0].part_name);
                                        printf("%s %s\n", "Fit: ", master.mbr_partcion[0].part_fit);
                                        printf("%s %d\n", "Start: ", master.mbr_partcion[0].part_start);
                                        printf("%s %d\n", "Size: ", master.mbr_partcion[0].part_size);

                                        break;
                                    }
                                    else
                                    {
                                        if (name[0] == master.mbr_partcion[1].part_name)
                                        {
                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            delet[0] = ru1;

                                            strcpy(master.mbr_partcion[1].part_type, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_fit, delet[0]);
                                            strcpy(master.mbr_partcion[1].part_name, delet[0]);
                                            master.mbr_partcion[1].part_start = 0;
                                            master.mbr_partcion[1].part_size = 0;
                                            int pos = ftell(arch1) - sizeof(MBR);

                                            fseek(arch1, pos, SEEK_SET);
                                            fwrite(&master, sizeof(MBR), 1, arch1);
                                            printf("Se modifico los datos de la particion.\n");
                                            existe = 1;

                                            printf("%s %s\n", "Type: ", master.mbr_partcion[1].part_type);
                                            printf("%s %s\n", "Status: ", master.mbr_partcion[1].part_status);
                                            printf("%s %s\n", "Name: ", master.mbr_partcion[1].part_name);
                                            printf("%s %s\n", "Fit: ", master.mbr_partcion[1].part_fit);
                                            printf("%s %d\n", "Start: ", master.mbr_partcion[1].part_start);
                                            printf("%s %d\n", "Size: ", master.mbr_partcion[1].part_size);

                                            break;
                                        }
                                        else
                                        {
                                            if (name[0] == master.mbr_partcion[2].part_name)
                                            {
                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                delet[0] = ru1;

                                                strcpy(master.mbr_partcion[2].part_type, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_fit, delet[0]);
                                                strcpy(master.mbr_partcion[2].part_name, delet[0]);
                                                master.mbr_partcion[2].part_start = 0;
                                                master.mbr_partcion[2].part_size = 0;
                                                int pos = ftell(arch1) - sizeof(MBR);

                                                fseek(arch1, pos, SEEK_SET);
                                                fwrite(&master, sizeof(MBR), 1, arch1);
                                                printf("Se modifico los datos de la particion.\n");
                                                existe = 1;

                                                printf("%s %s\n", "Type: ", master.mbr_partcion[2].part_type);
                                                printf("%s %s\n", "Status: ", master.mbr_partcion[2].part_status);
                                                printf("%s %s\n", "Name: ", master.mbr_partcion[2].part_name);
                                                printf("%s %s\n", "Fit: ", master.mbr_partcion[2].part_fit);
                                                printf("%s %d\n", "Start: ", master.mbr_partcion[2].part_start);
                                                printf("%s %d\n", "Size: ", master.mbr_partcion[2].part_size);

                                                break;
                                            }
                                            else
                                            {
                                                if (name[0] == master.mbr_partcion[3].part_name)
                                                {
                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    delet[0] = ru1;

                                                    strcpy(master.mbr_partcion[3].part_type, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_fit, delet[0]);
                                                    strcpy(master.mbr_partcion[3].part_name, delet[0]);
                                                    master.mbr_partcion[3].part_start = 0;
                                                    master.mbr_partcion[3].part_size = 0;
                                                    int pos = ftell(arch1) - sizeof(MBR);

                                                    fseek(arch1, pos, SEEK_SET);
                                                    fwrite(&master, sizeof(MBR), 1, arch1);
                                                    printf("Se modifico los datos de la particion.\n");
                                                    existe = 1;

                                                    printf("%s %s\n", "Type: ", master.mbr_partcion[3].part_type);
                                                    printf("%s %s\n", "Status: ", master.mbr_partcion[3].part_status);
                                                    printf("%s %s\n", "Name: ", master.mbr_partcion[3].part_name);
                                                    printf("%s %s\n", "Fit: ", master.mbr_partcion[3].part_fit);
                                                    printf("%s %d\n", "Start: ", master.mbr_partcion[3].part_start);
                                                    printf("%s %d\n", "Size: ", master.mbr_partcion[3].part_size);

                                                    break;
                                                }
                                                else
                                                {
                                                    printf("NO HAY MAS PARTICIONES\n");
                                                    printf(" \n");
                                                    printf("ERROR/Advertencia: No se encontro Particion\n");
                                                    printf(" \n");
                                                    break;
                                                }
                                            }
                                        }
                                    }

                                    fread(&master, sizeof(MBR), 1, arch1);
                                }

                                if (existe == 0)
                                    printf("Ya existe la particion\n");
                                fclose(arch1);
                            }
                            else
                            {
                                printf("NO ENTRO AL UNIT\n");
                                printf(" \n");
                                printf("ERROR/Advertencia: valor inexistente u variable nula\n");
                                printf(" \n");
                            }
                        }
                    }
                    else
                    {
                        printf("NO ENTRO A LA MODIFICACION\n");
                        printf(" \n");
                        printf("ERROR/Advertencia: Necesita modificar o eliminar archivo\n");
                        printf(" \n");
                    }
                }
                else
                {
                    printf("NO ENTRO AL Type\n");
                    printf(" \n");
                    printf("ERROR/Advertencia: valor inexistente u variable nula\n");
                    printf(" \n");
                }
            }
            else
            {
                printf("NO ENTRO AL FIT\n");
                printf(" \n");
                printf("ERROR/Advertencia: valor inexistente u variable nula\n");
                printf(" \n");
            }

            // fclose(arch1);
            printf(" \n");
            printf("Termino de carga de Datos\n");

            printf(" \n");
        }
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

    int part = 0;

    char dd[5] = "F";
    char d1[5] = "m";
    char hu[5] = "0";

    char *path[100];
    char *size[100];
    char *unit[100];
    char *fit[100];

    char *cero[100];

    char *sino[100];

    // fit[0] = "FF";
    // unit[0] = "m";

    // unit[0] = "m";

    // printf("%s %s\n", "Este es el fit:", fit[0]);

    printf("%s %d %d %d\n", "Prueba de parametros:", a, s, u);

    char *split = strtok(x, igual);
    printf(" %s\n", split);

    for (size_t i = 0; i < strlen(split); ++i)
    {
        split[i] = tolower((unsigned char)split[i]);
        // printf(" %c\n", split[i]);
    }

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

    for (size_t i = 0; i < strlen(divi); ++i)
    {
        divi[i] = tolower((unsigned char)divi[i]);
        // printf(" %c\n", split[i]);
    }

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

    for (size_t i = 0; i < strlen(separar); ++i)
    {
        separar[i] = tolower((unsigned char)separar[i]);
        // printf(" %c\n", split[i]);
    }

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

    for (size_t i = 0; i < strlen(otra); ++i)
    {
        otra[i] = tolower((unsigned char)otra[i]);
        // printf(" %c\n", split[i]);
    }

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
        cero[0] = hu;

        if (f == 0)
        {
            printf("Valor Fit establecido automaticamente\n");
            fit[0] = dd;
        }
        else
        {
            printf("Print Encontrado\n");
        }
        if (u == 0)
        {
            printf("Valor Unit establecido automaticamente\n");
            unit[0] = d1;
        }
        else
        {
            printf("Print Encontrado\n");
        }
        // Espera
        printf(" \n");
        FILE *arch;
        // char nombre;
        printf("%s %s\n", "Esta es la direccion PATH:", path[0]);

        path[0][strcspn(path[0], "\n")] = 0;
        size[0][strcspn(size[0], "\n")] = 0;

        arch = fopen(path[0], "wb");

        if (arch == NULL)
            exit(1);
        fclose(arch);

        printf(" \n");
        printf("%s %s\n", "Este es el fit:", fit[0]);

        fit[0][strcspn(fit[0], "\n")] = 0;

        if ((strcmp(fit[0], "B") == 0) || (strcmp(fit[0], "F") == 0) || (strcmp(fit[0], "W") == 0) || (strcmp(fit[0], "BF") == 0) || (strcmp(fit[0], "FF") == 0) || (strcmp(fit[0], "WF") == 0))
        {
            printf("SI ENTRO AL FIT\n");

            unit[0][strcspn(unit[0], "\n")] = 0;

            if ((strcmp(unit[0], "m") == 0) || (strcmp(unit[0], "M") == 0))
            {
                printf("SI ENTRO AL UNIT\n");
                FILE *arch1;
                arch1 = fopen(path[0], "ab");
                if (arch1 == NULL)
                    exit(1);

                MBR master;
                int cont = 0;
                printf(" Creando Archivo....\n");

                time_t t;

                t = time(NULL);

                master.mbr_tamano = strtol(size[0], NULL, 10) * 1024 * 1024;
                master.mbr_fecha_creacion = t;
                master.mbr_dsk_signature = rand() % 500;
                strcpy(master.mbr_fit, fit[0]);

                while (part <= 3)
                {
                    strcpy(master.mbr_partcion[part].part_status, cero[0]);
                    strcpy(master.mbr_partcion[part].part_type, cero[0]);
                    strcpy(master.mbr_partcion[part].part_fit, cero[0]);
                    master.mbr_partcion[part].part_start = -1;
                    master.mbr_partcion[part].part_size = 0;
                    strcpy(master.mbr_partcion[part].part_name, "");

                    printf("%s %s\n", "Type: ", master.mbr_partcion[part].part_type);
                    printf("%s %s\n", "Status: ", master.mbr_partcion[part].part_status);
                    printf("%s %s\n", "Name: ", master.mbr_partcion[part].part_name);
                    printf("%s %s\n", "Fit: ", master.mbr_partcion[part].part_fit);
                    printf("%s %d\n", "Start: ", master.mbr_partcion[part].part_start);
                    printf("%s %d\n", "Size: ", master.mbr_partcion[part].part_size);

                    part = part + 1;
                }

                printf("%s %d\n", "Este es el tamaño:", master.mbr_tamano);
                printf("%s %ld\n", "Este es el fecha:", master.mbr_fecha_creacion);
                printf("%s %d\n", "Este es el signatura:", master.mbr_dsk_signature);
                printf("%s %s\n", "Este es el fit:", master.mbr_fit);

                fwrite(&master, master.mbr_tamano, 1, arch1);

                fclose(arch1);
                printf(" \n");
                printf("Creacion de Archivo Terminada\n");

                printf(" \n");
            }
            else if ((strcmp(unit[0], "k") == 0) || (strcmp(unit[0], "K") == 0))
            {
                printf("SI ENTRO AL UNIT\n");

                FILE *arch1;
                arch1 = fopen(path[0], "ab");
                if (arch1 == NULL)
                    exit(1);

                MBR master;
                int cont = 0;
                printf(" Creando Archivo....\n");

                time_t t;

                t = time(NULL);

                master.mbr_tamano = strtol(size[0], NULL, 10) * 1024;
                master.mbr_fecha_creacion = t;
                master.mbr_dsk_signature = rand() % 500;
                strcpy(master.mbr_fit, fit[0]);

                while (part <= 3)
                {
                    strcpy(master.mbr_partcion[part].part_status, cero[0]);
                    strcpy(master.mbr_partcion[part].part_type, cero[0]);
                    strcpy(master.mbr_partcion[part].part_fit, cero[0]);
                    master.mbr_partcion[part].part_start = -1;
                    master.mbr_partcion[part].part_size = 0;
                    strcpy(master.mbr_partcion[part].part_name, "");

                    printf("%s %s\n", "Type: ", master.mbr_partcion[part].part_type);
                    printf("%s %s\n", "Status: ", master.mbr_partcion[part].part_status);
                    printf("%s %s\n", "Name: ", master.mbr_partcion[part].part_name);
                    printf("%s %s\n", "Fit: ", master.mbr_partcion[part].part_fit);
                    printf("%s %d\n", "Start: ", master.mbr_partcion[part].part_start);
                    printf("%s %d\n", "Size: ", master.mbr_partcion[part].part_size);

                    part = part + 1;
                }

                printf("%s %d\n", "Este es el tamaño:", master.mbr_tamano);
                printf("%s %ld\n", "Este es el fecha:", master.mbr_fecha_creacion);
                printf("%s %d\n", "Este es el signatura:", master.mbr_dsk_signature);
                printf("%s %s\n", "Este es el fit:", master.mbr_fit);

                fwrite(&master, master.mbr_tamano, 1, arch1);

                fclose(arch1);
                printf(" \n");
                printf("Creacion de Archivo Terminada\n");

                printf(" \n");
            }
            else
            {
                printf("NO ENTRO AL UNIT\n");
                printf(" \n");
                printf("ERROR/Advertencia: valor inexistente u variable nula\n");
                printf(" \n");
            }
        }
        else
        {
            printf("NO ENTRO AL FIT\n");
            printf(" \n");
            printf("ERROR/Advertencia: valor inexistente u variable nula\n");
            printf(" \n");
        }
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
    int part = 0;

    FILE *arch;
    arch = fopen("toto.dk", "rb");
    if (arch == NULL)
        exit(1);

    MBR maestro;
    fread(&maestro, sizeof(MBR), 1, arch);

    printf("Tamaño: ");

    printf("%d\n", maestro.mbr_tamano);
    printf("Fecha de Creacion: ");
    printf("%ld\n", maestro.mbr_fecha_creacion);
    printf("Signature: ");
    printf("%d\n", maestro.mbr_dsk_signature);
    printf("Fit: ");
    printf("%s\n", maestro.mbr_fit);
    printf("Particiones: \n");

    while (part <= 3)
    {

        printf("%s %s\n", "Type: ", maestro.mbr_partcion[part].part_type);
        printf("%s %s\n", "Status: ", maestro.mbr_partcion[part].part_status);
        printf("%s %s\n", "Name: ", maestro.mbr_partcion[part].part_name);
        printf("%s %s\n", "Fit: ", maestro.mbr_partcion[part].part_fit);
        printf("%s %d\n", "Start: ", maestro.mbr_partcion[part].part_start);
        printf("%s %d\n", "Size: ", maestro.mbr_partcion[part].part_size);

        part = part + 1;
    }

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
    mknum[4] = NULL;
    mknum[5] = NULL;
    mknum[6] = NULL;

    for (size_t i = 0; i < strlen(split); ++i)
    {
        split[i] = tolower((unsigned char)split[i]);
        // printf(" %c\n", split[i]);
    }

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

                /*if (strcmp(split, "/home/manuel/Descargas/hola.txt") == 0)
                {
                    printf("Deberia funcionar \n");
                }
                else
                {
                    printf("No es igual \n");
                }*/

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

                        opcion[strcspn(opcion, "\n")] = 0;

                        for (size_t i = 0; i < strlen(opcion); ++i)
                        {
                            opcion[i] = tolower((unsigned char)opcion[i]);
                            // printf(" %c\n", split[i]);
                        }

                        if (strcmp(opcion, "exit") == 0)
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
                            FDISK(mknum[0], mknum[1], mknum[2], mknum[3], mknum[4], mknum[5], mknum[6]);
                            cont = 0;
                            mknum[0] = NULL;
                            mknum[1] = NULL;
                            mknum[2] = NULL;
                            mknum[3] = NULL;
                            mknum[4] = NULL;
                            mknum[5] = NULL;
                            mknum[6] = NULL;
                        }
                        else if (strcmp(opcion, "rmdisk") == 0)
                        {
                            printf("EJECUTANDO: Comando rmdisk \n");
                            printf("Analizando..... \n");
                            while (opcion != NULL)
                            {
                                if (strcmp(opcion, "rmdisk") == 0)
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
                            RMDISK(mknum[0]);
                            cont = 0;
                            mknum[0] = NULL;
                        }
                        else if (strcmp(opcion, "mount") == 0)
                        {
                            printf("EJECUTANDO: Comando mount \n");
                            printf("Analizando..... \n");
                            while (opcion != NULL)
                            {
                                if (strcmp(opcion, "mount") == 0)
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
                            MOUNT(mknum[0], mknum[1]);
                            cont = 0;
                            mknum[0] = NULL;
                            mknum[1] = NULL;
                        }
                        else if (strcmp(opcion, "unmount") == 0)
                        {
                            printf("EJECUTANDO: Comando unmount \n");
                            printf("Analizando..... \n");
                            while (opcion != NULL)
                            {
                                if (strcmp(opcion, "unmount") == 0)
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
                            UNMOUNT(mknum[0]);
                            cont = 0;
                            mknum[0] = NULL;
                        }
                        else if (strcmp(opcion, "rep") == 0)
                        {
                            printf("EJECUTANDO: Comando rep \n");
                            printf("Analizando..... \n");
                            REP();
                        }
                        else if (strcmp(opcion, "mkfs") == 0)
                        {
                            printf("EJECUTANDO: Comando mkfs \n");
                            printf("Analizando..... \n");
                            while (opcion != NULL)
                            {
                                if (strcmp(opcion, "mkfs") == 0)
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
                            MKFS(mknum[0], mknum[1], mknum[2]);
                            cont = 0;
                            mknum[0] = NULL;
                            mknum[1] = NULL;
                            mknum[2] = NULL;
                        }
                        else if (strcmp(opcion, "login") == 0)
                        {
                            printf("EJECUTANDO: Comando login \n");
                            printf("Analizando..... \n");
                            while (opcion != NULL)
                            {
                                if (strcmp(opcion, "login") == 0)
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
                            LOGIN(mknum[0], mknum[1], mknum[2]);
                            cont = 0;
                            mknum[0] = NULL;
                            mknum[1] = NULL;
                            mknum[2] = NULL;
                        }
                        else if (strcmp(opcion, "logout") == 0)
                        {
                            printf("EJECUTANDO: Comando logout \n");
                            printf("Analizando..... \n");
                            LOGOUT();
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
    mknum[4] = NULL;
    mknum[5] = NULL;
    mknum[6] = NULL;

    printf("\n");
    /* mkdir("hola", 0777);   //Solo funcionaron como prueba
     chdir("hola");
     mkdir("Adios", 0777);

     chdir("..");
     mkdir("FF", 0777);*/

    do
    {
        // printf("Prueba: ");

        fgets(cmd, 200, stdin);

        // printf(" \n");
        // printf("%s %s\n", "Esta prueba es de split: ", cmd);

        char *split = strtok(cmd, espacio);

        // printf("%s %s\n", "Esta prueba es de split: ", cmd);
        //  printf(" \n");

        for (size_t i = 0; i < strlen(split); ++i)
        {
            split[i] = tolower((unsigned char)split[i]);
            // printf(" %c\n", split[i]);
        }

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
        else if (strcmp(split, "rmdisk") == 0)
        {
            printf("EJECUTANDO: Comando rmdisk \n");
            printf("ADVERTENCIA: la dreccion del archivo NO debe tener espacios; Se mostrara ERROR \n");
            while (split != NULL)
            {
                if (strcmp(split, "rmdisk") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                }
                else
                {
                    printf(" %s\n", split); // printing each token
                    RMDISK(split);
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
            FDISK(mknum[0], mknum[1], mknum[2], mknum[3], mknum[4], mknum[5], mknum[6]);
            cont = 0;
            mknum[0] = NULL;
            mknum[1] = NULL;
            mknum[2] = NULL;
            mknum[3] = NULL;
            mknum[4] = NULL;
            mknum[5] = NULL;
            mknum[6] = NULL;
        }
        else if (strcmp(split, "mount") == 0)
        {
            printf("EJECUTANDO: Comando mount \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "mount") == 0)
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
            MOUNT(mknum[0], mknum[1]);
            cont = 0;
            mknum[0] = NULL;
            mknum[1] = NULL;
        }
        else if (strcmp(split, "unmount") == 0)
        {
            printf("EJECUTANDO: Comando UNMOUNT \n");
            // printf("ADVERTENCIA: la dreccion del archivo NO debe tener espacios; Se mostrara ERROR \n");
            while (split != NULL)
            {
                if (strcmp(split, "unmount") == 0)
                {
                    printf("Analizando..... \n");
                    split = strtok(NULL, " ");
                }
                else
                {
                    printf(" %s\n", split); // printing each token
                    UNMOUNT(split);
                    // split = strtok(NULL, " ");
                    break;
                }
            }
        }
        else if (strcmp(split, "mkfs") == 0)
        {
            printf("EJECUTANDO: Comando mkfs \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "mkfs") == 0)
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
            MKFS(mknum[0], mknum[1], mknum[2]);
            cont = 0;
            mknum[0] = NULL;
            mknum[1] = NULL;
            mknum[2] = NULL;
        }
        else if (strcmp(split, "login") == 0)
        {
            printf("EJECUTANDO: Comando login \n");
            printf("Analizando..... \n");
            while (split != NULL)
            {
                if (strcmp(split, "login") == 0)
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
            LOGIN(mknum[0], mknum[1], mknum[2]);
            cont = 0;
            mknum[0] = NULL;
            mknum[1] = NULL;
            mknum[2] = NULL;
        }
        else if (strcmp(split, "logout") == 0)
        {
            printf("EJECUTANDO: Comando logout \n");
            printf("Analizando..... \n");
            LOGOUT();
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