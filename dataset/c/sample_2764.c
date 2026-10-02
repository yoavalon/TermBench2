#include <stdio.h>

int func() {
    static int x = 1;
    return x++;
}

int main() {
    while (1) {
        int num = func();
        printf("%d\n", num);
    }
    return 0;
}