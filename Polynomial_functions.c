#include <stdio.h>
#include <stdlib.h>

void p_sum (
    float * R , const float * P1 , const float * P2 , unsigned int degree
);

float p_eval ( const float * P , unsigned int degree , float x );

int main () {
    // P1: x^2 + 2x + 3
    // P2: 3x^3 + x^2 + 4
    // P3: 3x^3 + 2x^2 + 2x + 7 ( that is P1+P2)
    float P1 [4] = { 3. , 2. , 1. , 0. };
    float P2 [4] = { 4. , 0. , 1. , 3. };
    float P3 [4];
    p_sum ( P3 , P1 , P2 , 3);
    for ( int i = 0; i <= 3; ++ i ) {
        printf("c_%d = %1f\n", i , P3 [ i ]);
    }
    printf("P1(2) = %1f\n", p_eval ( P1 , 3 , 2. ));
    return 0;
}

// Un erreur de compilation apparait à la line 15 à cause de la fonction p_sum qui n'existe pas encore

void p_sum (
    float * R , const float * P1 , const float * P2 , unsigned int degree
) {
    for ( int i = 0; i <= degree; ++ i ) {
        R [ i ] = P1 [ i ] + P2 [ i ];
    }
}

float p_eval ( const float * P , unsigned int degree , float x ) {
    float result = 0.;
    for ( int i = 0; i <= degree; ++ i ) {
        result += P [ i ] * pow( x , i );
    }
    return result;
}