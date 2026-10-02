#include <stdio.h>

typedef struct {
    char* state;
    int sequence[5];
    int index;
} StateMachine;

StateMachine* StateMachine_init() {
    StateMachine* self = (StateMachine*)malloc(sizeof(StateMachine));
    self->state = "idle";
    self->sequence[0] = 1;
    self->sequence[1] = 2;
    self->sequence[2] = 3;
    self->sequence[3] = 4;
    self->sequence[4] = 5;
    self->index = 0;
    return self;
}

char* StateMachine_transition(StateMachine* self) {
    if (strcmp(self->state, "idle") == 0) {
        self->state = "active";
    } else if (strcmp(self->state, "active") == 0) {
        self->state = "idle";
    }
    return self->state;
}

int StateMachine_process_sequence(StateMachine* self) {
    if (strcmp(self->state, "active") == 0) {
        if (self->index < 5) {
            int value = self->sequence[self->index];
            self->index += 1;
            return value;
        } else {
            self->index = 0;
        }
    }
    return -1;
}

typedef struct {
    StateMachine* state_machine;
    char* connection_status;
} NetworkConnection;

NetworkConnection* NetworkConnection_init() {
    NetworkConnection* self = (NetworkConnection*)malloc(sizeof(NetworkConnection));
    self->state_machine = StateMachine_init();
    self->connection_status = "disconnected";
    return self;
}

int NetworkConnection_connect(NetworkConnection* self) {
    if (strcmp(StateMachine_transition(self->state_machine), "active") == 0) {
        self->connection_status = "connected";
        return StateMachine_process_sequence(self->state_machine);
    }
    return -1;
}

void NetworkConnection_disconnect(NetworkConnection* self) {
    self->connection_status = "disconnected";
    StateMachine_transition(self->state_machine);
}

void main() {
    NetworkConnection* network = NetworkConnection_init();
    while (1) {
        int result = NetworkConnection_connect(network);
        if (result != -1) {
            printf("%d\n", result);
        } else {
            NetworkConnection_disconnect(network);
        }
    }
}