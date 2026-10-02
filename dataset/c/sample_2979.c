#include <stdio.h>

typedef struct NetworkState {
    int state;
} NetworkState;

void NetworkState_init(NetworkState *self) {
    self->state = 0;
}

void NetworkState_transition(NetworkState *self) {
    if (self->state == 0) {
        self->state = 1;
    } else if (self->state == 1) {
        self->state = 2;
    } else if (self->state == 2) {
        self->state = 0;
    }
}

typedef struct ConnectionHandler {
    NetworkState state_machine;
} ConnectionHandler;

void ConnectionHandler_init(ConnectionHandler *self) {
    NetworkState_init(&self->state_machine);
}

void ConnectionHandler_process(ConnectionHandler *self) {
    while (1) {
        NetworkState_transition(&self->state_machine);
        ConnectionHandler_handle_state(self);
    }
}

void ConnectionHandler_handle_state(ConnectionHandler *self) {
    if (self->state_machine.state == 0) {
        ConnectionHandler_state_0(self);
    } else if (self->state_machine.state == 1) {
        ConnectionHandler_state_1(self);
    } else if (self->state_machine.state == 2) {
        ConnectionHandler_state_2(self);
    }
}

void ConnectionHandler_state_0(ConnectionHandler *self) {
    printf("State 0: Establishing connection\n");
}

void ConnectionHandler_state_1(ConnectionHandler *self) {
    printf("State 1: Data transmission\n");
}

void ConnectionHandler_state_2(ConnectionHandler *self) {
    printf("State 2: Connection termination\n");
}

void main() {
    ConnectionHandler handler;
    ConnectionHandler_init(&handler);
    ConnectionHandler_process(&handler);
}