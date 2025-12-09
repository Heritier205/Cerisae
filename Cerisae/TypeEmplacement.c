//
// Created by herit on 12/9/2025.
//
#include <stdio.h>
#include <string.h>
#include "TypeEmplacement.h"

void AjouterEmplacement(const char *nomFichier) {
    char Ligne[50];
    float Prix;

    printf("Entrez le nom et le prix d'un emplacement Ex(Tente : 11,5)\n");
    printf("Ligne : ");
    scanf("%49s", Ligne);
    printf("Prix : ");
    scanf("%f", &Prix);

    FILE *f = fopen(nomFichier, "a+");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(f, "%s:%.2f\n", Ligne, Prix);
    fclose(f);
    printf("Emplacement ajoute avec succes.\n");
}

void supprimerEmplacement(const char *nomFichier){
    char Type[50];
    printf("Entrez le nom de l'emplacement a supprimer: ");
    scanf("%s", Type);

    //Ouverture du fichier
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    //Creation d'un fichier tmp
    FILE *tmp = fopen("fichierTmp", "w");
    if (tmp == NULL) {
        printf("Erreur lors de la creation du fichier.\n");
    }
    char Ligne[256];

    while (fgets(Ligne, sizeof(Ligne), f)){
        Ligne[strcspn(Ligne, "\n")] = '\0'; // supprime le \n de la fin
        char TypeLigne[50];
        sscanf(Ligne, "%[^:]", TypeLigne); // lit tout avant le ':'
        printf(TypeLigne);
        if(strcmp(Type, TypeLigne) != 0){
            fprintf(tmp, "%s\n", Ligne);
        }
    }
    //Fermeture des fichiers
    fclose(f);
    fclose(tmp);

    //Suppression de l'ancien fichier
    remove(nomFichier);

    //Changement du nom du fichier tmp
    rename("fichierTmp", nomFichier);
}

void ModifierEmplacement(const char *nomFichier) {
    char Type[50];
    printf("Entrez le nom de l'emplacement a modifier: ");
    scanf("%s", Type);

    //Ouverture du fichier
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    //Creation d'un fichier tmp
    FILE *tmp = fopen("fichierTmp", "w");
    if (tmp == NULL) {
        printf("Erreur lors de la creation du fichier.\n");
    }
    char Ligne[256];

    while (fgets(Ligne, sizeof(Ligne), f)){
        Ligne[strcspn(Ligne, "\n")] = '\0'; // supprime le \n de la fin
        char TypeLigne[50];
        sscanf(Ligne, "%[^:]", TypeLigne); // lit tout avant le ':'
        if(strcmp(Type, TypeLigne) != 0){
            fprintf(tmp, "%s\n", Ligne);
        }else{
            char Ligne[50];
            float Prix;
            printf("Entrez la modification: ");

            printf("Entrez le nom et les informations du nouvel emplacement\n");
            printf("Ligne : ");
            scanf("%49s", Ligne);
            printf("Prix : ");
            scanf("%f", &Prix);
            fprintf(tmp, "%s:%.2f\n", Ligne, Prix);
            printf("Emplacement modifie avec succes.\n");
        }
    }
    //Fermeture des fichiers
    fclose(f);
    fclose(tmp);

    //Suppression de l'ancien fichier
    remove(nomFichier);

    //Changement du nom du fichier tmp
    rename("fichierTmp", nomFichier);
}

void AfficherContenu(const char *nomFichier){
    char Ligne[256];
    FILE *f = fopen(nomFichier, "r");
    while (fgets(Ligne, sizeof(Ligne), f)){
        Ligne[strcspn(Ligne, "\n")] = '\0'; // supprime le \n de la fin
        printf("%s\n", Ligne);
    }
    fclose(f);
    printf("\n\n");
}