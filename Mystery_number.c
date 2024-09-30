// Importation des bibliothèques standards
#include <stdio.h>
#include <stdlib.h>

// Déclaration des fonctions
int mystery_number();

// Fonction principale
void main() {
    printf("Bienvenue dans le juste nombre!\n");
    printf("Trouvez le nombre mystère entre 1 et 100!\n");
    int a, b, c;
    b = mystery_number();
    c = 0;
    do {
        printf("Entrez un nombre: ");
        scanf("%d", &a);
        if (a < b) {
            printf("Le nombre mystere est plus grand!\n");
        } else if (a > b) {
            printf("Le nombre mystere est plus petit!\n");
        }
        c++;
    } while (a != b);
    printf("Bravo! Vous avez trouve le nombre mystere %d en %d coups!\n", b, c);
}

int mystery_number() {
    return rand() % 100 + 1;
}