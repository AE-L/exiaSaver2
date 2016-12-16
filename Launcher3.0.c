#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>

int my_rand(); // tire un nombre aleatoire entre 1 et 3 (pour le lancement d un screensaver (time.h)
void config(char **envp); // permet d editer les vars d environnement globales par des vars d env programme.
void autoconfig(); // a titre d informations, utilisation config ~/.profile.
void attendre(float temps); //sleep recode, grace a time.h
void saverLaucher(int execNb, char **envp); //fonction lancant le screensaver sous forme de processus
int kbhit(void);  //getchar non bloquant
int forcescreensaver (int execNb);  //gere le decompte, permettant de forcer un screensaver
void write_log(char **envp, int execNb); //ecriture log
void nom_log(); //tri par noms
void type_log(); //tri par types
void date_log(); //tri par dates

int main(int argc, char *argv[], char **envp) // argc = nb de param, argv = param, envp = vars environnement programme 
{
  system("clear");

  int execNb;
  
  printf("Running ExiaSaver . . . ");
  attendre(1);

  if(argc>1)
    {
      
    if(strcmp(argv[1], "-cfg") == 0)
      {
        printf("Config avancee !\n\n");
        config(envp);
      }
    
    if(strcmp(argv[1], "-stats") == 0)
      {
	printf("Logs :\n");
	if(argc>2)
	  {
	if(strcmp(argv[2], "date") == 0)
	  date_log();
	else if(strcmp(argv[2], "name") == 0)
	  nom_log();
	else if(strcmp(argv[2], "type") == 0)
	  type_log();
	else
	  date_log();
	  }
	else
	  date_log(); // le tri par date est le tri par defaut
	
	
        return (0); 
      }
    
    if(strcmp(argv[1], "-cfg") != 0  && strcmp(argv[1], "-stats") != 0)
      {
	printf("option introuvable !\n");
	return (0);
      }
    
    }
  
  else
    {
        printf("Auto config !!\n");
	printf("Chargement de la configuration ~/.profile\n");
        autoconfig();
    }
    
  execNb = my_rand();
  execNb = forcescreensaver(execNb);
  printf("\n[%d]\n", execNb);

  write_log(envp, execNb);
  
  saverLaucher(execNb, envp);

  //system("clear");
  return (0);
}

void autoconfig()
{
  printf("Configuration actuelle:\n\n");
				    
  char *token;
    attendre(0.1);
  token = getenv("EXIASAVER_HOME");
    printf("EXIASAVER_HOME = %s\n", token);
    attendre(0.1);
  token = getenv("EXIASAVER1_PBM");
    printf("EXIASAVER1_PBM = %s\n", token);
    attendre(0.1);
  token = getenv("EXIASAVER2_PBM");
    printf("EXIASAVER2_PBM = %s\n", token);
    attendre(0.1);
  token = getenv("EXIASAVER2_TAILLE");
    printf("EXIASAVER2_TAILLE = %s\n", token);
    attendre(0.1);
  token = getenv("EXIASAVER2_SLEEP");
    printf("EXIASAVER2_SLEEP = %s\n", token);
    attendre(0.1);
  token = getenv("EXIASAVER3_PBM");
    printf("EXIASAVER3_PBM = %s\n", token);
    attendre(1.5);

}

