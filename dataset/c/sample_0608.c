#include <stdio.h>
#include <string.h>

char* state_machine(char* state, int count) {
    if (count == 0) {
        return "Idle";
    } else if (strcmp(state, "Connecting") == 0) {
        return state_machine("Connected", count - 1);
    } else if (strcmp(state, "Connected") == 0) {
        return state_machine("Disconnecting", count - 1);
    } else if (strcmp(state, "Disconnecting") == 0) {
        return state_machine("Idle", count - 1);
    } else {
        return "Invalid State";
    }
}

int main() {
    printf("%s\n", state_machine("Connecting", 3));
    return 0;
}