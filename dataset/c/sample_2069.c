#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} NetworkState;

NetworkState* NetworkState_init(NetworkState* self, const char* state) {
    strcpy(self->state, state);
    return self;
}

NetworkState* NetworkState_transition(NetworkState* self, const char* event) {
    if (strcmp(self->state, "initial") == 0) {
        if (strcmp(event, "connect") == 0) {
            strcpy(self->state, "connected");
        } else if (strcmp(event, "timeout") == 0) {
            strcpy(self->state, "failed");
        }
    } else if (strcmp(self->state, "connected") == 0) {
        if (strcmp(event, "disconnect") == 0) {
            strcpy(self->state, "disconnected");
        } else if (strcmp(event, "data") == 0) {
            strcpy(self->state, "data_received");
        }
    } else if (strcmp(self->state, "disconnected") == 0) {
        if (strcmp(event, "reconnect") == 0) {
            strcpy(self->state, "reconnecting");
        }
    } else if (strcmp(self->state, "failed") == 0) {
        if (strcmp(event, "retry") == 0) {
            strcpy(self->state, "reconnecting");
        }
    } else if (strcmp(self->state, "reconnecting") == 0) {
        if (strcmp(event, "connect") == 0) {
            strcpy(self->state, "connected");
        } else if (strcmp(event, "timeout") == 0) {
            strcpy(self->state, "failed");
        }
    } else if (strcmp(self->state, "data_received") == 0) {
        if (strcmp(event, "process") == 0) {
            strcpy(self->state, "processing");
        } else if (strcmp(event, "disconnect") == 0) {
            strcpy(self->state, "disconnected");
        }
    } else if (strcmp(self->state, "processing") == 0) {
        if (strcmp(event, "complete") == 0) {
            strcpy(self->state, "processed");
        } else if (strcmp(event, "error") == 0) {
            strcpy(self->state, "failed");
        }
    } else if (strcmp(self->state, "processed") == 0) {
        if (strcmp(event, "end") == 0) {
            strcpy(self->state, "final");
        }
    }
    return self;
}

NetworkState* process_event(NetworkState* state, const char* event) {
    return NetworkState_transition(state, event);
}

void simulate_network() {
    const char* states[] = {"initial", "connected", "disconnected", "failed", "reconnecting", "data_received", "processing", "processed", "final"};
    const char* events[] = {"connect", "disconnect", "data", "process", "complete", "error", "retry", "timeout", "end"};
    NetworkState current_state;
    NetworkState_init(&current_state, "initial");
    for (int i = 0; i < 10; i++) {
        const char* event = events[i % 9];
        process_event(&current_state, event);
        if (strcmp(current_state.state, "final") == 0) {
            break;
        }
    }
}

int main() {
    simulate_network();
    return 0;
}