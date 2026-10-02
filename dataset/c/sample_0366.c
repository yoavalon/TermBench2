c
#include <stdio.h>

void main() {
    int a = 1, b = 2;
    while (a < b) {
        int temp = a;
        a = b;
        b = temp + b;
    }
}