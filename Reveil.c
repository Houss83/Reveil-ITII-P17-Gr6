#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int bStop;
    bool bPass = false;
    time_t ut = time(NULL);
    struct tm utm = *localtime(&ut);
    int heure, minute;
    printf("------Reveil------\n\n");
    printf("\nentrez 1 pour le mode auto, 0 sinon : ");
    scanf("%d", &bStop);
    printf("\nentrez une heure : ");
    scanf("%d", &heure);
    printf("\nentrez la minutes : ");
    scanf("%d", &minute);
    getchar();
    utm.tm_hour = heure;
    utm.tm_min = minute;
    printf("\nvous serez reveille a %d:%d", heure, minute);
    while(bPass==false)
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        if((tm.tm_hour == utm.tm_hour)&&(tm.tm_min == utm.tm_min))
        {
            printf("reveille toi");
        }
        if(bStop != 1) bPass = true;

    }
    return 0;
}
