# include "list.h"

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

char * duplicateString ( const char * str ) {
    size_t length = stringLength(str);
    char * dup = malloc(length);
    copyString(dup, str, length);
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
    newNode->value = malloc(strlen(value) + 1); // Allouer de la mémoire pour la copie de la chaîne
    if (newNode->value == NULL) {
        free(newNode);
        printf("Impossible d'allouer de la mémoire pour la valeur du node\n");
        return 1;
    }
    strcpy(newNode->value, value);
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
    newNode->value = malloc(strlen(value) + 1); // Allouer de la mémoire pour la copie de la chaîne
    if (newNode->value == NULL) {
        free(newNode);
        printf("Impossible d'allouer de la mémoire pour la valeur du node\n");
        return 1;
    }
    strcpy(newNode->value, value);
    newNode->prev = NULL;
    newNode->next = list->head;
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
    newNode->prev = list->tail;
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
        list->tail->next = newNode;
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

void List_erase ( struct List * list, struct Node * pos ){
    if (pos == NULL){
        printf("Le Node a supprimer n'existe pas\n");
    }
    if (pos->prev != NULL && pos->next != NULL){
        pos->prev->next = pos->next;
        pos->next->prev = pos->prev;
    }
    else if(pos->prev == NULL){
        list->head = pos->next;
        pos->next->prev = NULL;
    }
    else{
        list->tail = pos->prev;
        pos->prev->next = NULL;
    }
    free(pos);
    list->size--;
    printf("Le Node a bien ete supprimer\n");
}

int List_pop_front ( struct List * list ){
    if(list->head == NULL){
        printf("La liste est vide, impossible de supprimer le premier Node\n");
        return 1;
    }
    struct Node* myNode = list->head;
    if(list->head == list->tail){
        list->head = NULL;
        list->tail = NULL;
    }
    else{
        list->head = myNode->next;
        myNode->next->prev = NULL;
    }
    free(myNode);
    list->size--;
    printf("Le premier element a bien ete supprimer\n");
    return 0;
}

int List_pop_back ( struct List * list ){
    if(list->tail == NULL){
        printf("La liste est vide, impossible de supprimer le dernier Node\n");
        return 1;
    }
    struct Node* myNode = list->tail;
    if(list->head == list->tail){
        list->head = NULL;
        list->tail = NULL;
    }
    else{
        list->tail = myNode->prev;
        myNode->prev->next = NULL;
    }
    free(myNode);
    list->size--;
    printf("Le dernier element a bien ete supprimer\n");
    return 0;
}

void List_splice ( struct List * list1 , struct Node * pos1 , struct List * list2 , struct Node * from2 , struct Node * to2 ){
    if (from2 == NULL){
        printf("Le Node from2 n'existe pas\n");
        return;
    }
    if (to2 == NULL){
        printf("Le Node to2 n'existe pas\n");
        return;
    }
    if (pos1 == NULL){
        printf("Le Node pos1 n'existe pas\n");
        return;
    }
    if (list1 == list2){
        printf("Les deux listes sont identiques\n");
        return;
    }
    if (pos1->prev != NULL){
        pos1->prev->next = from2;
    }
    else{
        list1->head = from2;
    }
    from2->prev = pos1->prev;
    to2->next = pos1;
    pos1->prev = to2;
    printf("Les Nodes ont bien ete deplaces\n");
}

struct Node * List_find ( struct List * list , const char * value , int (* compare )( const char * , const char *)){
    struct Node * node = list->head;
    while (node != NULL) {
        if (compare(node->value, value) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void List_swap ( struct List * list , struct Node * x , struct Node * y ){
    if (x == NULL){
        printf("Le Node x n'existe pas\n");
        return;
    }
    if (y == NULL){
        printf("Le Node y n'existe pas\n");
        return;
    }
    if (x->prev != NULL){
        x->prev->next = y;
    }
    else{
        list->head = y;
    }
    if (x->next != NULL){
        x->next->prev = y;
    }
    else{
        list->tail = y;
    }
    if (y->prev != NULL){
        y->prev->next = x;
    }
    else{
        list->head = x;
    }
    if (y->next != NULL){
        y->next->prev = x;
    }
    else{
        list->tail = x;
    }
    struct Node * temp = x->prev;
    x->prev = y->prev;
    y->prev = temp;
    temp = x->next;
    x->next = y->next;
    y->next = temp;
    printf("Les Nodes ont bien ete echanges\n");
}

void List_sort ( struct List * list , int (* compare )( const char * , const char *)){
    struct Node * node = list->head;
    while (node != NULL) {
        struct Node * next = node->next;
        while (next != NULL) {
            if (compare(node->value, next->value) > 0) {
                List_swap(list, node, next);
            }
            next = next->next;
        }
        node = node->next;
    }
    printf("La liste a bien ete triee\n");
}


int compare ( const char * str1 , const char * str2 ){
    return strcmp(str1, str2);
}