void config(char **envp)
{
  printf("Pressez [ENTREE] pour laisser la valeur par defaut.\n\n");
  
  char token[150];

  /* EXIASAVER_HOME */
  
  printf("EXIASAVER_HOME ?\nRépertoire où se trouvent  les  3  exécutables.\nSi cette valeur n’est pas définie,\nle répertoire par défaut est le répertoire courant.\n\n > ");
  gets(token);
  if(strcmp(token, "") != 0)
    {
      setenv("EXIASAVER_HOME", token, 1);
    }
  system("clear");

  /* EXIASAVER1_PBM */
  
  printf("\nEXIASAVER1_PBM ?\nRépertoire  où se trouvent  tous  les fichiers  PBM  pour  le  niveau statique. Si cette valeur n’est pas définie,\nle répertoire par défaut est le répertoire courant.\n\n > ");
  gets(token);
  if(strcmp(token, "") != 0)
    {
      setenv("EXIASAVER1_PBM", token, 1);
    }
  system("clear");

    /* EXIASAVER2_PBM */
  
  printf("\nEXIASAVER2_PBM ?\nRépertoire  où se trouvent  tous  les fichiers  PBM  pour  le  niveau dynamique. Si cette valeur n’est pas définie,\nle répertoire par défaut est le répertoire courant.\n\n > ");
  gets(token);
  if(strcmp(token, "") != 0)
    {
      setenv("EXIASAVER2_PBM", token, 1);
    }
  system("clear");

    /* EXIASAVER3_PBM */
  
  printf("\nEXIASAVER3_PBM ?\nRépertoire  où se trouvent  tous  les fichiers  PBM  pour  le  niveau intéractif. Si cette valeur n’est pas définie,\nle répertoire par défaut est le répertoire courant.\n\n > ");
  gets(token);
  if(strcmp(token, "") != 0)
    {
      setenv("EXIASAVER3_PBM", token, 1);
    }
  system("clear");

    /* EXIASAVER2_TAILLE */
  
  printf("\nEXIASAVER2_TAILLE ?\nTaille  d’affichage  de  chiffres  dans  l’horloge  numérique.\nSi cette variable n’est pas définie, la valeur par défaut est 5x3.\n\n > ");
  gets(token);
  if(strcmp(token, "") != 0)
    {
      setenv("EXIASAVER2_TAILLE", token, 1);
    }
  system("clear");

      /* EXIASAVER2_SLEEP */
  
  printf("\nEXIASAVER2_SLEEP ?\nNombre (positif) de secondes entre 2 rafraichissements de l’horloge.\nSi cette variable n’est pas définie, la valeur par défaut est 10 secondes. .\n\n > ");
  gets(token);
  if(strcmp(token, "") != 0)
    {
      setenv("EXIASAVER2_SLEEP", token, 1);
    }
  system("clear");
  
  autoconfig();
}

int my_rand()
{
    srand(time(NULL));
    int randomValue;
    randomValue = rand()%3+1;

    return(randomValue);
}

void attendre(float temps)

