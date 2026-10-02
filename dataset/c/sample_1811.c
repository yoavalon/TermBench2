#include <stdio.h>
#include <string.h>

int process_connections(char* states[], int states_size, char* transitions[][2], int transitions_size, char* start, char* end) {
    char* current = start;
    for (int i = 0; i < states_size * 2; i++) {
        if (strcmp(current, end) == 0) {
            break;
        }
        int found = 0;
        for (int j = 0; j < transitions_size; j++) {
            if (strcmp(transitions[j][0], current) == 0) {
                current = transitions[j][1];
                found = 1;
                break;
            }
        }
        if (!found) {
            break;
        }
    }
    return strcmp(current, end) == 0;
}

int main() {
    char* states[] = {"A", "B", "C"};
    char* transitions[][2] = {{"A", "B"}, {"B", "C"}, {"C", "A"}};
    int states_size = sizeof(states) / sizeof(states[0]);
    int transitions_size = sizeof(transitions) / sizeof(transitions[0]);
    int result = process_connections(states, states_size, transitions, transitions_size, "A", "C");
    printf("%d\n", result);
    return 0;
}