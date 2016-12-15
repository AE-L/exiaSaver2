#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>


typedef struct
{
    char* l1;
    char* l2;
    char* l3;
    char* l4;
    char* l5;

} NOMBRE1;

typedef struct
{
    char* l1;
    char* l2;
    char* l3;
    char* l4;
    char* l5;

} NOMBRE2;

typedef struct
{
    char* l1;
    char* l2;
    char* l3;
    char* l4;
    char* l5;

} NOMBRE3;

typedef struct
{
    char* l1;
    char* l2;
    char* l3;
    char* l4;
    char* l5;

} NOMBRE4;

typedef struct
{
    char* l1;
    char* l2;
    char* l3;
    char* l4;
    char* l5;

} NOMBRE5;

typedef struct
{
    char* l1;
    char* l2;
    char* l3;
    char* l4;
    char* l5;

} NOMBRE6;

void chargement_N1(NOMBRE1 *nb1,char tab_HEURE[25], char *CHEMIN_IMAGES)
{
    //Variables
    int i;
    char caractereActuel;
    FILE* nombre1 = NULL;

    int h1 = 0;

    switch (tab_HEURE[11])
    {
        case '1':
        h1 = 1;
        break;
        case '2':
        h1 = 2;
        break;
        case '3':
        h1 = 3;
        break;
        case '4':
        h1 = 4;
        break;
        case '5':
        h1 = 5;
        break;
        case '6':
        h1 = 6;
        break;
        case '7':
        h1 = 7;
        break;
        case '8':
        h1 = 8;
        break;
        case '9':
        h1 = 9;
        break;

    }


    //Chargement de l'heure
    char* heure;
    heure = malloc(256*sizeof(char*));

    if(strcmp(CHEMIN_IMAGES, "") != 0)
      sprintf(heure, "%s%d.pbm", CHEMIN_IMAGES, h1);
    else
      sprintf(heure, "numbers/%d.pbm", h1);

    nombre1 = fopen(heure,"r");

    //VIDAGE DE l'entete
    for (i=0;i<8;i++)
    {
        caractereActuel = fgetc(nombre1);
    }
    //Chargement du chiffre
    for (i=0;i<6;i++)
    {
        nb1->l1[i] = fgetc(nombre1);
    }
    for (i=0;i<6;i++)
    {
        nb1->l2[i] = fgetc(nombre1);
    }
    for (i=0;i<6;i++)
    {
        nb1->l3[i] = fgetc(nombre1);
    }
    for (i=0;i<6;i++)
    {
        nb1->l4[i] = fgetc(nombre1);
    }
    for (i=0;i<6;i++)
    {
        nb1->l5[i] = fgetc(nombre1);
    }
    fclose(nombre1);

}

void chargement_N2(NOMBRE2 *nb2,char tab_HEURE[25], char *CHEMIN_IMAGES)
{
    int i;
    int caractereActuel;
    FILE* nombre2 = NULL;

    int h2 = 2;


    switch (tab_HEURE[12])
    {
        case '1':
        h2 = 1;
        break;
        case '2':
        h2 = 2;
        break;
        case '3':
        h2 = 3;
        break;
        case '4':
        h2 = 4;
        break;
        case '5':
        h2 = 5;
        break;
        case '6':
        h2 = 6;
        break;
        case '7':
        h2 = 7;
        break;
        case '8':
        h2 = 8;
        break;
        case '9':
        h2 = 9;
        break;

    }

   //Allocation du chifre 2


    //Chargement de l'heure
    char* heure;
    heure = malloc(256*sizeof(char*));
    
    if(strcmp(CHEMIN_IMAGES, "") != 0)
      sprintf(heure, "%s%d.pbm", CHEMIN_IMAGES, h2);
    else
      sprintf(heure, "numbers/%d.pbm", h2);

    nombre2 = fopen(heure,"r");

    //VIDAGE DE l'entete
    for (i=0;i<8;i++)
    {
        caractereActuel = fgetc(nombre2);
    }

    //Chargement du chiffre
    for (i=0;i<6;i++)
    {
        nb2->l1[i] = fgetc(nombre2);
    }
    for (i=0;i<6;i++)
    {
        nb2->l2[i] = fgetc(nombre2);
    }
    for (i=0;i<6;i++)
    {
        nb2->l3[i] = fgetc(nombre2);
    }
    for (i=0;i<6;i++)
    {
        nb2->l4[i] = fgetc(nombre2);
    }
    for (i=0;i<6;i++)
    {
        nb2->l5[i] = fgetc(nombre2);
    }
    fclose(nombre2);
}


