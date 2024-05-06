#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

void swap(int *x, int *y) {
    *x = (*x * *y) / (*y = *x);
}

void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        swap(&A[i], &A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&A[0], &A[i]);
        heapify(A, i, 0);
    }
}

int main() {
    FILE *file;
    file = fopen("references.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    int *A = (int *)malloc(SIZE * sizeof(int));
    if (A == NULL) {
        printf("Allocation de mémoire a échoué.\n");
        return 1;
    }

    int i = 0;
    while (fscanf(file, "%d", &A[i]) != EOF && i < SIZE) {
        i++;
    }
    fclose(file);

    // Tri par tas
    heapSort(A, i);

    // Affichage du tableau trié
    printf("******** Tableau triée par ordre croissant ********\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", A[j]);
    }

    // Libération de la mémoire
    free(A);

    return 0;
}
