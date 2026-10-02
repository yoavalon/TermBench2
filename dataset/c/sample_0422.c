#include <stdio.h>

char transition(char state) {
    if (state == 'A') {
        return 'B';
    } else if (state == 'B') {
        return 'C';
    } else if (state == 'C') {
        return 'A';
    } else {
        return 'A';
    }
}

void process(char state) {
    while (1) {
        state = transition(state);
        printf("%c\n", state);
    }
}

int main() {
    char initial_state = 'A';
    process(initial_state);
    return 0;
}