void chargement_N3(NOMBRE3 *nb3,char tab_HEURE[25], char *CHEMIN_IMAGES)
{
    int i;
    int caractereActuel;
    FILE* nombre3 = NULL;

    int h3 = 3;

    switch (tab_HEURE[14])
    {
        case '1':
        h3 = 1;
        break;
        case '2':
        h3 = 2;
        break;
        case '3':
        h3 = 3;
        break;
        case '4':
        h3 = 4;
        break;
        case '5':
        h3 = 5;
        break;
        case '6':
        h3 = 6;
        break;
        case '7':
        h3 = 7;
        break;
        case '8':
        h3 = 8;
        break;
        case '9':
        h3 = 9;
        break;

    }

    
    //Allocation du chifre 3


    //Chargement de l'heure
    char* heure;
    heure = malloc(256*sizeof(char*));
    
    if(strcmp(CHEMIN_IMAGES, "") != 0)
      sprintf(heure, "%s%d.pbm", CHEMIN_IMAGES, h3);
    else
      sprintf(heure, "numbers/%d.pbm", h3);;

    nombre3 = fopen(heure,"r");

    //VIDAGE DE l'entete
    for (i=0;i<8;i++)
    {
        caractereActuel = fgetc(nombre3);
    }

    //Chargement du chiffre
    for (i=0;i<6;i++)
    {
        nb3->l1[i] = fgetc(nombre3);
    }
    for (i=0;i<6;i++)
    {
        nb3->l2[i] = fgetc(nombre3);
    }
    for (i=0;i<6;i++)
    {
        nb3->l3[i] = fgetc(nombre3);
    }
    for (i=0;i<6;i++)
    {
        nb3->l4[i] = fgetc(nombre3);
    }
    for (i=0;i<6;i++)
    {
        nb3->l5[i] = fgetc(nombre3);
    }
    fclose(nombre3);

}

void chargement_N4(NOMBRE4 *nb4,char tab_HEURE[25], char *CHEMIN_IMAGES)
{
    int i;
    int caractereActuel;
    FILE* nombre4 = NULL;

    int h4 = 0;

    switch (tab_HEURE[15])
    {
        case '1':
        h4 = 1;
        break;
        case '2':
        h4 = 2;
        break;
        case '3':
        h4 = 3;
        break;
        case '4':
        h4 = 4;
        break;
        case '5':
        h4 = 5;
        break;
        case '6':
        h4 = 6;
        break;
        case '7':
        h4 = 7;
        break;
        case '8':
        h4 = 8;
        break;
        case '9':
        h4 = 9;
        break;

    }
     //Allocation du chifre 4
    
    //Chargement de l'heure
    char* heure;
    heure = malloc(256*sizeof(char*));
    
    if(strcmp(CHEMIN_IMAGES, "") != 0)
      sprintf(heure, "%s%d.pbm", CHEMIN_IMAGES, h4);
    else
      sprintf(heure, "numbers/%d.pbm", h4);;

    nombre4 = fopen(heure,"r");

    //VIDAGE DE l'entete
    for (i=0;i<8;i++)
    {
        caractereActuel = fgetc(nombre4);
    }

    //Chargement du chiffre
    for (i=0;i<6;i++)
    {
        nb4->l1[i] = fgetc(nombre4);
    }
    for (i=0;i<6;i++)
    {
        nb4->l2[i] = fgetc(nombre4);
    }
    for (i=0;i<6;i++)
    {
        nb4->l3[i] = fgetc(nombre4);
    }
    for (i=0;i<6;i++)
    {
        nb4->l4[i] = fgetc(nombre4);
    }
    for (i=0;i<6;i++)
    {
        nb4->l5[i] = fgetc(nombre4);
    }
    fclose(nombre4);

}

