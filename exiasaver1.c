#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char getch()
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

int kbhit(void)
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

char *forceimage(char *CHEMIN_IMAGE)
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

int my_rand()
{
    srand(time(NULL));
    int nbgen=rand()%3+1;
    return nbgen;
}

int position_X(char* CHEMINIMAGE)
{
    char tab_head[8];

    char tab_x[1];
    tab_x[0]=0;
    tab_x[1]=0;
  
    int i;
    int caractereActuel;
    int pos_x;
    FILE* image;

    image = fopen(CHEMINIMAGE,"r");
    if (!image) 
{
    printf("Failed to open text file\n");
    exit(1);
}

    for(i=0;i<8;i++)
            {
                caractereActuel = fgetc(image);
                tab_head[i] = caractereActuel;
            }
            fclose(image);

            //Detection de des dimension
            tab_x[0] = tab_head[4];
            tab_x[1] = tab_head[5];
            sscanf(tab_x, "%d", &pos_x);

    return pos_x;
}

int position_Y(char* CHEMINIMAGE)
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

char* load_screen(char* screen,char* CHEMINIMAGE)
{
    FILE* image;
    int caractereActuel;
    int i = 0;

    image = fopen(CHEMINIMAGE,"r");
    if (!image) 
    {
    printf("Failed to open text file\n");
    exit(1);
    }

    for (i=0;i<8;i++)
    {
        caractereActuel = fgetc(image);
    }

    do
        {
            caractereActuel = fgetc(image);
            screen[i] = caractereActuel;
            i++;

        } while (caractereActuel != EOF);
        fclose(image);

    return screen;
}

void affichage(char* screen, int pos_x, int pos_y)
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
    
    
    if (centrage_y != 0)
      {
    for (y=0;y<centrage_y;y++)
      {
        printf("\n");
      }
      }
    if (centrage_x != 0)
      {
    for (x=0;x<centrage_x;x++)
      {
        
        printf(" ");
      }
      }
    
    for (i=0;i<3850;i++)
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
                    if (j == 160)
                    {
                        j=0;
                        printf("\n");
            if (centrage_x != 0)
              {
                for (x=0;x<centrage_x;x++)
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

void write_log(char *CHEMIN_IMAGE)
{
  int i;
  int j = 0;
  int length = strlen(CHEMIN_IMAGE);
  char *IMAGE;
  char *IMAGEinversee;
  IMAGEinversee = malloc(256*sizeof(char*));
  IMAGE = malloc(256*sizeof(char*));

  printf("<%s>\n", CHEMIN_IMAGE);
  printf("%d\n", length);
  
  for(i=length-1; i>=0; i--, j++)
    {
      IMAGEinversee[j]=CHEMIN_IMAGE[i];
    }
  IMAGEinversee[j] = '\0';
  printf("<%s>\n", IMAGEinversee);

  IMAGEinversee = strtok(IMAGEinversee, "/");
  printf("<%s>\n", IMAGEinversee);

  length = strlen(IMAGEinversee);
  j = 0;
    for(i=length-1; i>=0; i--, j++)
    {
      IMAGE[j]=IMAGEinversee[i];
    }
  IMAGE[j] = '\0';
  printf("<%s>\n", IMAGE);
  
  
  FILE* log = NULL;
  log = fopen("./logs/log.txt","a+");
  char tab[256];

  sprintf(tab,"|%s\n",IMAGE);
  fprintf(log,"%s",tab);
  fclose(log);
}

int main()
{
  system("clear");
    char* screen;
    screen = malloc(3850*sizeof(char*));
    int x;

    int pos_y,pos_x;

    char* CHEMIN_IMAGE;
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

    write_log(CHEMIN_IMAGE);

    pos_x = position_X(CHEMIN_IMAGE);
    pos_y = position_Y(CHEMIN_IMAGE);

    load_screen(screen,CHEMIN_IMAGE);

    pid_t pid;
    pid =fork();
    if(pid == 0)
      {
	affichage(screen,pos_x,pos_y);
	getch();
      }
    else
      {
	wait(NULL);
      }


    free(screen);
    return 0;
}
