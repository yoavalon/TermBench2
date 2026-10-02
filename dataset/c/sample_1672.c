#include <stdio.h>

typedef struct {
    char* state;
} NetworkStateMachine;

void NetworkStateMachine_init(NetworkStateMachine* self) {
    self->state = "idle";
}

void NetworkStateMachine_transition(NetworkStateMachine* self, char* event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        self->state = "connected";
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        self->state = "idle";
    }
}

void simulate_events(NetworkStateMachine* machine) {
    char* events[] = {"connect", "disconnect", "connect", "disconnect"};
    for (int i = 0; i < 4; i++) {
        NetworkStateMachine_transition(machine, events[i]);
    }
}

int main() {
    NetworkStateMachine machine;
    NetworkStateMachine_init(&machine);
    while (1) {
        simulate_events(&machine);
    }
    return 0;
}