{

    clock_t arrivee=clock()+(temps*CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arrêter


    while(clock()<arrivee);

}

void saverLaucher(int execNb, char **envp)
{
  char *string;
  char *stringtoexec;
  string = malloc(256*sizeof(char*));
  stringtoexec = malloc(256*sizeof(char*));
  
  pid_t pid;
  string = getenv("EXIASAVER_HOME"); // recup la var d env, quelle soit globale ou programme (programme prioritaire)

      if(strcmp(string, "DEFAULT") != 0)
	{
      
	  switch(execNb)
	    {
	    case 1:
	      sprintf(stringtoexec, "%s%s", string, "/exiasaver1");
		break;

	    case 2:
	      sprintf(stringtoexec, "%s%s", string, "/exiasaver2");
		break;

	    case 3:
	      sprintf(stringtoexec, "%s%s", string, "/exiasaver3");
		break;
	      }
	     }
      
       else
	{
	  switch(execNb)
	    {
	    case (1):
	      stringtoexec = "./exiasaver1";
		break;

	    case (2):
	      stringtoexec = "./exiasaver2";
		break;

	    case (3):
	      stringtoexec = "./exiasaver3";
		break;
		}
	  
	}

  
      pid = fork(); //Création processus fils

      if(pid == 0)
	{
	  printf("((%s))", stringtoexec);
	  attendre(2);
	  system("clear");
	  execvp(stringtoexec, envp);
	}
      else
	{
	  wait(NULL);
	}

}

int kbhit(void)  // ceci n est pas developpe par le groupe.
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

int forcescreensaver (int execNb)
{
  char *token;
  token = malloc(2*sizeof(char*));
  int i;
  i = 3;
  printf("\nAppuyez sur n'importe quelle touche pour forcer l'execution d'un screensaver !\n");
  
  while(!kbhit()) // tant qu on ne presse aucune touche
    {
    printf("%d\n", i);
    fflush(stdout);
    sleep(1);
    i--;
    if(i == 0)
      {
	return execNb;
      }
    }
  if(i != 0) // si touche pressee durant les 3 secondes
    {
      system("clear");
      printf("Veuillez rentrer [1-3]\n\n  > ");

      gets(token);
      
      for(i = 0 ; token[i] ; i++)
	token[i] = token[i+1];

	  switch(token[0])
	    {
	    case 49:
	      execNb = 1;
	      break;
	    case 50:
	      execNb = 2;
	      break;
	    case 51:
	      execNb = 3;
	      break;
	    default:
	      printf("erreur, veuillez choisir un nombre entre 1, 2 ou  3.");
	    }
	  return execNb;

    }
  return 0;
}

void write_log(char **envp, int execNb)
{
    //Chargement de l'heure
   time_t now = time (NULL);
   struct tm tm_now = *localtime (&now);
   char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];
   strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);

   char *taille;
   taille = malloc(256*sizeof(char*));
   taille = getenv("EXIASAVER2_TAILLE");
   if(strcmp(taille, "DEFAULT") == 0)
     {
       taille = "1";
     }
   
    char tab[256];
 
    FILE* log = NULL;
 
    log = fopen("./logs/log.txt","a+");
 
    switch (execNb)
    {
    case 1:
        sprintf(tab,"[%s]|%d",s_now,execNb);
        fprintf(log,"%s",tab);
        break;
    case 2:
        sprintf(tab,"[%s]|%d;%s|\n",s_now,execNb,taille);
        fprintf(log,"%s",tab);
        break;
    case 3:
        sprintf(tab,"[%s]|%d|\n",s_now,execNb);
        fprintf(log,"%s",tab);
        break;
    }
 
    fclose(log);
    printf("\n(Logs edited)");
 
}

void date_log()
{
    FILE* log = NULL;
    int caractereActuel;
 
    //Par dates
    printf("\n\n\nEcriture des Logs par date :\n\n");
    log = fopen("./logs/log.txt","r");
 
 
    do
        {
            caractereActuel = fgetc(log);
            printf("%c", caractereActuel);
        } while (caractereActuel != EOF);
 
    fclose(log);
}
 
void type_log()
{
    int i;
    FILE* log = NULL;
    int caractereActuel;
    //Par types;
    printf("\n\n\nEcriture des Logs par types:\n\n");
    log = fopen("./logs/log.txt","r");
 
    //Lecture du type
 
    //Premier check du premier type
    printf("Statique :\n");
    fseek(log, 0, SEEK_SET);
 
    do
        {
            fseek(log, +22, SEEK_CUR); // VAS AU CARACTERE 22
            caractereActuel = fgetc(log);
            if (caractereActuel == '1') //SI le caractere est du type 1 Alors il affiche la ligne de log
            {
                fseek(log, -23, SEEK_CUR);
                for (i=0;i<34;i++)
                {
                    caractereActuel = fgetc(log);
                    printf("%c",caractereActuel);
                }
                printf("\n");
 
            }
            while ((caractereActuel != '\n')&&(caractereActuel != EOF))
            {
                caractereActuel = fgetc(log);
            }
        } while (caractereActuel != EOF);
 
    printf("\nDynamique :\n");
 
    //Deuxieme check pour le deuxieme type
    fseek(log, 0, SEEK_SET);
    do
        {
            fseek(log, +22, SEEK_CUR); // VAS AU CARACTERE 22
            caractereActuel = fgetc(log);
            if (caractereActuel == '2') //SI le caractere est du type 1 Alors il affiche la ligne de log
            {
                fseek(log, -23, SEEK_CUR);
                for (i=0;i<26;i++)
                {
                    caractereActuel = fgetc(log);
                    printf("%c",caractereActuel);
                }
                printf("\n");
 
            }
            while ((caractereActuel != '\n')&&(caractereActuel != EOF))
            {
                caractereActuel = fgetc(log);
            }
        } while (caractereActuel != EOF);
 
    printf("\nInteractif :\n");
 
    //Troisieme check pour le troisieme type
    fseek(log, 0, SEEK_SET);
    do
        {
            fseek(log, +22, SEEK_CUR); // VAS AU CARACTERE 22
            caractereActuel = fgetc(log);
            if (caractereActuel == '3') //SI le caractere est du type 1 Alors il affiche la ligne de log
            {
                fseek(log, -23, SEEK_CUR);
                for (i=0;i<24;i++)
                {
                    caractereActuel = fgetc(log);
                    printf("%c",caractereActuel);
                }
                printf("\n");
 
            }
            while ((caractereActuel != '\n')&&(caractereActuel != EOF))
            {
                caractereActuel = fgetc(log);
            }
        } while (caractereActuel != EOF);
 
 
    fclose(log);
 
}
 
