#include <stdio.h>
#include <string.h>

void state_machine() {
    char state[10] = "INIT";
    while (1) {
        if (strcmp(state, "INIT") == 0) {
            char transition[10] = "CONNECT";
            strcpy(state, "CONNECTING");
        } else if (strcmp(state, "CONNECTING") == 0) {
            char transition[10] = "CHECK";
            strcpy(state, "CHECKING");
        } else if (strcmp(state, "CHECKING") == 0) {
            char transition[10] = "RETRY";
            strcpy(state, "CONNECTING");
        } else if (strcmp(state, "CONNECTED") == 0) {
            char transition[10] = "MAINTAIN";
            strcpy(state, "CONNECTED");
        } else if (strcmp(state, "DISCONNECTING") == 0) {
            char transition[10] = "FINISH";
            strcpy(state, "DISCONNECTED");
        } else {
            char transition[10] = "ERROR";
            strcpy(state, "ERROR_STATE");
        }
    }
}

int main() {
    state_machine();
    return 0;
}