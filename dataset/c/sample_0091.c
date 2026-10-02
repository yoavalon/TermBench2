#include <stdio.h>

int consensus_mechanism() {
    int a = 1, b = 0;
    for (int i = 0; i < 10; i++) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return a;
}

int main() {
    consensus_mechanism();
    return 0;
}