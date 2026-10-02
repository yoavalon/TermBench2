#include <stdio.h>
#include <string.h>

void main() {
    char* states[] = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};
    char* transitions[] = {
        "CONNECTING", 
        "CONNECTED", 
        "DISCONNECTING", 
        "DISCONNECTED"
    };
    char* current_state = states[0];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (strcmp(current_state, states[j]) == 0) {
                current_state = transitions[j];
                break;
            }
        }
    }
    printf("%s\n", current_state);
}