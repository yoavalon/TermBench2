#include <stdio.h>
#include <string.h>

const char* analyze_network_connections(const char* connections[], int connections_size, const char* states[], int states_size, const char* transitions[][3], int transitions_size) {
    const char* current_state = states[0];
    for (int i = 0; i < connections_size; i++) {
        for (int j = 0; j < transitions_size; j++) {
            if (strcmp(transitions[j][0], current_state) == 0 && strcmp(transitions[j][1], connections[i]) == 0) {
                current_state = transitions[j][2];
                break;
            }
        }
    }
    return current_state;
}

int main() {
    const char* connections[] = {"open", "data", "close"};
    const char* states[] = {"idle", "active", "closed"};
    const char* transitions[][3] = {
        {"idle", "open", "active"},
        {"active", "data", "active"},
        {"active", "close", "closed"}
    };
    int connections_size = sizeof(connections) / sizeof(connections[0]);
    int states_size = sizeof(states) / sizeof(states[0]);
    int transitions_size = sizeof(transitions) / sizeof(transitions[0]);
    const char* result = analyze_network_connections(connections, connections_size, states, states_size, transitions, transitions_size);
    printf("%s\n", result);
    return 0;
}