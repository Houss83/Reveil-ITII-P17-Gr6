#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>


int affichageMenu(void);
void EcritureFichierTemps(FILE *fichier, time_t temps, struct tm tm);

int main(int argc, char *argv[])
{
    //Declaration des PID
    int PID_reveil, PID_chrono, PID_temps, PID_CaR, PIDa = 0, PIDb = 0, PIDc = 0;

    //outils du menu
    int ChoixMenu = affichageMenu();
    bool bStop = false;

    //Obtention de l'heure que l'on fournira à la fonction du fils pour écriture
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	//Ponteur vers le fichier à ouvrir que l'on passera à la fonction du fils
	FILE* fichier = NULL;
    PID_temps=fork();

    if(PID_temps <0) printf("erreur");
    if(PID_temps>0)
    {
        //Affichage du menu jusqu'à quitter
        while (!bStop)
        {
            //Reveil :
            switch(ChoixMenu)
            {
                case 1:
                printf("\nreveil choisi\n");
                PID_reveil = fork();
                if(PID_reveil == -1){
                    printf("erreur");
                }
                if(PID_reveil == 0)
                {
                    PIDa = getpid();
                    printf("processus fils\n");
                    execl("/usr/bin/xterm", "xterm", "-e", "./Reveil", NULL);
                };
                ChoixMenu = affichageMenu();
                break;

                case 2:
                printf("\nchrono choisi\n");
                PID_chrono = fork();
                if(PID_chrono == -1){
                    printf("erreur");
                }
                if(PID_chrono == 0)
                {
                    PIDb = getpid();
                    printf("processus fils");
                    execl("/usr/bin/xterm", "xterm", "-e", "./Chronometre", NULL);
                };
                ChoixMenu = affichageMenu();
                break;

                case 3:
                printf("\nCompte a rebours choisi\n");
                PID_chrono = fork();
                if(PID_CaR == -1){
                    printf("erreur");
                }
                if(PID_CaR == 0)
                {
                    PIDc = getpid();
                    printf("processus fils");
                    execl("/usr/bin/xterm", "xterm", "-e", "./CaR", NULL);
                };
                ChoixMenu = affichageMenu();
                break;

                case 0: //quitter
                bStop = true;
                break;
            }
        }
        kill(PIDa, SIGTERM);
        kill(PIDb, SIGTERM);
        kill(PIDc, SIGTERM);
    }
    if (PID_temps==0)
    {
        EcritureFichierTemps(fichier, t, tm);
    }

    return 0;
}

int affichageMenu(void)
{
     int ChoixMenu;
     printf("---Menu---\n\n");

     printf("1- Reveil\n");
     printf("2- Chronometre\n");
     printf("3- Compte a rebours\n");
     printf("0- Quitter");

     printf("\nVotre choix?\n\n");

     scanf(" %d", &ChoixMenu);
     getchar();
     printf("%d", ChoixMenu);
     return ChoixMenu;
}

void EcritureFichierTemps(FILE * fichier, time_t temps, struct tm tm)
{
    time_t t = time(NULL);
	struct tm tm1 = *localtime(&t);
    fichier = fopen("TempsExecution.txt", "w+");
    fprintf(fichier,"Exucution de %02d:%02d:%02d à %02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec, tm1.tm_hour, tm1.tm_min, tm1.tm_sec);
    fclose(fichier);
}

