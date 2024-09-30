#include <stdio.h>
#include <stdint.h>

int main () {
    int8_t mask = 0b00000001;
    const int8_t x = -1;
    int output [] = { -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 };
    for (int i = 0; i < 8; ++ i ) {
        output [ i ] = ( x & mask ) != 0;
        mask = mask << 1;
    }
    // Do NOT uncomment the following lines until you are
    // asked to do so.
    for (int i = 7; i >= 0; --i) {
        printf("% d" , output [i ]);
    }
    printf("\n");
    return 0;
}

// Avant d'entrée dans la boucle for, mask vaut 1 (0b00000001), x vaut 57 (0b00111001), i vaut 0 et output vaut { -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 }.
// 1ère itération de la boucle for:
// i vaut 0, output vaut { 1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 } et mask vaut 2 (0b00000010).
// 2ème itération de la boucle for:
// i vaut 1, output vaut { 1 , 0 , -1 , -1 , -1 , -1 , -1 , -1 } et mask vaut 4 (0b00000100).
// 3ème itération de la boucle for:
// i vaut 2, output vaut { 1 , 0 , 0 , -1 , -1 , -1 , -1 , -1 } et mask vaut 8 (0b00001000).
// 4ème itération de la boucle for:
// i vaut 3, output vaut { 1 , 0 , 0 , 1 , -1 , -1 , -1 , -1 } et mask vaut 16 (0b00010000).
// 5ème itération de la boucle for:
// i vaut 4, output vaut { 1 , 0 , 0 , 1 , 1 , -1 , -1 , -1 } et mask vaut 32 (0b00100000).
// 6ème itération de la boucle for:
// i vaut 5, output vaut { 1 , 0 , 0 , 1 , 1 , 0 , -1 , -1 } et mask vaut 64 (0b01000000).
// 7ème itération de la boucle for:
// i vaut 6, output vaut { 1 , 0 , 0 , 1 , 1 , 0 , 0 , -1 } et mask vaut 128 (0b10000000).
// 8ème itération de la boucle for:
// i vaut 7, output vaut { 1 , 0 , 0 , 1 , 1 , 0 , 0 , 0 } et mask vaut 0 (0b00000000).
// Après la boucle for, output vaut { 1 , 0 , 0 , 1 , 1 , 0 , 0 , 0 }.

// Lors de l'exécution de ce programme, la sortie affichée est: 0 0 0 1 1 0 0 1

// Si je met x = -1 (0b11111111), la sortie affichée sera: 1 1 1 1 1 1 1 1