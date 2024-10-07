#include <stdio.h>

size_t stringLength(char *str);

int stringCompare(char *str1, char *str2);

char* findFirst(char *str, char c);

char* findLast(char *str, char c);

int copyString ( char * dst , const char * src , size_t dstSize );

int main(void) {
    char str1[] = "Hello World!";
    char str2[] = "Hello Everybody!";
    printf("La chaine de caractere '%s' a une longueur de %d\n", str1, stringLength(str1));
    printf("La chaine de caractere '%s' a une longueur de %d\n", str2, stringLength(str2));
    printf("La chaine de caractere '%s' est %s a la chaine de caractere '%s'\n", str1, stringCompare(str1, str2) == 0 ? "identique" : "differente", str2);
    printf("La chaine de caractere '%s' est %s a la chaine de caractere '%s'\n", str1, stringCompare(str1, str1) == 0 ? "identique" : "differente", str1);
    char c = 'o';
    char *first = findFirst(str1, c);
    if (first != NULL) {
        printf("Le premier caractere '%c' dans la chaine de caractere '%s' est a l'index %d\n", c, str1, first - str1);
    } else {
        printf("Le caractere '%c' n'est pas present dans la chaine de caractere '%s'\n", c, str1);
    }
    char *last = findLast(str1, c);
    if (last != NULL) {
        printf("Le dernier caractere '%c' dans la chaine de caractere '%s' est a l'index %d\n", c, str1, last - str1);
    } else {
        printf("Le caractere '%c' n'est pas present dans la chaine de caractere '%s'\n", c, str1);
    }
    char dst[6];
    copyString(dst, "Hello World!", 6);
    printf("La chaine de caractere copiee est: %s\n", dst);
    return 0;
}

size_t stringLength(char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int stringCompare(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else if (str1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

char* findFirst(char *str, char c) {
    int i = 0;
    char *first = NULL;
    while (str[i] != '\0' && first == NULL) {
        if (str[i] == c) {
            first = &str[i];
        }
        i++;
    }
    return first;
}

char* findLast(char *str, char c) {
    // retourne un pointeur sur le dernier caractere c dans str
    int i = 0;
    char *last = NULL;
    while (str[i] != '\0') {
        if (str[i] == c) {
            last = &str[i];
        }
        i++;
    }
    return last;
}

int copyString ( char * dst , const char * src , size_t dstSize ) {
    // copie src dans dst, on tronque src si la taille de dst est inferieure a la taille de src, on retourne une erreur si la taille de dstSize vaut 0, 1 sinon.
    if (dstSize == 0) {
        return 0;
    }
    int i = 0;
    while (src[i] != '\0' && i < dstSize - 1) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return 1;
}