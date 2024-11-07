# include "../include/list.h"
# include "../include/list-test.h"
# include <stdio.h>
# include <string.h>

// Le but est de tester TOUTES les fonctions du fichier list.h
// Pour cela, on va créer une liste, ajouter des éléments, les supprimer, les trier, etc.
// On va ensuite vérifier que les fonctions ont bien fait ce qu'elles devaient faire.
// On va aussi vérifier que les fonctions ne modifient pas des éléments qui ne devraient pas être modifiés.

int test_create(){
    printf("Test de la creation de la liste :\n");
    struct List * list = List_new();
    if(list == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    if(list->size != 0){
        printf("    La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head != NULL){
        printf("    La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->tail != NULL){
        printf("    La queue de la liste n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : La liste a bien ete cree\n");
    return 0;
}

int test_insert(){
    printf("Test de l'insertion dans la liste :\n");
    struct List * list = List_new();
    if(list == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    struct Node * node = list->head;
    if(node != NULL){
        printf("    La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(List_insert(list, node, "test") != 0){
        printf("    L'insertion a echoue\n");
        return 1;
    }
    if(list->size != 1){
        printf("    La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head == NULL){
        printf("    La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->tail == NULL){
        printf("    La queue de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head != list->tail){
        printf("    La tete et la queue de la liste ne sont pas correctes\n");
        return 1;
    }
    if(list->head->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list->head->value, "test") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : L'insertion a bien ete faite\n");
    return 0;
}

int test_push_front(){
    printf("Test de l'ajout en debut de liste :\n");
    struct List * list = List_new();
    if(list == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    if(List_push_front(list, "test") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(list->size != 1){
        printf("    La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head == NULL){
        printf("    La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->tail == NULL){
        printf("    La queue de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head != list->tail){
        printf("    La tete et la queue de la liste ne sont pas correctes\n");
        return 1;
    }
    if(list->head->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list->head->value, "test") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : L'ajout a bien ete fait\n");
    return 0;
}

int test_push_back(){
    printf("Test de l'ajout en fin de liste :\n");
    struct List * list = List_new();
    if(list == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    if(List_push_back(list, "test") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(list->size != 1){
        printf("    La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head == NULL){
        printf("    La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->tail == NULL){
        printf("    La queue de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head != list->tail){
        printf("    La tete et la queue de la liste ne sont pas correctes\n");
        return 1;
    }
    if(list->head->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list->head->value, "test") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : L'ajout a bien ete fait\n");
    return 0;
}

int test_pop_front(){
    printf("Test de la suppression en debut de liste :\n");
    struct List * list = List_new();
    if(list == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    if(List_push_back(list, "test") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(List_pop_front(list) != 0){
        printf("    La suppression a echoue\n");
        return 1;
    }
    if(list->size != 0){
        printf("    La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head != NULL){
        printf("    La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->tail != NULL){
        printf("    La queue de la liste n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : La suppression a bien ete faite\n");
    return 0;
}

int test_pop_back(){
    printf("Test de la suppression en fin de liste :\n");
    struct List * list = List_new();
    if(list == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    if(List_push_back(list, "test") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(List_pop_back(list) != 0){
        printf("    La suppression a echoue\n");
        return 1;
    }
    if(list->size != 0){
        printf("    La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head != NULL){
        printf("    La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->tail != NULL){
        printf("    La queue de la liste n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : La suppression a bien ete faite\n");
    return 0;
}

int test_erase(){
    printf("Test de la suppression d'un element de la liste :\n");
    struct List * list = List_new();
    if(list == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    if(List_push_back(list, "test") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(List_push_back(list, "test2") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    struct Node * node = list->head;
    if(node == NULL){
        printf("    La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(node->next == NULL){
        printf("    La queue de la liste n'est pas correcte\n");
        return 1;
    }
    List_erase(list, node);
    if(list->size != 1){
        printf("    La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head == NULL){
        printf("    La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->tail == NULL){
        printf("    La queue de la liste n'est pas correcte\n");
        return 1;
    }
    if(list->head != list->tail){
        printf("    La tete et la queue de la liste ne sont pas correctes\n");
        return 1;
    }
    if(list->head->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list->head->value, "test2") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : La suppression a bien ete faite\n");
    return 0;
}

int test_splice(){
    printf("Test de la fusion de deux listes :\n");
    struct List * list1 = List_new();
    if(list1 == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    struct List * list2 = List_new();
    if(list2 == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    if(List_push_back(list1, "test") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(List_push_back(list1, "test2") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(List_push_back(list2, "test3") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(List_push_back(list2, "test4") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    struct Node * node1 = list1->head;
    struct Node * node2 = list2->head;
    List_splice(list1, node1, list2, node2, node2);
    if(list1->size != 4){
        printf("    La taille de la liste n'est pas correcte\n");
        return 1;
    }
    if(list1->head == NULL){
        printf("    La tete de la liste n'est pas correcte\n");
        return 1;
    }
    if(list1->tail == NULL){
        printf("    La queue de la liste n'est pas correcte\n");
        return 1;
    }
    if(list1->head == list1->tail){
        printf("    La tete et la queue de la liste ne sont pas correctes\n");
        return 1;
    }
    if(list1->head->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list1->head->value, "test") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(list1->head->next->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list1->head->next->value, "test2") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(list1->head->next->next->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list1->head->next->next->value, "test3") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(list1->head->next->next->next->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list1->head->next->next->next->value, "test4") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : La fusion a bien ete faite\n");
    return 0;
}

int test_find(){
    printf("Test de la recherche d'un element dans la liste :\n");
    struct List * list = List_new();
    if(list == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    if(List_push_back(list, "test") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(List_push_back(list, "test2") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    struct Node * node = List_find(list, "test2", compare);
    if(node == NULL){
        printf("    La recherche a echoue\n");
        return 1;
    }
    if(node->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(node->value, "test2") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : La recherche a bien ete faite\n");
    return 0;
}

int test_swap(){
    printf("Test de l'echange de deux elements de la liste :\n");
    struct List * list = List_new();
    if(list == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    if(List_push_back(list, "test") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(List_push_back(list, "test2") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    struct Node * node1 = list->head;
    struct Node * node2 = list->head->next;
    List_swap(list, node1, node2);
    if(list->head->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list->head->value, "test2") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(list->head->next->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list->head->next->value, "test") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : L'echange a bien ete fait\n");
    return 0;
}

int test_sort(){
    printf("Test du tri de la liste :\n");
    struct List * list = List_new();
    if(list == NULL){
        printf("    La liste n'a pas ete cree\n");
        return 1;
    }
    if(List_push_back(list, "test") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    if(List_push_back(list, "test2") != 0){
        printf("    L'ajout a echoue\n");
        return 1;
    }
    List_sort(list, compare);
    if(list->head->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list->head->value, "test") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(list->head->next->value == NULL){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    if(strcmp(list->head->next->value, "test2") != 0){
        printf("    La valeur du node n'est pas correcte\n");
        return 1;
    }
    printf("    Succes : Le tri a bien ete fait\n");
    return 0;
}