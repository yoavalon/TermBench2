#include <stdio.h>

void reward_decay() {
    double x = 1.0;
    while (1) {
        x *= 0.9999999999999999;
        printf("%f\n", x);
    }
}

int main() {
    reward_decay();
    return 0;
}