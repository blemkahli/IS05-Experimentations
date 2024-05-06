#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

void selectionSort(int arr[], int n) {
    int i, j, minIndex, tmp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

int main() {
    FILE *file;
    file = fopen("references.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    int *tab = (int *)malloc(SIZE * sizeof(int));
    if (tab == NULL) {
        printf("Allocation de mémoire a échoué.\n");
        return 1;
    }

    int i = 0;
    while (fscanf(file, "%d", &tab[i]) != EOF && i < SIZE) {
        i++;
    }
    fclose(file);

    // Appliquer le tri par sélection
    selectionSort(tab, SIZE);

    // Afficher le tableau trié
    printf("******** tableau triée par ordre croissant ********\n");
    for (i = 0; i < SIZE; i++)
        printf("%d ", tab[i]);

    // Libérer la mémoire allouée pour le tableau
    free(tab);

    return 0;
}
