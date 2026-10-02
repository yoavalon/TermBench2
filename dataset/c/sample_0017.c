#include <stdio.h>
#include <string.h>

int state_machine(char* data[], int length) {
    int states[3] = {0, 1, 2};
    int current = states[0];
    int transitions[3] = {states[1], states[2], states[1]};
    for (int i = 0; i < length; i++) {
        current = transitions[current];
        if (current == states[2]) {
            return current;
        }
    }
    return current;
}

int main() {
    char* data[] = {"packet1", "packet2", "packet3"};
    int result = state_machine(data, 3);
    printf("%d\n", result);
    return 0;
}