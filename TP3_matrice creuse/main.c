#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

int main() {
    int ligne, col, val;
    int ligne_1, col_1, ligne_2, col_2;
    matrice_creuse matrice;
    matrice_creuse matrice_2;
    int marche = 1;
    int remplir = 0;
    char fonction,n;
    int choix = 0;
    while (marche == 1) {
        printf("\n");
        printf("    1. Remplir une matrice creuse\n");
        printf("    2. Afficher une matrice creuse sous forme de tableau\n");
        printf("    3. Afficher une matrice creuse sous forme de listes\n");
        printf("    4. Donner la valeur d¡¯un ¨¦l¨¦ment d¡¯une matrice creuse\n");
        printf("    5. Affecter une valeur ¨¤ un ¨¦l¨¦ment d¡¯une matrice creuse\n");
        printf("    6. Additionner deux matrices creuses\n");
        printf("    7. Calculer le gain en espace en utilisant cette repr¨¦sentation pour une matrice donn¨¦e\n");
        printf("    8. Quitter\n");
        printf("\n");
        printf(" Veuillez s¨¦lectionner une fonction [1-8]\n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            printf("combien de lignes de m ?\n");
            scanf("%d", &ligne);
            printf("combien de col de m ?\n");
            scanf("%d", &col);
            remplirMatrice(&matrice, ligne, col);
            afficherMatrice(matrice);
            printf("Op¨¦ration r¨¦ussie\n");
            remplir = 1;
            break;
        case 2:
            if (remplir == 1) {
                afficherMatrice(matrice);
            }
            else {
                printf("Veuillez d'abord remplir une matrice \n");
            }
            break;
        case 3:
            if (remplir == 1) {
                afficherMatriceListes(matrice);
            }
            else {
                printf("Veuillez d'abord remplir une matrice \n");
            }
            break;
        case 4:
            printf("la ligne de l'element recherch¨¦ ?(l'indice de la premi¨¨re ligne est 0)\n");
            scanf("%d", &ligne);
            printf("la colone de l'element recherch¨¦ ?(l'indice de la premi¨¨re colone est 0)\n");
            scanf("%d", &col);
            printf("l'element recherch¨¦ est %d \n", rechercherValeur(matrice, ligne, col));
            break;
        case 5:
            printf("la ligne de l'element ¨¤ affecter ?(l'indice de la premi¨¨re ligne est 0)\n");
            scanf("%d", &ligne);
            printf("la colone de l'element ¨¤ affecter ?(l'indice de la premi¨¨re colone est 0)\n");
            scanf("%d", &col);
            printf("le valeur de l'element  ?\n");
            scanf("%d", &val);
            affecterValeur(matrice, ligne, col, val);
            afficherMatrice(matrice);
            break;
        case 6:
            printf("combien de lignes de m1 ?\n");
            scanf("%d", &ligne_1);
            printf("combien de col de m1 ?\n");
            scanf("%d", &col_1);
            remplirMatrice(&matrice, ligne_1, col_1);
            afficherMatrice(matrice);


            printf("combien de lignes de m2 ?\n");
            scanf("%d", &ligne_2);
            printf("combien de col de m2 ?\n");
            scanf("%d", &col_2);
            if (ligne_1 == ligne_2 && col_1 == col_2) {
                remplirMatrice(&matrice_2, ligne_2, col_2);
                afficherMatrice(matrice_2);

                additionerMatrices(matrice, matrice_2);
                printf("la somme des deux matrices est\n");
                afficherMatrice(matrice);
            }
            else {
                printf("les deux matrices n'ont pas la m¨ºme taille\n");
            }
            break;
        case 7:
            printf("le nombre d'octets gagn¨¦s est %d \n", nombreOctetsGagnes(matrice));
            break;
        case 8:
            supprimer_matrice(matrice);
            printf("Au revoir! \n");
            marche = 0;
            break;
        
        default:
            printf("Entrer un choix correcte SVP \n");
                break;
        }
       
    }
    return 0;
}