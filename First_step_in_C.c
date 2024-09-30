// importation des bibliothèques standards
#include <stdio.h>
#include <stdlib.h>

// déclaration des fonctions
int sum(int a, int b);
int product(int a, int b);
float division(int a, int b);

// fonction principale
void main() {
    printf("Hello, World!\n");
    int a, b, c, d;
    float e;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    c = sum(a, b);
    printf("%d + %d = %d\n", a, b, c);
    d = product(a, b);
    printf("%d x %d = %d\n", a, b, d);
    e = division(a, b);
    printf("%d / %d = %f\n", a, b, e);
}

// définition des fonctions
int sum(int a, int b) {
    return a + b;
}
int product(int a, int b) {
    return a * b;
}
float division(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "fatal error: division by zero\n");
        exit(1);
    }
    return (float) a / b;
}