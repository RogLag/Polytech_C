#include <stdio.h>
#include <stdlib.h>

void printReverseString(char* str);

int main(void) {
    printf("Variables de base :\n");
    char c[] = "Hello, World!";
    printf("Adresse de str : %p\n", &c);
    printf("c : %s\n", c);
    int e = 42;
    printf("Adresse de e : %p\n", &e);
    printf("e : %i\n", e);
    float f = 3.14;
    printf("Adresse de f : %p\n", &f);
    printf("f : %f\n", f);
    double d = 2.71828;
    printf("Adresse de d : %p\n", &d);
    printf("d : %lf\n", d);

    printf("\nVariables allouees dynamiquement :\n");
    char* pc = malloc(13 * sizeof(char));
    pc = c;
    printf("Adresse de pc : %p\n", &pc);
    printf("pc : %s\n", pc);
    int* pe = malloc(sizeof(int));
    *pe = e;
    printf("Adresse de pe : %p\n", &pe);
    printf("pe : %i\n", *pe);
    float* pf = malloc(sizeof(float));
    *pf = f;
    printf("Adresse de pf : %p\n", &pf);
    printf("pf : %f\n", *pf);
    double* pd = malloc(sizeof(double));
    *pd = d;
    printf("Adresse de pd : %p\n", &pd);
    printf("pd : %lf\n", *pd);

    printf("\nAffichage de la chaine de caracteres a l'envers :\n");
    printReverseString(c);
    return 0;
}

void printReverseString(char* cstr) {
    int ilength = 0;
    while (cstr[ilength] != '\0') {
        ilength++;
    }
    for (int i = ilength - 1; i >= 0; i--) {
        printf("%c", *(cstr + i));
    }
    printf("\n");
}