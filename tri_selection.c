#include <stdio.h>
#include <stdlib.h>

#define SIZE 13 //pour le test

/*void TriParSelection(int tab[], int n){
    int i, j, tmp, cle;

    //afficher les éléments du tableau
    for (i = 0; i < n - 1; i++) {
        cle = i;
        for (j = i + 1; j < n; j++) {
            if (tab[j] < tab[cle])
                cle = j;
        }
        if (cle != i) {
            tmp = tab[i];
            tab[i] = tab[cle];
            tab[cle] = tmp;
        }
    }
}*/

void TriParSelection(int *tab, int n){
    int *fin = tab + n;

    for (int *i = tab; i < fin - 1; i++) {
        int *min = i;
        for (int *j = i + 1; j < fin; j++) {
            if (*j < *min)
                min = j;
        }
        if (min != i) {
            int tmp = *i;
            *i = *min;
            *min = tmp;
        }
    }
}

/*int tab[SIZE] = {
    17351570558593906905,
    5325446475583167886,
    12763656725177062400,
    17734056355270412886,
    12049546057232698227,
    11977938826048809358,
    18315042824748044599,
    12807838780062790681,
    3241083009075883601,
    17576884272599774708,
    10706611849450071391,
    11264361406761140511,
    14366474443203082141
};*/

int main()
{
    //Ouverture du fichier d'entrée
    FILE *file_in;
    file_in = fopen("references-test.txt", "r");
    if (file_in == NULL) {
        printf("Erreur lors de l'ouverture du fichier d'entrée.\n");
        return 1;
    }

    //Création du tableau contenant les références
    int *tab = (int *)malloc(SIZE * sizeof(int));
    if (tab == NULL) {
        printf("Allocation de mémoire a échoué.\n");
        fclose(file_in);
        return 1;
    }

    //Remplissage du tableau de références
    int i = 0;
    while (fscanf(file_in, "%d", &tab[i]) != EOF && i < SIZE) {
        i++;
    }
    fclose(file_in);

    // Tri par sélection du tableau
    TriParSelection(tab, SIZE);

    // Écriture du tableau trié dans le fichier de sortie

    /*FILE *file_out;
    file_out = fopen("references-tri-selection4.txt", "w");
    if (file_out == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sortie.\n");
        free(tab);
        return 1;
    }
    int i;
    for (i = 0; i < SIZE; i++) {
        fprintf(file_out, "%d ", tab[i]);
    }
    fclose(file_out);

    //Libération de la mémoire allouée
    free(tab);*/

    FILE *file_out;
    file_out = fopen("references-tri-selection6.txt", "w");
    if (file_out == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sortie.\n");
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        fprintf(file_out, "%d ", tab[i]);
    }
    fclose(file_out);

    return 0;
}