void chargement_N5(NOMBRE5 *nb5,char tab_HEURE[25], char *CHEMIN_IMAGES)
{
    int i;
    int caractereActuel;
    FILE* nombre5 = NULL;

    int h5 = 5;

    switch (tab_HEURE[17])
    {
        case '1':
        h5 = 1;
        break;
        case '2':
        h5 = 2;
        break;
        case '3':
        h5 = 3;
        break;
        case '4':
        h5 = 4;
        break;
        case '5':
        h5 = 5;
        break;
        case '6':
        h5 = 6;
        break;
        case '7':
        h5 = 7;
        break;
        case '8':
        h5 = 8;
        break;
        case '9':
        h5 = 9;
        break;

    }

    //Allocation du chifre 5
    

    //Chargement de l'heure
    char* heure;
    heure = malloc(256*sizeof(char*));
    
    if(strcmp(CHEMIN_IMAGES, "") != 0)
      sprintf(heure, "%s%d.pbm", CHEMIN_IMAGES, h5);
    else
      sprintf(heure, "numbers/%d.pbm", h5);

    nombre5 = fopen(heure,"r");

    //VIDAGE DE l'entete
    for (i=0;i<8;i++)
    {
        caractereActuel = fgetc(nombre5);
    }

    //Chargement du chiffre
    for (i=0;i<6;i++)
    {
        nb5->l1[i] = fgetc(nombre5);
    }
    for (i=0;i<6;i++)
    {
        nb5->l2[i] = fgetc(nombre5);
    }
    for (i=0;i<6;i++)
    {
        nb5->l3[i] = fgetc(nombre5);
    }
    for (i=0;i<6;i++)
    {
        nb5->l4[i] = fgetc(nombre5);
    }
    for (i=0;i<6;i++)
    {
        nb5->l5[i] = fgetc(nombre5);
    }
    fclose(nombre5);

}

void chargement_N6(NOMBRE6 *nb6,char tab_HEURE[25],  char *CHEMIN_IMAGES)
{
    int i;
    int caractereActuel;
    FILE* nombre6 = NULL;

    int h6 = 0;

    switch (tab_HEURE[18])
    {
        case '1':
        h6 = 1;
        break;
        case '2':
        h6 = 2;
        break;
        case '3':
        h6 = 3;
        break;
        case '4':
        h6 = 4;
        break;
        case '5':
        h6 = 5;
        break;
        case '6':
        h6 = 6;
        break;
        case '7':
        h6 = 7;
        break;
        case '8':
        h6 = 8;
        break;
        case '9':
        h6 = 9;
        break;

    }

     //Allocation du chifre 5
    

    //Chargement de l'heure
    char* heure;
    heure = malloc(256*sizeof(char*));
    
    if(strcmp(CHEMIN_IMAGES, "") != 0)
      sprintf(heure, "%s%d.pbm", CHEMIN_IMAGES, h6);
    else
      sprintf(heure, "numbers/%d.pbm", h6);

    nombre6 = fopen(heure,"r");

    //VIDAGE DE l'entete
    for (i=0;i<8;i++)
    {
        caractereActuel = fgetc(nombre6);
    }

    //Chargement du chiffre 6
    for (i=0;i<6;i++)
    {
        nb6->l1[i] = fgetc(nombre6);
    }
    for (i=0;i<6;i++)
    {
        nb6->l2[i] = fgetc(nombre6);
    }
    for (i=0;i<6;i++)
    {
        nb6->l3[i] = fgetc(nombre6);
    }
    for (i=0;i<6;i++)
    {
        nb6->l4[i] = fgetc(nombre6);
    }
    for (i=0;i<6;i++)
    {
        nb6->l5[i] = fgetc(nombre6);
    }
    fclose(nombre6);



}

