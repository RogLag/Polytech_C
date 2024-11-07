# ifndef LIST_HEADER_GUARD
# define LIST_HEADER_GUARD

# include <stddef.h>

// a node of a List
struct Node {
    // a pointer to the previous node in the list (*)
    struct Node * prev ;
    // a pointer to the next node in the list (*)
    struct Node * next ;
    // the ( dynamically allocated ) string stored in the node
    char * value ;
};

// a doubly linked list of strings
struct List {
    // the size of the list
    size_t size ;
    // a pointer to the first element of the list (*)
    struct Node * head ;
    // a pointer to the last element of the list (*)
    struct Node * tail ;
};

struct List * List_new ();

void List_clear ( struct List * list );

void List_delete ( struct List * list );

void List_print ( const struct List * list );

int List_insert ( struct List * list , struct Node * pos , const char * value );

int List_push_front ( struct List * list , const char * value );

int List_push_back ( struct List * list , const char * value );

int Node_update ( struct Node * node , const char * value );

void List_erase ( struct List * list, struct Node * pos );

int List_pop_front ( struct List * list );

int List_pop_back ( struct List * list );

void List_splice ( struct List * list1 , struct Node * pos1 , struct List * list2 , struct Node * from2 , struct Node * to2 );

struct Node * List_find ( struct List * list , const char * value , int (* compare )( const char * , const char *));

void List_swap ( struct List * list , struct Node * x , struct Node * y );

void List_sort ( struct List * list , int (* compare )( const char * , const char *));

int compare ( const char * str1 , const char * str2 );

char * duplicateString ( const char * str );

size_t stringLength ( const char * str );

int copyString ( char * dst , const char * src , size_t dstSize );

// (*) NULL if no such node exists
# endif