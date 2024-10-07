// You are asked to complete five tasks. Each task i requires pi days to be processed and is due within di days. You cannot handle two tasks at a time. Preemption is not allowed.

// Je commencerai par traiter les tâches dans l'ordre de leur date limite. Si deux tâches ont la même date limite, je traiterai d'abord celle qui prend le moins de temps à être traitée. Si deux tâches ont la même date limite et prennent le même temps à être traitées, je traiterai d'abord celle qui a été reçue en premier.

// Importation des bibliothèques standards
#include <stdio.h>
#include <stdlib.h>

void tri (int *t, int *p, int *d);

int main () {

    int tasks [5] = { 1 , 2 , 3 , 4 , 5 };
    int p [5] = { 32 , 13 , 26 , 7 , 29 };
    int d [5] = { 83 , 37 , 29 , 70 , 69 };
    
    // Tri des tâches en fonction de leur date limite et de leur temps de traitement

    for ( int i = 0; i < 5; ++ i ) {
        for ( int j = i + 1; j < 5; ++ j ) {
            // Si la date limite de la tâche i est plus grande que celle de la tâche j 
            // ou si les dates limites sont les mêmes mais que le temps de traitement de la tâche i est plus grand que celui de la tâche j
            // ou si les dates limites et les temps de traitement sont les mêmes mais que la tâche i a été reçue après la tâche j
            //if ( d [ i ] > d [ j ] || ( d [ i ] == d [ j ] && p [ i ] > p [ j ] ) || ( d [ i ] == d [ j ] && p [ i ] == p [ j ] && tasks [ i ] > tasks [ j ] ) ) {
            //    int temp = tasks [ i ];
            //    tasks [ i ] = tasks [ j ];
            //    tasks [ j ] = temp;
            //    temp = p [ i ];
            //    p [ i ] = p [ j ];
            //    p [ j ] = temp;
            //    temp = d [ i ];
            //    d [ i ] = d [ j ];
            //    d [ j ] = temp;
            //}
            tri(tasks, p, d);
        }
    }

    for ( int k = 0; k < 5; ++ k ) {
        printf (" Task %d: start =%4d, end =%4d, lateness =%4d\n", tasks [ k ], p [ k ], d [ k ], p [ k ] - d [ k ] );
    }

    return 0;

}

// fonction de tri
void tri (int *t, int *p, int *d) {
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (d[i] > d[j] || (d[i] == d[j] && p[i] > p[j]) || (d[i] == d[j] && p[i] == p[j] && t[i] > t[j])) {
                int temp = t[i];
                t[i] = t[j];
                t[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
}