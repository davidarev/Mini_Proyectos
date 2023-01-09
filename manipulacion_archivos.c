#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <operación> <archivo>\n", argv[0]);
        printf("Operaciones: renombrar, dividir\n");
        return 1;
    }

    char *op = argv[1]; //Operación
    char *filename = argv[2]; //Nombre del archivo

    if (strcmp(op, "renombrar") == 0) { //Si la operación es renombrar
        char newname[256];
        printf("Ingrese el nuevo nombre del archivo: ");
        scanf("%s", newname); //Leemos el nuevo nombre

        if (rename(filename, newname) == 0) { //Si se pudo renombrar
            printf("El archivo ha sido renombrado exitosamente.\n");
        }
        else { //Si no se pudo renombrar
            perror("Error al renombrar el archivo");
        }
    }
    else if (strcmp(op, "dividir") == 0) { //Si la operación es dividir
        FILE *fp = fopen(filename, "rb"); //Abrimos el archivo en modo lectura binaria
        if (fp == NULL) { //Si no se pudo abrir el archivo
            perror("Error al abrir el archivo");
            return 1;
        }

        int part = 0;
        char outname[256];
        sprintf(outname, "%s.part%d", filename, part); //Creamos el nombre del archivo de salida
        FILE *outfp = fopen(outname, "wb"); //Abrimos el archivo de salida en modo escritura binaria
        if (outfp == NULL) { //Si no se pudo abrir el archivo de salida
            perror("Error al crear el archivo de salida");
            return 1;
        }

        const int BUFSIZE = 256;
        char buf[BUFSIZE]; //Buffer
        int n;
        while ((n = fread(buf, 1, BUFSIZE, fp)) > 0) { //Leemos el archivo de entrada
            fwrite(buf, 1, n, outfp); //Escribimos en el archivo de salida
            if (n < BUFSIZE) {
                break;
            }
            fclose(outfp);

            part++;
            sprintf(outname, "%s.part%d", filename, part); //Creamos el nombre del archivo de salida
            outfp = fopen(outname, "wb");
            if (outfp == NULL) {
                perror("Error al crear el archivo de salida");
                return 1;
            }
        }

        fclose(fp);
        fclose(outfp);
        printf("El archivo ha sido dividido en %d partes.\n", part + 1);
    }
    else { //Si la operación no es válida
        printf("Operación desconocida: %s\n", op);
        return 1;
    }
    return 0;
}
