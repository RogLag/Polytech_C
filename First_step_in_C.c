#include <stdio.h>

int sum(int a, int b);
int product(int a, int b);
float division(int a, int b);

void main() {
    printf("Hello, World!\n");
    int a, b, c, d;
    float e;
    printf("Enter two numbers: ");
    fflush( stdout );
    scanf("%d %d", &a, &b);
    c = sum(a, b);
    printf("%d + %d = %d\n", a, b, c);
    d = product(a, b);
    printf("%d x %d = %d\n", a, b, d);
    e = division(a, b);
    printf("%d / %d = %f\n", a, b, e);
}

int sum(int a, int b) {
    return a + b;
}

int product(int a, int b) {
    return a * b;
}

float division(int a, int b) {
    return (float) a / b;
}