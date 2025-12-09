#include <stdio.h>
#include <string.h>
#include "TypeEmplacement.h"


int main(void) {

    char answer;
    char msg;
    do {
        printf("Entrez :\n");
        printf("(1) Ajouter un emplacement\n");
        printf("(2) Modifier un emplacement\n");
        printf("(3) Supprimer un emplacement\n");
        printf("(4) Afficher tous les emplacements\n");
        printf("(0) Quitter\n");
        printf("Votre choix : ");
        scanf(" %c", &answer);
        printf("\n");

        switch (answer) {
            case '1':
                do {
                    AjouterEmplacement("TypeEmplacement.txt");
                    printf("Voulez-vous entrer un autre emplacement (o/N) ? : ");
                    scanf(" %c", &msg);
                } while (msg == 'o' || msg == 'O');
                break;

            case '2':
                ModifierEmplacement("TypeEmplacement.txt");
                break;

            case '3':
                supprimerEmplacement("TypeEmplacement.txt");
                break;

            case '4':
                AfficherContenu("TypeEmplacement.txt");
                break;

            case '0':
                printf("Programme termine.\n");
                break;

            default:
                printf("Choix invalide.\n");
        }
    } while(answer != '0');
    return 0;
}



/*void createType() {
    char nom[50], nomFichier[60];
    printf("Entrez le nom du fichier : ");
    scanf("%49s", nom);
    sprintf(nomFichier, "%s.txt", nom);

    FILE *f = fopen(nomFichier, "w");
    if (f == NULL) {
        printf("Erreur lors de la creation du fichier.\n");
    } else {
        fclose(f);
        printf("Le fichier %s a ete cree avec succes\n", nomFichier);
    }
}*/






