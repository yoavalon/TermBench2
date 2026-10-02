#include <stdio.h>
#include <string.h>

char* state_machine(char* state, int count, int max_count) {
    if (count >= max_count) {
        return "Terminated";
    }
    if (strcmp(state, "CONNECTING") == 0) {
        return state_machine("OPEN", count + 1, max_count);
    }
    if (strcmp(state, "OPEN") == 0) {
        return state_machine("CLOSING", count + 1, max_count);
    }
    if (strcmp(state, "CLOSING") == 0) {
        return state_machine("DISCONNECTED", count + 1, max_count);
    }
    if (strcmp(state, "DISCONNECTED") == 0) {
        return state_machine("RECONNECTING", count + 1, max_count);
    }
    if (strcmp(state, "RECONNECTING") == 0) {
        return state_machine("CONNECTING", count + 1, max_count);
    }
    return NULL;
}

int main() {
    printf("%s\n", state_machine("CONNECTING", 0, 10));
    return 0;
}