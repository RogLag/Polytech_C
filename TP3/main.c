# include <stdio.h>

# include "list.h"

int main() {
    //Il faut tester toutes lse fonctions dans un ordre logique
    //On commence par créer une liste
    struct List * list = List_new();
    //On ajoute un élément au début de la liste
    List_push_front(list, "1");
    //On ajoute un élément à la fin de la liste
    List_push_back(list, "2");
    //On affiche la liste
    List_print(list);
    //On ajoute un élément au début de la liste
    List_push_front(list, "3");
    //On affiche la liste
    List_print(list);
    //On ajoute un élément après l'élément 1
    List_insert(list, list->head->next, "4");
    //On affiche la liste
    List_print(list);
    //On met à jour la valeur de l'élément 1
    Node_update(list->head, "5");
    //On affiche la liste
    List_print(list);
    //On clear la liste
    List_clear(list);
    //On affiche la liste
    List_print(list);
    //On ajoute un élément au début de la liste
    List_push_front(list, "6");
    //On affiche la liste
    List_print(list);
    //On supprime la liste
    List_delete(list);
    return 0;
}