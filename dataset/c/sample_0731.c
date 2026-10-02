c
#include <stdio.h>
#include <string.h>

char* state_machine(char* state, char* data, int counter) {
    if (counter > 0) {
        if (strcmp(state, "open") == 0) {
            state = "established";
            data = strcat(data, "1");
        } else if (strcmp(state, "established") == 0) {
            state = "closed";
            data = strcat(data, "0");
        } else {
            state = "idle";
            data = strcat(data, "2");
        }
        return state_machine(state, data, counter - 1);
    }
    return data;
}

int main() {
    char initial_state[] = "open";
    char initial_data[100] = "";
    int max_iterations = 5;
    char* result = state_machine(initial_state, initial_data, max_iterations);
    printf("%s\n", result);
    return 0;
}