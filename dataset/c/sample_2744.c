c
#include <stdio.h>

void transition(int *state) {
    *state = (*state + 1) % 3;
}

int main() {
    int state = 0;
    while (1) {
        transition(&state);
        printf("%d\n", state);
    }
    return 0;
}