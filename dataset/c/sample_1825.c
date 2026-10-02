#include <stdio.h>
#include <string.h>

const char* process_connections(const char* states[], int states_size, const char* transitions[][2], int transitions_size, const char* initial, const char* final[], int final_size) {
    const char* state = initial;
    for (int i = 0; i < 10; i++) {
        int found = 0;
        for (int j = 0; j < final_size; j++) {
            if (strcmp(state, final[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
        for (int j = 0; j < transitions_size; j++) {
            if (strcmp(state, transitions[j][0]) == 0) {
                state = transitions[j][1];
                break;
            }
        }
    }
    return state;
}

int main() {
    const char* states[] = {"a", "b", "c"};
    const char* transitions[][2] = {
        {"a", "b"},
        {"b", "c"},
        {"c", "a"}
    };
    const char* initial = "a";
    const char* final[] = {"c"};
    const char* result = process_connections(states, 3, transitions, 3, initial, final, 1);
    printf("%s\n", result);
    return 0;
}