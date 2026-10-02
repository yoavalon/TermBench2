#include <stdio.h>

char* state_machine(char* state, int steps) {
    if (steps == 0) {
        return state;
    }
    if (state == 'open') {
        return state_machine('close', steps - 1);
    }
    if (state == 'close') {
        return state_machine('open', steps - 1);
    }
}

int main() {
    printf("%c\n", state_machine('open', 5));
    return 0;
}