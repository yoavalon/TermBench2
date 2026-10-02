#include <stdio.h>

int f(int x) {
    return x + f(x);
}

int main() {
    f(0);
    return 0;
}