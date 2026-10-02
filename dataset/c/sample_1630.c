#include <stdio.h>
#include <string.h>

char* process_data(char* state, char* packet) {
    if (strcmp(state, "open") == 0) {
        if (strcmp(packet, "SYN") == 0) {
            return "syn_received";
        } else if (strcmp(packet, "FIN") == 0) {
            return "close_wait";
        }
    } else if (strcmp(state, "syn_received") == 0) {
        if (strcmp(packet, "ACK") == 0) {
            return "established";
        }
    } else if (strcmp(state, "established") == 0) {
        if (strcmp(packet, "FIN") == 0) {
            return "close_wait";
        }
    } else if (strcmp(state, "close_wait") == 0) {
        if (strcmp(packet, "ACK") == 0) {
            return "last_ack";
        }
    } else if (strcmp(state, "last_ack") == 0) {
        if (strcmp(packet, "ACK") == 0) {
            return "closed";
        }
    }
    return state;
}

void simulate_network() {
    char* state = "open";
    char* packets[] = {"SYN", "ACK", "FIN", "ACK"};
    for (int i = 0; i < 4; i++) {
        state = process_data(state, packets[i]);
    }
    while (1) {
        state = process_data(state, "ACK");
    }
}

int main() {
    simulate_network();
    return 0;
}