#include <iostream>

void main() {
    int a = 1, b = 2;
    while (a < b) {
        int temp = b;
        b = a + b;
        a = temp;
    }
}