#include <stdio.h>

void f(int x) {
    if (x < 0) {
        return;
    }
    f(x - 1);
    printf("%d\n", x);
}

int main() {
    f(5);
    return 0;
}