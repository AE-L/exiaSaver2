#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char getch()//Commande Getch recodé pour quitté le statique screen.
{
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
}

int kbhit(void)//Fonction utiliser dans l'arret du lancement automatique ( getchar qui n'arrete pas le programme).
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

char *forceimage(char *CHEMIN_IMAGE)// Fonction qui force un des screen saver choisie.
{
  char *token;
  token = malloc(256*sizeof(char*));

  int i;
  i = 3;
  printf("Appuyez sur n'importe quelle touche pour configurer l'image !\n");
  
  while(!kbhit())
    {
    printf("%d\n", i);
    fflush(stdout);
    sleep(1);
    i--;
    if(i == 0)
      {
	return CHEMIN_IMAGE;
      }
    }
  if(i != 0)
    {
      system("clear");
      printf("Veuillez rentrer le chemin vers votre image\n\n  > ");
      gets(token);
      
      for(i = 0 ; token[i] ; i++)
	token[i] = token[i+1];

      return token;
    }
  return 0;
}

int my_rand() //Tire un chiffre aléatoire entre 1 et 3 pour la selection de l'image a affiché.
{
    srand(time(NULL));
    int nbgen=rand()%3+1;
    return nbgen;
}

int position_X(char* CHEMINIMAGE)// Permet via l'entete du fichier pbm de lire la valeur x de la taille de l'image afficher
{
    char tab_head[8];//Definition du tableau dans lequel l'entete de l'image serra chargé

    char tab_x[1];//Definition du tableau qui contiendra la valeur x de la taille de l'image
    tab_x[0]=0;
    tab_x[1]=0;
  
    int i;
    int caractereActuel;
    int pos_x;
    FILE* image;

    image = fopen(CHEMINIMAGE,"r");//Ouverture de l'image
    if (!image) //si l'image n'a pas été ouverte alors un message d'erreur est affiché.
{
    printf("Failed to open text file\n");
    exit(1);
}

    for(i=0;i<8;i++)//Le tableau d'entete est remplie avec l'entete du fichier pbm
            {
                caractereActuel = fgetc(image);
                tab_head[i] = caractereActuel;
            }
            fclose(image);

            //Detection de des dimension
            tab_x[0] = tab_head[4];
            tab_x[1] = tab_head[5];
            sscanf(tab_x, "%d", &pos_x);//le tableau qui contient la taille x de l'image est converti en int.

    return pos_x;//La taille est retourner vers le main.
}

int position_Y(char* CHEMINIMAGE)//Fonctionnement identique que pour la pos X mais avec Y.
{
    char tab_head[8];

    char tab_y[1];
    tab_y[0] = 0;
    tab_y[1] = 0;

    int i;
    int caractereActuel;
    int pos_y;
    FILE* image;
    image = fopen(CHEMINIMAGE,"r");
    if (!image) 
    {
    printf("Failed to open text file\n");
    exit(1);
    }

    for(i=0;i<15;i++)
            {
                caractereActuel = fgetc(image);
                tab_head[i] = caractereActuel;
            }
            fclose(image);

            //Detection de des dimension
            tab_y[0] = tab_head[7];
            tab_y[1] = tab_head[8];
            sscanf(tab_y, "%d", &pos_y);

    return pos_y;
}

char* load_screen(char* screen,char* CHEMINIMAGE)// Fonction qui a pour role de charger l'image désirer dans un tableau : "screen".
{
    FILE* image;
    int caractereActuel;
    int i = 0;

    image = fopen(CHEMINIMAGE,"r");//Ouverture de l'image avec le chemin image qui lui vient du launcher.
    if (!image) //Si l'image n'est pas ouverte alors un message d'erreur est affiché.
    {
    printf("Failed to open text file\n");
    exit(1);
    }

    for (i=0;i<8;i++)//Cette boucle est chargé de vider l'entete de l'image
    {
        caractereActuel = fgetc(image);
    }

    do// cette boucle est charger de charger l'image dans le tableau screen.
        {
            caractereActuel = fgetc(image);
            screen[i] = caractereActuel;
            i++;

        } while (caractereActuel != EOF);// C'est a dire ici que que les éléments de l'image serront chargé tant que nous ne somme pas au bout du fichier.
        fclose(image);

    return screen;
}

void affichage(char* screen, int pos_x, int pos_y)//Cette fonction a pour but d'afficher l'image chargé dans le tableau au préalable.
{
    int centrage_x;
    int centrage_y;
    int j = 0;
    int i;
    int x;
    int y;
    
    //Calcule la taille de la console.
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    pos_x = 80;
    pos_y = 24;

    //Calcul du centre
    centrage_x = ((w.ws_col - pos_x) / 2);
    centrage_y = ((w.ws_row - pos_y) / 2);

    
    
    //Affcihe et centre.
    
    
    if (centrage_y != 0)//Si la taille de l'image n'est pas égal a la taille de la consle alors : on centre en Y
      {
    for (y=0;y<centrage_y;y++)
      {
        printf("\n");
      }
      }
    if (centrage_x != 0)
      {
    for (x=0;x<centrage_x;x++)//Puis on centre en X une première fois
      {
        
        printf(" ");
      }
      }
    
    for (i=0;i<3850;i++)//On affiche l'image
                {
                    switch(screen[i])
                    {
                    case '0':
                        printf(" ");
                        break;
                    case '1':
                        printf("█");
                        break;
                    }
                    if (j == 160)//Si on a lu 160 caractere, c'est a dire une ligne en comptant les espace entre les caracteres de l'image pbm :
                    {
                        j=0;
                        printf("\n");//Alors on revient a la ligne pour afficher
            if (centrage_x != 0)
              {
                for (x=0;x<centrage_x;x++)//Et on recentre en X
                  {
                printf(" ");
                  }
              }
                    }
                    else
                    {
                        j++;
                    }
                }
}