void nom_log()
{
    FILE* log = NULL;
    int i;
    int caractereActuel;
 
    printf("Tri des statiques par nom :");
    log = fopen("./logs/log.txt","r");
    printf("\n\nstat_1.pbm :\n\n");
    fseek(log, 0, SEEK_SET);
 
    do
        {
            fseek(log, +22, SEEK_CUR); // VAS AU CARACTERE 22
            caractereActuel = fgetc(log);
            if (caractereActuel == '1') //SI le on lit le type 1
            {
                fseek(log, -23, SEEK_CUR);
                fseek(log, +29, SEEK_CUR);
 
                caractereActuel = fgetc(log);
                if (caractereActuel == '1')
                {
                    fseek(log, -30, SEEK_CUR);
                    for (i=0;i<34;i++)
                    {
                        caractereActuel = fgetc(log);
                        printf("%c",caractereActuel);
                    }
                    printf("\n");
 
                }
            }
            while ((caractereActuel != '\n')&&(caractereActuel != EOF))
            {
                caractereActuel = fgetc(log);
            }
        } while (caractereActuel != EOF);
 
    printf("\n\nstat_2.pbm :\n\n");
    fseek(log, 0, SEEK_SET);
 
    do
        {
            fseek(log, +22, SEEK_CUR); // VAS AU CARACTERE 22
            caractereActuel = fgetc(log);
            if (caractereActuel == '1') //SI le on lit le type 1
            {
                fseek(log, -23, SEEK_CUR);
                fseek(log, +29, SEEK_CUR);
 
                caractereActuel = fgetc(log);
                if (caractereActuel == '2')
                {
                    fseek(log, -30, SEEK_CUR);
                    for (i=0;i<34;i++)
                    {
                        caractereActuel = fgetc(log);
                        printf("%c",caractereActuel);
                    }
                    printf("\n");
 
                }
            }
            while ((caractereActuel != '\n')&&(caractereActuel != EOF))
            {
                caractereActuel = fgetc(log);
            }
        } while (caractereActuel != EOF);
 
    printf("\n\nstat_3.pbm :\n\n");
    fseek(log, 0, SEEK_SET);
 
    do
        {
            fseek(log, +22, SEEK_CUR); // VAS AU CARACTERE 22
            caractereActuel = fgetc(log);
            if (caractereActuel == '1') //SI le on lit le type 1
            {
                fseek(log, -23, SEEK_CUR);
                fseek(log, +29, SEEK_CUR);
 
                caractereActuel = fgetc(log);
                if (caractereActuel == '3')
                {
                    fseek(log, -30, SEEK_CUR);
                    for (i=0;i<34;i++)
                    {
                        caractereActuel = fgetc(log);
                        printf("%c",caractereActuel);
                    }
                    printf("\n");
 
                }
            }
            while ((caractereActuel != '\n')&&(caractereActuel != EOF))
            {
                caractereActuel = fgetc(log);
            }
        } while (caractereActuel != EOF);
 
    fclose(log);
 
 
 
}
