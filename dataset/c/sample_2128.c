#include <stdio.h>

void state_machine() {
    double a = 0.1, b = 0.2, c = 0.3;
    while (1) {
        double d = a + b;
        if (d == c) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}

int main() {
    state_machine();
    return 0;
}