// Importation des bibliothèques standards
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Déclaration des fonctions
void Userjouer(int a, int b, int c);
void IAjoue(int a, int b, int c);
int mystery_number();
int IA_al(int min, int max);
int IA__opt(int min, int max);

// Fonction principale
int main() {
    printf("Bienvenue dans le juste nombre!\n");
    printf("1. Jouer\n");
    printf("2. IA\n");
    int choix;
    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    while (choix < 1 || choix > 2) {
        printf("Entrez un choix valide: ");
        scanf("%d", &choix);
    };
    printf("Trouvez le nombre mystere entre 1 et 100!\n");
    int a, b, c;
    a = 0;
    b = mystery_number();
    c = 0;
    if (choix == 1) {
        Userjouer(a, b, c);
    } else if (choix == 2) {
        IAjoue(a, b, c);
    }
    return 0;
}

void Userjouer(int a, int b, int c) {
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

void IAjoue(int a, int b, int c) {
    printf("Choisissez le type de l'IA:\n");
    printf("1. Aleatoire\n");
    printf("2. Optimise\n");
    printf("3. Test de performance\n");
    int choix;
    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    while (choix < 1 || choix > 3) {
        printf("Entrez un choix valide: ");
        scanf("%d", &choix);
    };
    if (choix != 3) {
        int min = 1, max = 100;
        while (a != b) {
            if (choix == 1) {
                a = IA_al(min, max);
            } else if (choix == 2) {
                a = IA__opt(min, max);
            }
            if (a < b) {
                printf("Le nombre mystere est plus grand!\n");
                min = a + 1;
            } else if (a > b) {
                printf("Le nombre mystere est plus petit!\n");
                max = a - 1;
            }
            printf("Bravo! L'IA a trouve le nombre mystere %d en %d coups!\n", b, c);
        }
    } else {
        // ici on va tester les deux IA sur 1000000 de parties et on va afficher le nombre moyen de coups pour trouver le nombre mystere
        int moy1 = 0;
        int moy2 = 0;
        int min = 0, max = 0;
        int nb_parties1 = 0;
        int nb_parties2 = 0;
        for (int i = 0; i < 100; i++) {
            min = 1, max = 100;
            int nb_coups = 0;
            a = IA_al(min, max);
            if (a < b) {
                //printf("Le nombre mystere est plus grand!\n");
                min = a + 1;
                nb_coups++;
            } else if (a > b) {
                //printf("Le nombre mystere est plus petit!\n");
                max = a - 1;
                nb_coups++;
            }
            moy1 += (nb_coups + 1);
            printf("%d\n", i);
            print("nombre de coups: %d\n", nb_coups);
        }
        for (int i = 0; i < 100; i++) {
            min = 1, max = 100;
            int nb_coups = 0;
            a = IA__opt(min, max);
            if (a < b) {
                //printf("Le nombre mystere est plus grand!\n");
                min = a + 1;
                nb_coups++;
            } else if (a > b) {
                //printf("Le nombre mystere est plus petit!\n");
                max = a - 1;
                nb_coups++;
            }
            moy2 += (nb_coups + 1);
            printf("%d\n", i);
            print("nombre de coups: %d\n", nb_coups);
        }
        printf("L'IA aleatoire a trouve le nombre mystere en %d coups en moyenne!\n", (float)moy1 / 100);
        printf("L'IA optimise a trouve le nombre mystere en %d coups en moyenne!\n", (float)moy2 / 100);
    }
}

int mystery_number() {
    srand((unsigned int)time(NULL));
    return rand() % 100 + 1;
}

int IA_al(int min, int max) {
    sleep(1);
    srand((unsigned int)time(NULL));
    return rand() % (max - min + 1) + min;
}

int IA__opt(int min, int max) {
    sleep(1);
    return (min + max) / 2;
}