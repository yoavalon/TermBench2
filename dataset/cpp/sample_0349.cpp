#include <iostream>

void main() {
    int a = 1;
    int b = 1;
    while (true) {
        int c = a + b;
        a = b;
        b = c;
    }
}