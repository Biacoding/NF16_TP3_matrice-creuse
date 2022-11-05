#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


// Fonction qui permet de créer un élement d'une liste chaînée
// Params : indice de colonne (int), valeur de l'élement (int)
// Return : pointeur vers le nouvel élement crée

element* creerElement(int colonne, int valeur) {
    element* nouvelElement = malloc(sizeof(element));
    nouvelElement->col = colonne; // (* nouvelElement).col = colonne
    nouvelElement->val = valeur;
    nouvelElement->suivant = NULL;
    return nouvelElement; // retouner un pointeur element* 
}


void remplirMatrice(matrice_creuse* m, int N, int M) {
    m->Nlignes = N;
    m->Ncolonnes = M;
    int i,j;
    int tmp = 0;
    element* dernier = NULL;
    (m->tab_lignes) = malloc(sizeof(liste_ligne) * N ); // table pour liste_ligne
    for (i = 0; i < N; i++)
    {
        (m->tab_lignes)[i] = NULL; //initialiser le pointeur liste_ligne i    // *(m->tab_lignes) = liste_ligne = element*
        for (j = 0; j < M; j++)
        {
            printf("Enter le nombre pour [%d] [%d]\n", i, j);
            scanf("%d", &tmp); 
            
            if (tmp != 0 && (m->tab_lignes)[i] != NULL )
            {
                dernier->suivant = creerElement(j, tmp); 
                dernier = dernier->suivant; 
            }
            //Placez en fin de fonction pour ne pas initialiser deux fois
            if (tmp != 0 && (m->tab_lignes)[i] == NULL )
            {
                (m->tab_lignes)[i] = creerElement(j, tmp);
                dernier = (m->tab_lignes)[i];
            } 
        } 
    }
}

void afficherMatrice(matrice_creuse m) {
    int i,j;
    element* ele;
    printf("La matrice creuse sous forme de tableau \n ");
    printf("\n");
    for (i = 0;i < m.Nlignes;i++) {
        ele = (m.tab_lignes)[i];
        for (j = 0;j < m.Ncolonnes;j++) {
            if (ele != NULL && j == ele->col) {
                printf(" %d ", ele->val);
                ele = ele->suivant;
                continue; // Passez à itération suivante sans verifier la deuxième condition
            }
            if (ele == NULL || j != ele->col  ) {
                printf(" 0 ");
                continue;
            }
        }
        printf("\n"); 
    }

    
}

void afficherMatriceListes(matrice_creuse m) {

    int i;
    element* ele;
    printf("Les listes chaînées de matrice creuse \n ");
    printf("\n");
    for (i = 0;i < m.Nlignes;i++) {
        printf(" ligne %d ：  ", i);
        ele = (m.tab_lignes)[i];
        while ( ele != NULL )
        {
            printf("  val %d |col %d   ", ele->val,ele->col); 
            ele = ele->suivant;
        }
        printf("\n");
    }
}

//Ecrire une fonction qui renvoie la valeur de l'élément de la ligne i et la colonne j de la matrice
int rechercherValeur(matrice_creuse m, int i, int j) {
    
    element* ele = (m.tab_lignes)[i]; //(l'indice de la première colone/ligne est 0) 
    while (ele != NULL && j > ele->col )
    {
        ele = ele->suivant;
    }
    if (ele != NULL && j == ele->col)
    {
       return ele->val;
    }
    if (ele == NULL || j < ele->col)
    {
        return 0;
    }
}

//Ecrire une fonction qui affecte une valeur donnée à l'élément de la ligne i et la colonne j de la matrice.
void affecterValeur(matrice_creuse m, int i, int j, int val) {
    
    if (val != rechercherValeur(m, i, j)) //condition pour ne pas réaffecter la même valeur 
    {
        element* ele = (m.tab_lignes)[i]; 
        element* pre = NULL ; //pre->suivant = ele
        int recherche = 0;
        while (ele != NULL && j > ele->col) // chercher la position de l'element
        {
            pre = ele;
            ele = ele->suivant;
            recherche = 1;
        }
        if (ele != NULL && j == ele->col) //l'element est déja existant et différant de 0
        {
            if (val != 0)
            {
                ele->val = val;
            }
            else
            {
                pre->suivant = ele->suivant;//si la valeur à affecter est 0,il faut supprimer l'element
                free(ele);
            }
        }
        else if (ele != NULL && j < ele->col) //insertion entre deux elements
        {
            if (recherche == 0) {
                (m.tab_lignes)[i] = creerElement(j, val); //insertion en tête
                (m.tab_lignes)[i]->suivant = ele;
            }
            else {
                pre->suivant = creerElement(j , val);
                (pre->suivant)->suivant = ele;
            }
        }
        else if (ele == NULL) //insertion en fin de ligne
        {
            if (recherche == 0) {
                (m.tab_lignes)[i] = creerElement(j, val);
            }
            else {
                pre->suivant = creerElement(j, val);
            }
        }
    }
}

//Ecrire une fonction qui réalise, de manière la plus optimisée possible, la somme de deux 
//matrices données de mêmes dimensions, et sauvegarde le résultat directement dans la
//première matrice(ne pas utiliser les fonctions getValue et putValue).Le prototype de la
//fonction est comme suit
void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {

    int i, j;
    int tmp = 0;
    int N_1, M_1, N_2, M_2;
    N_1 = m1.Nlignes;
    M_1 = m1.Ncolonnes;
    N_2 = m2.Nlignes;
    M_2 = m2.Ncolonnes;
        for (i = 0; i < N_1; i++)
        {
            for (j = 0; j < M_1; j++)
            {
                tmp = rechercherValeur(m1, i, j) + rechercherValeur(m2, i, j);
                affecterValeur(m1, i, j, tmp);
            }
        }
}

//Ecrire une fonction qui retourne le nombre d’octets gagnés par cette représentation pour une
//matrice creuse donnée(attention à bien tenir compte de la taille d’un entier et de la taille d’un
//pointeur)
int nombreOctetsGagnes(matrice_creuse m) {
    int oct = 0;
    int i;
    element* ele;
    int nb_ele = 0;
    int normal = 0;
    int nb_gagne = 0;
    for (i = 0;i < m.Nlignes;i++) {
        ele = (m.tab_lignes)[i];
        while (ele != NULL)
        {
            nb_ele++;
            ele = ele->suivant;
        }
    }
    oct = sizeof(m) + m.Nlignes * sizeof(liste_ligne) + nb_ele * sizeof(element);
    normal = sizeof(m) + m.Nlignes * m.Ncolonnes * sizeof(int); 
    nb_gagne = normal - oct;
    return nb_gagne;
}

void supprimer_matrice(matrice_creuse m) {
    int i;
    element* ele;
    for (i = 0;i < m.Nlignes;i++) {
        while (m.tab_lignes[i] != NULL )
        {
            
            ele = m.tab_lignes[i];
            m.tab_lignes[i] = ele->suivant;
            free(ele);
        }
    }
    free(m.tab_lignes);
    printf("Mémoire libérée avec succès \n");
}