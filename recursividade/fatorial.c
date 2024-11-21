#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
    if (n == 0 || n==1 ) {
        return 1; 
    } else {
        return n * fatorial(n - 1); 
    }
}


int main(){

    int le;
     scanf("%d", &le);

     printf("o fatorial de %d eh: %d", le, fatorial(le));
}