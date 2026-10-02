#include <stdio.h>

void main() {
    while (1) {

        int f(int x) {
            if (x == 0)
                return 1;
            else
                return x * f(x - 1);
        }
        printf("%d\n", f(5));
    }
}