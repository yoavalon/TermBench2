#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} NetworkState;

void NetworkState_init(NetworkState *self, const char *state) {
    strcpy(self->state, state);
}

const char* NetworkState_transition(NetworkState *self, const char *event) {
    if (strcmp(self->state, "DISCONNECTED") == 0 && strcmp(event, "CONNECT") == 0) {
        return "CONNECTED";
    } else if (strcmp(self->state, "CONNECTED") == 0 && strcmp(event, "DISCONNECT") == 0) {
        return "DISCONNECTED";
    } else if (strcmp(self->state, "CONNECTED") == 0 && strcmp(event, "RECEIVE") == 0) {
        return "PROCESSING";
    } else if (strcmp(self->state, "PROCESSING") == 0 && strcmp(event, "SEND") == 0) {
        return "CONNECTED";
    } else {
        return self->state;
    }
}

typedef struct {
    NetworkState current_state;
} NetworkStateMachine;

void NetworkStateMachine_init(NetworkStateMachine *self) {
    NetworkState_init(&self->current_state, "DISCONNECTED");
}

const char* NetworkStateMachine_process_event(NetworkStateMachine *self, const char *event) {
    const char *new_state = NetworkState_transition(&self->current_state, event);
    NetworkState_init(&self->current_state, new_state);
    return new_state;
}

const char* generate_events(int *index) {
    const char *events[] = {"CONNECT", "RECEIVE", "SEND", "DISCONNECT"};
    return events[(*index)++ % 4];
}

void simulate_network() {
    NetworkStateMachine state_machine;
    NetworkStateMachine_init(&state_machine);
    int index = 0;
    while (1) {
        const char *event = generate_events(&index);
        const char *new_state = NetworkStateMachine_process_event(&state_machine, event);
        if (strcmp(new_state, "PROCESSING") == 0) {
            simulate_network();
        }
    }
}

int main() {
    simulate_network();
    return 0;
}