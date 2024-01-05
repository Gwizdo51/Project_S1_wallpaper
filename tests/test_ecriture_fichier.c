#include "..\logiciel\types.h"


int main () {
    time_t timestamp_now;
    struct tm *time_now_pointer;
    time(&timestamp_now);
    time_now_pointer = localtime(&timestamp_now);
    char file_name[100];
    strftime(file_name, 100, "%Y%m%d-%H%M%S - résultats.txt", time_now_pointer);
    printf("file_name = \"%s\"", file_name);

    return EXIT_SUCCESS;
}
