# include "../include/list.h"
# include "../include/list-test.h"
# include <stdio.h>
# include <string.h>

// Le but est de tester TOUTES les fonctions du fichier list.h
// Pour cela, on va créer une liste, ajouter des éléments, les supprimer, les trier, etc.
// On va ensuite vérifier que les fonctions ont bien fait ce qu'elles devaient faire.
// On va aussi vérifier que les fonctions ne modifient pas des éléments qui ne devraient pas être modifiés.

int test_create(){
    struct List * list = List_new();
    if(list == NULL){
        printf("La liste n'a pas ete cree\n");
        return 1;
    }
    if(list->size != 0){
        printf("La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head != NULL){
        printf("La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->tail != NULL){
        printf("La queue de la liste n'est pas correcte\n");
        return 1;
    }
    printf("La liste a bien ete cree\n");
    return 0;
}

int test_insert(){
    struct List * list = List_new();
    if(list == NULL){
        printf("La liste n'a pas ete cree\n");
        return 1;
    }
    struct Node * node = list->head;
    if(node != NULL){
        printf("La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(List_insert(list, node, "test") != 0){
        printf("L'insertion a echoue\n");
        return 1;
    }
    if(list->size != 1){
        printf("La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head == NULL){
        printf("La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->tail == NULL){
        printf("La queue de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head != list->tail){
        printf("La tete et la queue de la liste ne sont pas correctes\n");
        return 1;
    }
    if(list->head->value == NULL){
        printf("La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list->head->value, "test") != 0){
        printf("La valeur du node n'est pas correcte\n");
        return 1;
    }
    printf("L'insertion a bien ete faite\n");
    return 0;
}

int test_push_front(){
    struct List * list = List_new();
    if(list == NULL){
        printf("La liste n'a pas ete cree\n");
        return 1;
    }
    if(List_push_front(list, "test") != 0){
        printf("L'ajout a echoue\n");
        return 1;
    }
    if(list->size != 1){
        printf("La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head == NULL){
        printf("La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->tail == NULL){
        printf("La queue de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head != list->tail){
        printf("La tete et la queue de la liste ne sont pas correctes\n");
        return 1;
    }
    if(list->head->value == NULL){
        printf("La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list->head->value, "test") != 0){
        printf("La valeur du node n'est pas correcte\n");
        return 1;
    }
    printf("L'ajout a bien ete fait\n");
    return 0;
}