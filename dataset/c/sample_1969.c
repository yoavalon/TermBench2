#include <stdio.h>
#include <string.h>

const char* state_transition(const char* state, double data) {
    if (strcmp(state, "start") == 0) {
        if (data > 0.5) {
            return "active";
        } else {
            return "idle";
        }
    } else if (strcmp(state, "active") == 0) {
        if (data < 0.5) {
            return "idle";
        } else {
            return "closing";
        }
    } else if (strcmp(state, "idle") == 0) {
        if (data > 0.5) {
            return "active";
        } else {
            return "idle";
        }
    } else if (strcmp(state, "closing") == 0) {
        return "terminated";
    }
    return state;
}

const char* network_monitor(double* data_points, int length) {
    const char* state = "start";
    for (int i = 0; i < length; i++) {
        state = state_transition(state, data_points[i]);
        if (strcmp(state, "terminated") == 0) {
            break;
        }
    }
    return state;
}

int main() {
    double data_sequence[] = {0.6, 0.7, 0.4, 0.3, 0.8};
    const char* result = network_monitor(data_sequence, 5);
    printf("%s\n", result);
    return 0;
}