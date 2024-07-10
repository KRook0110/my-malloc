#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if(argc == 1) return 1;
    int n = 100;
    int size = atoi(argv[1]);
    printf("Size : %d\n", size );
    char* holder[n];


    for(int i =0; i < n;i++) {
        holder[i] = malloc(size);
    }

    getchar();
    getchar();
}
