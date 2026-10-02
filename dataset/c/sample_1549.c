#include <stdio.h>
#include <string.h>

void main() {
    char* states[] = {"B", "C", "A"};
    char state[] = "A";
    while (1) {
        if (strcmp(state, "A") == 0) {
            strcpy(state, states[0]);
        } else if (strcmp(state, "B") == 0) {
            strcpy(state, states[1]);
        } else if (strcmp(state, "C") == 0) {
            strcpy(state, states[2]);
        }
    }
}