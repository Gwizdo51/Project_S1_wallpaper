#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define BOOL int
#define FALSE 0
#define TRUE 1

#define FOREGROUND_COLOR_BLACK   "\x1b[30m"
#define FOREGROUND_COLOR_RED     "\x1b[31m"
#define FOREGROUND_COLOR_GREEN   "\x1b[32m"
#define FOREGROUND_COLOR_YELLOW  "\x1b[33m"
#define FOREGROUND_COLOR_BLUE    "\x1b[34m"
#define FOREGROUND_COLOR_MAGENTA "\x1b[35m"
#define FOREGROUND_COLOR_CYAN    "\x1b[36m"
#define FOREGROUND_COLOR_WHITE   "\x1b[37m"

#define BRIGHT_FOREGROUND_COLOR_BLACK   "\x1b[90m"
#define BRIGHT_FOREGROUND_COLOR_RED     "\x1b[91m"
#define BRIGHT_FOREGROUND_COLOR_GREEN   "\x1b[92m"
#define BRIGHT_FOREGROUND_COLOR_YELLOW  "\x1b[93m"
#define BRIGHT_FOREGROUND_COLOR_BLUE    "\x1b[94m"
#define BRIGHT_FOREGROUND_COLOR_MAGENTA "\x1b[95m"
#define BRIGHT_FOREGROUND_COLOR_CYAN    "\x1b[96m"
#define BRIGHT_FOREGROUND_COLOR_WHITE   "\x1b[97m"

#define BACKGROUND_COLOR_BLACK   "\x1b[40m"
#define BACKGROUND_COLOR_RED     "\x1b[41m"
#define BACKGROUND_COLOR_GREEN   "\x1b[42m"
#define BACKGROUND_COLOR_YELLOW  "\x1b[43m"
#define BACKGROUND_COLOR_BLUE    "\x1b[44m"
#define BACKGROUND_COLOR_MAGENTA "\x1b[45m"
#define BACKGROUND_COLOR_CYAN    "\x1b[46m"
#define BACKGROUND_COLOR_WHITE   "\x1b[47m"

#define BRIGHT_BACKGROUND_COLOR_BLACK   "\x1b[100m"
#define BRIGHT_BACKGROUND_COLOR_RED     "\x1b[101m"
#define BRIGHT_BACKGROUND_COLOR_GREEN   "\x1b[102m"
#define BRIGHT_BACKGROUND_COLOR_YELLOW  "\x1b[103m"
#define BRIGHT_BACKGROUND_COLOR_BLUE    "\x1b[104m"
#define BRIGHT_BACKGROUND_COLOR_MAGENTA "\x1b[105m"
#define BRIGHT_BACKGROUND_COLOR_CYAN    "\x1b[106m"
#define BRIGHT_BACKGROUND_COLOR_WHITE   "\x1b[107m"

#define COLOR_RESET   "\x1b[0m"


int main()
{
    printf("%s%s", FOREGROUND_COLOR_BLACK, BACKGROUND_COLOR_CYAN);
    // printf("%s%s", BRIGHT_FOREGROUND_COLOR_CYAN, BACKGROUND_COLOR_BLUE);
    system("cls");
    printf("EAOA PROGRESS\n\n");
    printf("1. [P]apier peint\n");
    printf("2. [M]urs / pieces\n");
    printf("3. [C]olle\n");
    printf("4. [R]esultat\n");
    printf("5. [Q]uitter\n\n");

    printf("Unites:\n");
    printf("Distances: m (metres)\n");
    printf("Volume: L (litres)\n\n");

    system("pause");
    printf("%s", COLOR_RESET);
    system("cls");

    return 0;
}
