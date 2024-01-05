#include "..\logiciel\types.h"


int main () {
    // génération d'un nom de fichier
    time_t timestamp_now;
    struct tm *time_now_pointer;
    time(&timestamp_now);
    time_now_pointer = localtime(&timestamp_now);
    char file_name[100];
    strftime(file_name, 100, "%Y%m%d-%H%M%S - resultats.txt", time_now_pointer);
    printf("file_name = \"%s\"", file_name);

    // création du fichier et écriture dedans
    FILE *stream;
    stream = fopen(file_name, "w");
    fprintf(stream, "Bonjour!\n");
    fprintf(stream, "nombre de rouleaux : 10\n");
    fprintf(stream, "volume de colle : 20 litres\n");
    fclose(stream);

    return EXIT_SUCCESS;
}
