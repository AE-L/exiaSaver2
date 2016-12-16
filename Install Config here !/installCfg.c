#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void readme();

int main()
{
  system("clear");
  char *user;
  char *exec;
  user = malloc(256*sizeof(char*));
  exec = malloc(256*sizeof(char*));
  user = getenv("USER");

  sprintf(exec, "/home/%s/.profile", user);
  printf("<%s>\n", exec);
		
  
  
    FILE* profile = NULL;
    profile = fopen(exec,"a+");
 
    fprintf(profile,"export EXIASAVER_HOME=DEFAULT\nexport EXIASAVER1_PBM=DEFAULT\n");
    fprintf(profile,"export EXIASAVER2_PBM=DEFAULT\nexport EXIASAVER2_TAILLE=DEFAULT\n");
    fprintf(profile,"export EXIASAVER2_SLEEP=DEFAULT\nexport EXIASAVER3_PBM=DEFAULT\n");
    fclose(profile);

    printf("Installation de la configuration terminée !\nVous pouvez toujours vous rendre dans ~/.profile pour éditer la configuration.\nCette configuration est permanente.\n");
    system("rm installCfg");

    readme();
 
 
  return 0;
}

void readme()
{
    FILE* readd = NULL;
    readd = fopen("READ ME.txt","a+");
    fprintf(readd,"Guide d'utilisation\n\nVeuillez ne pas supprimer ce fichier, et ne pas le déplacer.\n"
            "Ici vous trouverez tout les conseils et commandes pour utiliser à bien le screen saver.\n\n"
            "Lors de l'éxécution du launcher avec ./Launcher3.0 l'économiseur d'écran se lancera avec les paramètres par défaut, définis dans le .profile.\n"
            "Lors de l'éxécution du launcher avec ./Launcher3.0  -cfg l'économiseur d'écran vous demande de configurer ses paramètres expliqués ci dessous.\n"
            "Definitions des variables d'environnements :\nEXIASAVER_HOME : est le chemin du repertoire qui contient les executables statique, dynamique et interactif.\n"
            "EXIASAVER1_PBM : est le chemin du repertoire contenant les images statiques à afficher.\n"
            "EXIASAVER2_PBM : est le chemin du repertoire contenant les images dynamique à afficher.\n"
            "EXIASAVER2_TAILLE : est la taille des caracteres des chiffres pour l'heure, ici 1 ou 2.\n"
            "EXIASAVER2_SLEEP : est le temps entre deux rafraichisements pour l'affichage de l'heure.\n"
            "EXIASAVER3_PBM : est le chemin du repertoire contenant les images de l'avion.\n"
            "\nVous pouvez accéder à l'historique des lancements avec ./Launcher3.0 -stat , -stat peut être suivis d'un argument qui définira le tri de l'historique :\n"
            "name : pour trier par nom de fichier éxécutés.\n"
            "type : pour trier par types d'économiseur d'écran lancés.\n"
            "date : pour trier par ordre chronologique.\n"
            "\nA tout moment lors de l'éxécution d'un type d'économiseur d'écran, vous pouvez stopper son lancement lorsque vous voyez un décompte.\n"
            "Vous pouvez donc ainsi taper le type d'économiseur d'écran que vous voulez afficher ou bien selectionner quelle image afficher.");
    fclose(readd);
	
FILE* bashh = NULL;
sprintf(exec, "/home/%s/.bash_profile", user);
printf("<%s>\n", exec);
bashh = fopen(exec,"a+");
fprintf(bashh,"export EXIASAVER_HOME=DEFAULT\nexport EXIASAVER1_PBM=DEFAULT\n");
fprintf(bashh,"export EXIASAVER2_PBM=DEFAULT\nexport EXIASAVER2_TAILLE=DEFAULT\n");
fprintf(bashh,"export EXIASAVER2_SLEEP=DEFAULT\nexport EXIASAVER3_PBM=DEFAULT\n");
fclose(bashh);
 
}
