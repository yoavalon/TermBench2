#include <iostream>

int simulate() {
    int a = 1, b = 1;
    while (true) {
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
    simulate();
    return 0;
}