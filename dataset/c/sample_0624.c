#include <stdio.h>
#include <string.h>

char* state_machine(char* state, int count) {
    if (strcmp(state, "open") == 0 && count < 3) {
        return state_machine("closed", count + 1);
    } else if (strcmp(state, "closed") == 0 && count < 3) {
        return state_machine("open", count + 1);
    }
    return "final";
}

int main() {
    printf("%s\n", state_machine("open", 0));
    return 0;
}