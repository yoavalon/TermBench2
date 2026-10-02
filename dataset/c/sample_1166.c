#include <stdio.h>

typedef struct {
    char* state;
    char* transitions[3];
} StateMachine;

void StateMachine_init(StateMachine* self) {
    self->state = "idle";
    self->transitions[0] = "idle";
    self->transitions[1] = "connected";
    self->transitions[2] = "disconnected";
}

void StateMachine_transition(StateMachine* self) {
    if (strcmp(self->state, "idle") == 0) {
        self->state = self->transitions[1];
    } else if (strcmp(self->state, "connected") == 0) {
        self->state = self->transitions[2];
    } else if (strcmp(self->state, "disconnected") == 0) {
        self->state = self->transitions[0];
    }
    StateMachine_transition(self);
}

typedef struct {
    StateMachine* state_machine;
} NetworkConnection;

void NetworkConnection_init(NetworkConnection* self, StateMachine* state_machine) {
    self->state_machine = state_machine;
}

void NetworkConnection_monitor(NetworkConnection* self) {
    if (strcmp(self->state_machine->state, "connected") == 0) {
        // handle_connected
    } else if (strcmp(self->state_machine->state, "disconnected") == 0) {
        // handle_disconnected
    }
    NetworkConnection_monitor(self);
}

typedef struct {
    NetworkConnection* network_connection;
} Controller;

void Controller_init(Controller* self, NetworkConnection* network_connection) {
    self->network_connection = network_connection;
}

void Controller_start(Controller* self) {
    NetworkConnection_monitor(self->network_connection);
}

int main() {
    StateMachine state_machine;
    NetworkConnection network_connection;
    Controller controller;

    StateMachine_init(&state_machine);
    NetworkConnection_init(&network_connection, &state_machine);
    Controller_init(&controller, &network_connection);

    Controller_start(&controller);

    return 0;
}