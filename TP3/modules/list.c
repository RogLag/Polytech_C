# include "list.h"

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

struct List * List_new (){
    struct List * list = malloc(sizeof(struct List));
    if (list == NULL) {
        return NULL;
    };
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
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
}

void List_delete ( struct List * list ){
    if(list != NULL){
        List_clear(list);
        free(list);
    }
}

void List_print ( const struct List * list ){
    struct Node * node = list->head;
    int index = 0;
    printf("[");
    while (node != NULL) {
        struct Node * next = node->next;
        printf("%s", node->value);
        if (next != NULL) {
            printf(", ");
        }
        node = next;
        index++;
    }
    printf("]\n");
}

int List_insert ( struct List * list , struct Node * pos , const char * value ){
    struct Node * newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        return 1;
    }
    newNode->value = malloc(strlen(value) + 1);
    if (newNode->value == NULL) {
        free(newNode);
        return 1;
    }
    strcpy(newNode->value, value);
    newNode->prev = NULL;
    newNode->next = NULL;
    if(newNode->value == NULL){
        free(newNode);
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
    }
    list->size++;
    return 0;
}

int List_push_front ( struct List * list , const char * value ){
    struct Node * newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        return 1;
    }
    newNode->value = malloc(strlen(value) + 1);
    if (newNode->value == NULL) {
        free(newNode);
        return 1;
    }
    strcpy(newNode->value, value);
    newNode->prev = NULL;
    newNode->next = list->head;
    if(newNode->value == NULL){
        free(newNode);
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
    return 0;
}

int List_push_back ( struct List * list , const char * value ){
    struct Node * newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        return 1;
    }
    newNode->value = malloc(strlen(value) + 1);
    if (newNode->value == NULL) {
        free(newNode);
        return 1;
    }
    strcpy(newNode->value, value);
    newNode->prev = list->tail;
    newNode->next = NULL;
    if(newNode->value == NULL){
        free(newNode);
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
    return 0;
}

int Node_update ( struct Node * node , const char * value ){
    if(node == NULL){
        return 1;
    }
    free(node->value);
    node->value = malloc(strlen(value) + 1);
    if (node->value == NULL) {
        return 1;
    }
    strcpy(node->value, value);
    return 0;
}

void List_erase ( struct List * list, struct Node * pos ){
    if (pos == NULL){
        return;
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
}

int List_pop_front ( struct List * list ){
    if(list->head == NULL){
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
    return 0;
}

int List_pop_back ( struct List * list ){
    if(list->tail == NULL){
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
    return 0;
}

void List_splice ( struct List * list1 , struct Node * pos1 , struct List * list2 , struct Node * from2 , struct Node * to2 ){
    if (from2 == NULL){
        return;
    }
    if (to2 == NULL){
        to2 = list2->tail;
    }
    if (pos1 == NULL){
        pos1 = list1->tail;
    }
    if (list1 == list2){
        struct Node * node = from2;
        while (node != to2) {
            struct Node * next = node->next;
            List_insert(list1, pos1, node->value);
            List_erase(list2, node);
            node = next;
        }
    }
    else{
        struct Node * node = from2;
        while (node != to2) {
            struct Node * next = node->next;
            List_insert(list1, pos1, node->value);
            List_erase(list2, node);
            node = next;
        }
    }
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
        return;
    }
    if (y == NULL){
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
}


int compare ( const char * str1 , const char * str2 ){
    return strcmp(str1, str2);
}