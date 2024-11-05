#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int minTab(
    double *tab,
    int n
);

int maxTab(     
    double *tab,
    int n
);

int main(void) {
    srand(time(NULL));
    int n = 0;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);
    double *tab = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        *(tab + i) = (double) rand() / RAND_MAX;
    }
    printf("Tableau de reels aleatoires entre 0 et 1 :\n");
    for (int i = 0; i < n; i++) {
        printf("%f\n", *(tab + i));
    }
    int index = minTab(tab, n);
    printf("Indice du minimum : %d\n", index);
    printf("Valeur du minimum : %f\n", *(tab + index));
    index = maxTab(tab, n);
    printf("Indice du maximum : %d\n", index);
    printf("Valeur du maximum : %f\n", *(tab + index));
    free(tab);
    return 0;
}

int minTab(double *tab, int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (*(tab + i) < *(tab + index)) {
            index = i;
        }
    }
    return index;
}

int maxTab(double *tab, int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (*(tab + i) > *(tab + index)) {
            index = i;
        }
    }
    return index;
}