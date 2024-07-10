#include <stdio.h>

int testing() {
    static int a = 10;
    a++;
    return a;
}

int main(void) {
    printf("%d\n", testing());
    printf("%d\n", testing());
    printf("%d\n", testing());
    printf("%d\n", testing());
    printf("%d\n", testing());
}
