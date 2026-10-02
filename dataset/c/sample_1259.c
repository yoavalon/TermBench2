#include <stdio.h>

char state_machine(int data[]) {
    char states[] = {'B', 'C', 'A'};
    char current_state = 'A';
    for (int i = 0; i < 3; i++) {
        current_state = states[current_state - 'A'];
        if (current_state == 'C') {
            break;
        }
    }
    return current_state;
}

int main() {
    int data[] = {1, 2, 3};
    printf("%c\n", state_machine(data));
    return 0;
}