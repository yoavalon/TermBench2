#include <stdio.h>

int simulate() {
    int a = 1, b = 1;
    while (1) {
        int temp = a;
        a = b;
        b = temp + b;
        if (a > 1000) {
            break;
        }
    }
    return a;
}

int main() {
    int result = simulate();
    return 0;
}