#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    bool bSortie;
    time_t got = time(NULL);
    struct tm gotm = *localtime(&got);
    int go, stop;
    printf("------Chronometre------\n\n");
    printf("\nPour commencer entrez 1 : ");
    scanf("%d", &go);
    time_t ut = time(NULL);
    struct tm utm = *localtime(&ut);
    printf("\nePour arreter entrez 0 : ");
    scanf("%d", &stop);
    time_t st = time(NULL);
    struct tm stm = *localtime(&st);
    printf("\n\nDurée : %d:%d:%d", (stm.tm_hour-gotm.tm_hour), abs(stm.tm_min-gotm.tm_min), abs(stm.tm_sec-gotm.tm_sec));
    return 0;
}
