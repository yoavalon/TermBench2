#include <stdio.h>

void simulate() {
    int state = 0;
    while (1) {
        state = (state + 1) % 10;
        if (state == 0) {
            state = 1;
        }
    }
}

int main() {
    simulate();
    return 0;
}