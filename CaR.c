#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t ut = time(NULL);
    struct tm utm = *localtime(&ut);
    bool bStop = false;
    int heure, minute;
    printf("------Reveil------\n\n");
    printf("\nentrez 1 pour le mode auto, 0 sinon : ");
    printf("\nentrez dans combien d heure vous souhaitez sonner : ");
    scanf("%d", &heure);
    printf("\nentrez entrez dans combien de minutes vous souhaitez sonner : ");
    scanf("%d", &minute);
    getchar();
    utm.tm_hour = utm.tm_hour + heure;
    utm.tm_min = utm.tm_min + minute;
    printf("\nvous serez reveille a %d:%d", heure, minute);
    while(!bStop)
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        if((tm.tm_hour == utm.tm_hour)&&(tm.tm_min == utm.tm_min))
        {
            printf("c'est l'heure bb");
        }
        bStop = true;
    }
    return 0;
}