void write_log(char *CHEMIN_IMAGE)//Cette fonction est chargé de completer les LOGS ecrit par le launcher
{                                //En effet le laucnher lance le statique et ecrit dans les log l'heure a laquelle il la lancé
  int i;                        //Le statique complete alors la ligne avec le nom du fichier qu'il a lancer.
  int j = 0;
  int length = strlen(CHEMIN_IMAGE);//On mesure la taille du chemin de l'image
  char *IMAGE;
  char *IMAGEinversee;
  IMAGEinversee = malloc(256*sizeof(char*));
  IMAGE = malloc(256*sizeof(char*));

  printf("<%s>\n", CHEMIN_IMAGE);
  printf("%d\n", length);
  
  for(i=length-1; i>=0; i--, j++)//On inverse le chemin de l'image pour séparé le nom de l'image du chemin plus facilement
    {
      IMAGEinversee[j]=CHEMIN_IMAGE[i];
    }
  IMAGEinversee[j] = '\0';
  printf("<%s>\n", IMAGEinversee);

  IMAGEinversee = strtok(IMAGEinversee, "/");//On prend le nom de l'image qui se situe avant le /.
  printf("<%s>\n", IMAGEinversee);

  length = strlen(IMAGEinversee);
  j = 0;
    for(i=length-1; i>=0; i--, j++)//Puis on remet le nom de l'image a l'endroit
    {
      IMAGE[j]=IMAGEinversee[i];
    }
  IMAGE[j] = '\0';
  printf("<%s>\n", IMAGE);
  
  
  FILE* log = NULL;
  log = fopen("./logs/log.txt","a+");//On ouvre les logs et on écrit a la suite avec "a+".
  char tab[256];

  sprintf(tab,"|%s\n",IMAGE);//On fusionne un caractere et le nom de l'image.
  fprintf(log,"%s",tab);//On affiche le tableau qui contient le nom plus le caractere
  fclose(log);
}

int main()//Fonction principale qui vas servir a lancer les différente fonction
{
  system("clear");
    char* screen;
    screen = malloc(3850*sizeof(char*));
    int x;

    int pos_y,pos_x;

    char* CHEMIN_IMAGE;//Ces variables et commande servent à transformer la variable d'environement contenant le chemin de l'image en variable du programme.
    char* CHEMIN_token; //variable temporaire (utilisation sprintf)
    CHEMIN_IMAGE = malloc(256*sizeof(char*));
    CHEMIN_token = malloc(256*sizeof(char*));
    CHEMIN_IMAGE = getenv("EXIASAVER1_PBM");
    
    x = my_rand();


    //Selection du dossier des images
    if(strcmp(CHEMIN_IMAGE, "DEFAULT") == 0)//CHOIX DE L'IMAGE
      {
        switch (x)
          {
              case 1:
                CHEMIN_IMAGE = "./screensavers/stat_1.pbm";
                break;

              case 2:
                CHEMIN_IMAGE = "./screensavers/stat_2.pbm";
                break;

                  case 3:
                CHEMIN_IMAGE = "./screensavers/stat_3.pbm";
                break;
            }
     }

    else
      {
        switch (x)
            {

              case 1:
                sprintf(CHEMIN_token, "%s%s", CHEMIN_IMAGE, "/stat_1.pbm");
                CHEMIN_IMAGE = CHEMIN_token;
                break;

              case 2:
                sprintf(CHEMIN_token, "%s%s", CHEMIN_IMAGE, "/stat_2.pbm");
                CHEMIN_IMAGE = CHEMIN_token;
                break;

              case 3:
                sprintf(CHEMIN_token, "%s%s", CHEMIN_IMAGE, "/stat_3.pbm");
                CHEMIN_IMAGE = CHEMIN_token;
                break;
            }
        }
    CHEMIN_IMAGE = forceimage(CHEMIN_IMAGE); //l'utilisateur peut selectionner une autre image que celles proposées.
    system("clear");

    write_log(CHEMIN_IMAGE);//On complete ici les logs qu'a commencé le launcher

    pos_x = position_X(CHEMIN_IMAGE);//On cherche la taille de l'image en X
    pos_y = position_Y(CHEMIN_IMAGE);//Idem pour Y

    load_screen(screen,CHEMIN_IMAGE);//On charge l'image

    pid_t pid;
    pid =fork();//On lance l'affichage de l'image avec un fork();
    if(pid == 0)
      {
	affichage(screen,pos_x,pos_y);
	getch();//Getch sert ici passer a la suite du programme lors du pressage de n'importe quelle touche.
      }
    else
      {
	wait(NULL);
      }


    free(screen);
    return 0;
}
