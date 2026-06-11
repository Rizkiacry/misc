#include <stdio.h>

int main() {
    int I = 0;
    int A[11];
    while (I < 11) {
        A[I] = 1 << I;
        printf("%d\n", A[I]);
        I++;
    }
}