void affichage_L1(NOMBRE1 *nb1,NOMBRE2 *nb2,NOMBRE3 *nb3,NOMBRE4 *nb4,NOMBRE5 *nb5,NOMBRE6 *nb6,int taille)
{
    int i;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int centrage_x;
    int centrage_y;
    int pos_x = 28;
    int pos_y = 5;
    int j;

    switch (taille)
    {
        case 1:
            
            centrage_x = ((w.ws_col - pos_x) / 2);
            centrage_y = ((w.ws_row - pos_y) / 2);

            for (i=0;i<centrage_y;i++)
            {
                printf("\n");
            }

            for (i=0;i<centrage_x;i++)
            {
                printf(" ");
            }

            //AFFICHAGE premiere Ligne
             //NB1
             for (i=0;i<6;i++)
            {
                switch (nb1->l1[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB2
            for (i=0;i<6;i++)
            {
                switch (nb2->l1[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("   ");
            //NB3
            for (i=0;i<6;i++)
            {
                switch (nb3->l1[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB4
            for (i=0;i<6;i++)
            {
                switch (nb4->l1[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("   ");
            //NB5
            for (i=0;i<6;i++)
            {
                switch (nb5->l1[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB6
            for (i=0;i<6;i++)
            {
                switch (nb6->l1[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("\n");
        break;
        case 2:
            for (j=0;j<2;j++)
            {

            pos_x = 45;
            pos_y = 10;

            centrage_x = ((w.ws_col - pos_x) / 2);
            centrage_y = ((w.ws_row - pos_y) / 2);
            system("clear");

            for (i=0;i<centrage_y;i++)
            {
                printf("\n");
            }

            for (i=0;i<centrage_x;i++)
            {
                printf(" ");
            }

            //AFFICHAGE premiere Ligne
             //NB1
             for (i=0;i<6;i++)
            {
                switch (nb1->l1[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB2
            for (i=0;i<6;i++)
            {
                switch (nb2->l1[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("   ");
            //NB3
            for (i=0;i<6;i++)
            {
                switch (nb3->l1[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB4
            for (i=0;i<6;i++)
            {
                switch (nb4->l1[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("   ");
            //NB5
            for (i=0;i<6;i++)
            {
                switch (nb5->l1[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB6
            for (i=0;i<6;i++)
            {
                switch (nb6->l1[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("\n");
            }

    }
    

}

void affichage_L2(NOMBRE1 *nb1,NOMBRE2 *nb2,NOMBRE3 *nb3,NOMBRE4 *nb4,NOMBRE5 *nb5,NOMBRE6 *nb6,int taille)
{
    int i;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int centrage_x;
    int centrage_y;
    int pos_x = 28;
    int pos_y = 5;
    int j;

    switch (taille)
    {
        case 1:
            
            centrage_x = ((w.ws_col - pos_x) / 2);
            centrage_y = ((w.ws_row - pos_y) / 2);


            for (i=0;i<centrage_x;i++)
            {
                printf(" ");
            }

            //AFFICHAGE premiere Ligne
             //NB1
             for (i=0;i<6;i++)
            {
                switch (nb1->l2[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB2
            for (i=0;i<6;i++)
            {
                switch (nb2->l2[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" █ ");
            //NB3
            for (i=0;i<6;i++)
            {
                switch (nb3->l2[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB4
            for (i=0;i<6;i++)
            {
                switch (nb4->l2[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" █ ");
            //NB5
            for (i=0;i<6;i++)
            {
                switch (nb5->l2[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB6
            for (i=0;i<6;i++)
            {
                switch (nb6->l2[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("\n");
        break;
        case 2:
            for (j=0;j<2;j++)
            {

            pos_x = 45;
            pos_y = 10;

            centrage_x = ((w.ws_col - pos_x) / 2);
            centrage_y = ((w.ws_row - pos_y) / 2);

            for (i=0;i<centrage_x;i++)
            {
                printf(" ");
            }

            //AFFICHAGE premiere Ligne
             //NB1
             for (i=0;i<6;i++)
            {
                switch (nb1->l2[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB2
            for (i=0;i<6;i++)
            {
                switch (nb2->l2[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" █ ");
            //NB3
            for (i=0;i<6;i++)
            {
                switch (nb3->l2[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB4
            for (i=0;i<6;i++)
            {
                switch (nb4->l2[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" █ ");
            //NB5
            for (i=0;i<6;i++)
            {
                switch (nb5->l2[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB6
            for (i=0;i<6;i++)
            {
                switch (nb6->l2[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("\n");
            }

    }

}

void affichage_L3(NOMBRE1 *nb1,NOMBRE2 *nb2,NOMBRE3 *nb3,NOMBRE4 *nb4,NOMBRE5 *nb5,NOMBRE6 *nb6,int taille)
{
    int i;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int centrage_x;
    int centrage_y;
    int pos_x = 28;
    int pos_y = 5;
    int j;

    switch (taille)
    {
        case 1:
            
            centrage_x = ((w.ws_col - pos_x) / 2);
            centrage_y = ((w.ws_row - pos_y) / 2);

            for (i=0;i<centrage_x;i++)
            {
                printf(" ");
            }

            //AFFICHAGE premiere Ligne
             //NB1
             for (i=0;i<6;i++)
            {
                switch (nb1->l3[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB2
            for (i=0;i<6;i++)
            {
                switch (nb2->l3[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("   ");
            //NB3
            for (i=0;i<6;i++)
            {
                switch (nb3->l3[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB4
            for (i=0;i<6;i++)
            {
                switch (nb4->l3[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("   ");
            //NB5
            for (i=0;i<6;i++)
            {
                switch (nb5->l3[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB6
            for (i=0;i<6;i++)
            {
                switch (nb6->l3[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("\n");
        break;
        case 2:
            for (j=0;j<2;j++)
            {

            pos_x = 45;
            pos_y = 10;

            centrage_x = ((w.ws_col - pos_x) / 2);
            centrage_y = ((w.ws_row - pos_y) / 2);

            for (i=0;i<centrage_x;i++)
            {
                printf(" ");
            }

            //AFFICHAGE premiere Ligne
             //NB1
             for (i=0;i<6;i++)
            {
                switch (nb1->l3[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB2
            for (i=0;i<6;i++)
            {
                switch (nb2->l3[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("   ");
            //NB3
            for (i=0;i<6;i++)
            {
                switch (nb3->l3[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB4
            for (i=0;i<6;i++)
            {
                switch (nb4->l3[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("   ");
            //NB5
            for (i=0;i<6;i++)
            {
                switch (nb5->l3[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB6
            for (i=0;i<6;i++)
            {
                switch (nb6->l3[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("\n");
            }

    }

}

void affichage_L4(NOMBRE1 *nb1,NOMBRE2 *nb2,NOMBRE3 *nb3,NOMBRE4 *nb4,NOMBRE5 *nb5,NOMBRE6 *nb6,int taille)
{
    int i;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int centrage_x;
    int centrage_y;
    int pos_x = 28;
    int pos_y = 5;
    int j;

    switch (taille)
    {
        case 1:
            
            centrage_x = ((w.ws_col - pos_x) / 2);
            centrage_y = ((w.ws_row - pos_y) / 2);

            for (i=0;i<centrage_x;i++)
            {
                printf(" ");
            }

            //AFFICHAGE premiere Ligne
             //NB1
             for (i=0;i<6;i++)
            {
                switch (nb1->l4[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB2
            for (i=0;i<6;i++)
            {
                switch (nb2->l4[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" █ ");
            //NB3
            for (i=0;i<6;i++)
            {
                switch (nb3->l4[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB4
            for (i=0;i<6;i++)
            {
                switch (nb4->l4[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" █ ");
            //NB5
            for (i=0;i<6;i++)
            {
                switch (nb5->l4[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB6
            for (i=0;i<6;i++)
            {
                switch (nb6->l4[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("\n");
        break;
        case 2:
            for (j=0;j<2;j++)
            {

            pos_x = 45;
            pos_y = 10;

            centrage_x = ((w.ws_col - pos_x) / 2);
            centrage_y = ((w.ws_row - pos_y) / 2);

            for (i=0;i<centrage_x;i++)
            {
                printf(" ");
            }

            //AFFICHAGE premiere Ligne
             //NB1
             for (i=0;i<6;i++)
            {
                switch (nb1->l4[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB2
            for (i=0;i<6;i++)
            {
                switch (nb2->l4[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" █ ");
            //NB3
            for (i=0;i<6;i++)
            {
                switch (nb3->l4[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB4
            for (i=0;i<6;i++)
            {
                switch (nb4->l4[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" █ ");
            //NB5
            for (i=0;i<6;i++)
            {
                switch (nb5->l4[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB6
            for (i=0;i<6;i++)
            {
                switch (nb6->l4[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("\n");
            }

    }

}

void affichage_L5(NOMBRE1 *nb1,NOMBRE2 *nb2,NOMBRE3 *nb3,NOMBRE4 *nb4,NOMBRE5 *nb5,NOMBRE6 *nb6,int taille)
{
    int i;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    int centrage_x;
    int centrage_y;
    int pos_x = 28;
    int pos_y = 5;
    int j;

    switch (taille)
    {
        case 1:
            
            centrage_x = ((w.ws_col - pos_x) / 2);
            centrage_y = ((w.ws_row - pos_y) / 2);

            for (i=0;i<centrage_x;i++)
            {
                printf(" ");
            }

            //AFFICHAGE premiere Ligne
             //NB1
             for (i=0;i<6;i++)
            {
                switch (nb1->l5[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB2
            for (i=0;i<6;i++)
            {
                switch (nb2->l5[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("   ");
            //NB3
            for (i=0;i<6;i++)
            {
                switch (nb3->l5[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB4
            for (i=0;i<6;i++)
            {
                switch (nb4->l5[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("   ");
            //NB5
            for (i=0;i<6;i++)
            {
                switch (nb5->l5[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf(" ");
            //NB6
            for (i=0;i<6;i++)
            {
                switch (nb6->l5[i])
                {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf("█");
                    break;
                }

            }
            printf("\n");
        break;
        case 2:
            for (j=0;j<2;j++)
            {

            pos_x = 45;
            pos_y = 10;

            centrage_x = ((w.ws_col - pos_x) / 2);
            centrage_y = ((w.ws_row - pos_y) / 2);

            for (i=0;i<centrage_x;i++)
            {
                printf(" ");
            }

            //AFFICHAGE premiere Ligne
             //NB1
             for (i=0;i<6;i++)
            {
                switch (nb1->l5[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB2
            for (i=0;i<6;i++)
            {
                switch (nb2->l5[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("   ");
            //NB3
            for (i=0;i<6;i++)
            {
                switch (nb3->l5[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB4
            for (i=0;i<6;i++)
            {
                switch (nb4->l5[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("   ");
            //NB5
            for (i=0;i<6;i++)
            {
                switch (nb5->l5[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf(" ");
            //NB6
            for (i=0;i<6;i++)
            {
                switch (nb6->l5[i])
                {
                case '0':
                    printf("  ");
                    break;
                case '1':
                    printf("██");
                    break;
                }

            }
            printf("\n");
            }

    }

}

void allocation(NOMBRE1 *nb1,NOMBRE2 *nb2,NOMBRE3 *nb3,NOMBRE4 *nb4,NOMBRE5 *nb5,NOMBRE6 *nb6)
{
    nb1->l1 = malloc(6*(sizeof(char*)));
    nb1->l2 = malloc(6*(sizeof(char*)));
    nb1->l3 = malloc(6*(sizeof(char*)));
    nb1->l4 = malloc(6*(sizeof(char*)));
    nb1->l5 = malloc(6*(sizeof(char*)));

    nb2->l1 = malloc(6*(sizeof(char*)));
    nb2->l2 = malloc(6*(sizeof(char*)));
    nb2->l3 = malloc(6*(sizeof(char*)));
    nb2->l4 = malloc(6*(sizeof(char*)));
    nb2->l5 = malloc(6*(sizeof(char*)));

    nb3->l1 = malloc(6*(sizeof(char*)));
    nb3->l2 = malloc(6*(sizeof(char*)));
    nb3->l3 = malloc(6*(sizeof(char*)));
    nb3->l4 = malloc(6*(sizeof(char*)));
    nb3->l5 = malloc(6*(sizeof(char*)));

    nb4->l1 = malloc(6*(sizeof(char*)));
    nb4->l2 = malloc(6*(sizeof(char*)));
    nb4->l3 = malloc(6*(sizeof(char*)));
    nb4->l4 = malloc(6*(sizeof(char*)));
    nb4->l5 = malloc(6*(sizeof(char*)));

    nb5->l1 = malloc(6*(sizeof(char*)));
    nb5->l2 = malloc(6*(sizeof(char*)));
    nb5->l3 = malloc(6*(sizeof(char*)));
    nb5->l4 = malloc(6*(sizeof(char*)));
    nb5->l5 = malloc(6*(sizeof(char*)));

    nb6->l1 = malloc(6*(sizeof(char*)));
    nb6->l2 = malloc(6*(sizeof(char*)));
    nb6->l3 = malloc(6*(sizeof(char*)));
    nb6->l4 = malloc(6*(sizeof(char*)));
    nb6->l5 = malloc(6*(sizeof(char*)));



}

void free_free(NOMBRE1 *nb1,NOMBRE2 *nb2,NOMBRE3 *nb3,NOMBRE4 *nb4,NOMBRE5 *nb5,NOMBRE6 *nb6)
{
    free(nb1->l1);
    free(nb1->l2);
    free(nb1->l3);
    free(nb1->l4);
    free(nb1->l5);

    free(nb2->l1);
    free(nb2->l2);
    free(nb2->l3);
    free(nb2->l4);
    free(nb2->l5);

    free(nb3->l1);
    free(nb3->l2);
    free(nb3->l3);
    free(nb3->l4);
    free(nb3->l5);

    free(nb4->l1);
    free(nb4->l2);
    free(nb4->l3);
    free(nb4->l4);
    free(nb4->l5);

    free(nb5->l1);
    free(nb5->l2);
    free(nb5->l3);
    free(nb5->l4);
    free(nb5->l5);

    free(nb6->l1);
    free(nb6->l2);
    free(nb6->l3);
    free(nb6->l4);
    free(nb6->l5);

}



int main(char **envp)
{
  int sleep_var;
  system("clear");
  int taille;
    int i;
      
    NOMBRE1 nb1;
    NOMBRE2 nb2;
    NOMBRE3 nb3;
    NOMBRE4 nb4;
    NOMBRE5 nb5;
    NOMBRE6 nb6;

    char tab_HEURE[25];


    char *CHEMIN_IMAGES;
    CHEMIN_IMAGES = malloc(256*sizeof(char*));

    CHEMIN_IMAGES = getenv("EXIASAVER2_PBM");

    if(strcmp(CHEMIN_IMAGES, "DEFAULT") == 0)
      CHEMIN_IMAGES = "";
    else
      sprintf(CHEMIN_IMAGES, "%s/", CHEMIN_IMAGES);
    
    
    while (1)
    {
        time_t temps;
        struct tm date;
        time(&temps);
        date=*localtime(&temps);
        sprintf(tab_HEURE,"%s",asctime(&date));

        allocation(&nb1,&nb2,&nb3,&nb4,&nb5,&nb6);

        //Chargement des chffres dans des tableaux
        chargement_N1(&nb1,tab_HEURE, CHEMIN_IMAGES);
        chargement_N2(&nb2,tab_HEURE, CHEMIN_IMAGES);
        chargement_N3(&nb3,tab_HEURE, CHEMIN_IMAGES);
        chargement_N4(&nb4,tab_HEURE, CHEMIN_IMAGES);
        chargement_N5(&nb5,tab_HEURE, CHEMIN_IMAGES);
        chargement_N6(&nb6,tab_HEURE, CHEMIN_IMAGES);

        char *tailleEnv;
	tailleEnv = malloc(16*sizeof(char*));
        tailleEnv = getenv("EXIASAVER2_TAILLE");
        if(strcmp(tailleEnv, "DEFAULT") == 0  || strcmp(tailleEnv, "1") == 0)
        {
           taille = 1;
        }
        else
        {
           taille = 2;
        }

        //Affichage ligne par ligne des tableaux
        affichage_L1(&nb1,&nb2,&nb3,&nb4,&nb5,&nb6,taille);
        affichage_L2(&nb1,&nb2,&nb3,&nb4,&nb5,&nb6,taille);
        affichage_L3(&nb1,&nb2,&nb3,&nb4,&nb5,&nb6,taille);
        affichage_L4(&nb1,&nb2,&nb3,&nb4,&nb5,&nb6,taille);
        affichage_L5(&nb1,&nb2,&nb3,&nb4,&nb5,&nb6,taille);

        free_free(&nb1,&nb2,&nb3,&nb4,&nb5,&nb6);
        printf("\n");

        //Calcule la taille de la console.
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);

        int pos_x = 38;
        int centrage_x;
        centrage_x = ((w.ws_col - pos_x) / 2);

        for (i=0;i<centrage_x;i++)
        {
            printf(" ");
        }

        printf("Actualisation dans quelque insant ");

        char *sleep_varEnv;
	sleep_varEnv = malloc(16*sizeof(char*));
        sleep_varEnv = getenv("EXIASAVER2_SLEEP");
        if(strcmp(sleep_varEnv, "DEFAULT") == 0)
        {
	  sleep_var = 10;
        }
        else
        {
	  sleep_var = atoi(sleep_varEnv);
	  }
         // VARIABLE D'ENVIRONNEMENT POUR LE TEMPS DE PAUSE.

        for (i=0;i<sleep_var;i++)
        {
               printf(".");
               fflush(stdout);
               sleep(1);
        }
        system("clear");
    }
     
    return 0;
}
