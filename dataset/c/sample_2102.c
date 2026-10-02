#include <stdio.h>

void network_state_machine() {
    char* states[] = {"CONNECTING", "CONNECTED", "DISCONNECTING", "DISCONNECTED"};
    int current_state = 0;
    while (1) {
        if (current_state == 0) {
            current_state = 1;
        } else if (current_state == 1) {
            current_state = 2;
        } else if (current_state == 2) {
            current_state = 3;
        } else if (current_state == 3) {
            current_state = 0;
        }
    }
}

int main() {
    network_state_machine();
    return 0;
}