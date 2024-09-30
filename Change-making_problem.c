// Importation des bibliothèques standards
#include <stdio.h>
#include <stdlib.h>

void main() {
    unsigned int x = 0;
    unsigned int res1 = 0, res2 = 0, res5 = 0, res10 = 0;

    printf("Entrez un montant en euros : ");
    scanf("%d", &x);

    res10 = x / 10;
    x = x % 10;
    res5 = x / 5;
    x = x % 5;
    res2 = x / 2;
    x = x % 2;
    res1 = x;

    printf("Le montant en euros est composé de : \n");
    printf("%d billets de 10 euros\n", res10);
    printf("%d billets de 5 euros\n", res5);
    printf("%d billets de 2 euros\n", res2);
    printf("%d billets de 1 euro\n", res1);
}