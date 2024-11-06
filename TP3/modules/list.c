# include "list.h"

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

char * duplicateString ( const char * str ) {
    size_t length = stringLength(str);
    char * dup = malloc(length + 1);
    copyString(dup, str, length + 1);
    return dup;
}

size_t stringLength ( const char * str ) {
    size_t length = 0;
    while ( str[length] != '\0' ) {
        length++;
    }
    return length;
}

int copyString ( char * dst , const char * src , size_t dstSize ) {
    int i = 0;
    while ( src[i] != '\0' && i < dstSize - 1 ) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    if ( src[i] != '\0' ) {
        return -1;
    } else {
        return 0;
    }
}

struct List * List_new (){
    struct List * list = malloc(sizeof(struct List));
    if (list == NULL) {
        printf("La creation de la liste a echoue\n");
        return NULL;
    };
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    printf("La liste a ete cree avec succes\n");
    return list;
}

void List_clear ( struct List * list ){
    struct Node * node = list->head;
    while (node != NULL) {
        struct Node * next = node->next;
        free(node->value);
        free(node);
        node = next;
    }
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    printf("La liste a ete videe\n");
}

void List_delete ( struct List * list ){
    if(list != NULL){
        List_clear(list);
        free(list);
    }
    printf("La liste a ete supprimee\n");
}

void List_print ( const struct List * list ){
    struct Node * node = list->head;
    int index = 0;
    while (node != NULL) {
        struct Node * next = node->next;
        printf("Le node num %d contient la valeur : %s\n", index, node->value);
        node = next;
        index++;
    }
}

int List_insert ( struct List * list , struct Node * pos , const char * value ){
    struct Node * newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Impossible de creer le nouveau node\n");
        return 1;
    }
    newNode->value = duplicateString(value);
    newNode->prev = NULL;
    newNode->next = NULL;
    if(newNode->value == NULL){
        free(newNode);
        printf("La valeur du node n'est pas valide\n");
        return 1;
    }
    if(pos == NULL){
        struct Node * lastNode = list->tail;
        if(lastNode == NULL){
            list->head = newNode;
            list->tail = newNode;
        }
        else{
            lastNode->next = newNode;
            newNode->prev = lastNode;
            list->tail = newNode;
        }
        printf("Le nouveau Node a ete ajoute a la fin de la liste car le Node pos est NULL\n");
    }
    else{
        newNode->prev = pos->prev;
        newNode->next = pos;
        if (pos->prev != NULL) {
            pos->prev->next = newNode;
        } else {
            list->head = newNode;
        }
        pos->prev = newNode;
        printf("Le nouveau Node a ete ajoute avant le Node pos\n");
    }
    list->size++;
    return 0;
}

int List_push_front ( struct List * list , const char * value ){
    struct Node * newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Impossible de creer le nouveau node\n");
        return 1;
    }
    newNode->value = duplicateString(value);
    newNode->prev = NULL;
    newNode->next = NULL;
    if(newNode->value == NULL){
        free(newNode);
        printf("La valeur du node n'est pas valide\n");
        return 1;
    }
    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
    printf("Le nouveau Node a ete ajoute au debut de la liste\n");
    return 0;
}

int List_push_back ( struct List * list , const char * value ){
    struct Node * newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Impossible de creer le nouveau node\n");
        return 1;
    }
    newNode->value = duplicateString(value);
    newNode->prev = NULL;
    newNode->next = NULL;
    if(newNode->value == NULL){
        free(newNode);
        printf("La valeur du node n'est pas valide\n");
        return 1;
    }
    if(list->tail == NULL){
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        newNode->prev = list->tail;
        list->head->next = newNode;
        list->tail = newNode;
    }
    list->size++;
    printf("Le nouveau Node a ete ajoute a la fin de la liste\n");
    return 0;
}

int Node_update ( struct Node * node , const char * value ){
    char * storeValue = node->value;
    node->value = duplicateString(value);
    if(node->value == NULL){
        printf("La nouvelle valeur du Node est incorrecte\n");
        node->value = storeValue;
        return 0;
    }
    free(storeValue);
    printf("La valeur du Node a ete mise a jour\n");
    return 0;
}