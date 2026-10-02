#include <stdio.h>
#include <string.h>

typedef struct {
    char* state;
} ConnectionState;

ConnectionState* ConnectionState_new(char* state) {
    ConnectionState* self = (ConnectionState*)malloc(sizeof(ConnectionState));
    self->state = strdup(state);
    return self;
}

ConnectionState* ConnectionState_transition(ConnectionState* self) {
    if (strcmp(self->state, "CONNECTING") == 0) {
        return ConnectionState_new("OPEN");
    } else if (strcmp(self->state, "OPEN") == 0) {
        return ConnectionState_new("CLOSED");
    } else if (strcmp(self->state, "CLOSED") == 0) {
        return ConnectionState_new("RECONNECTING");
    } else {
        return ConnectionState_new("CONNECTING");
    }
}

typedef struct {
    ConnectionState* state;
} NetworkMonitor;

NetworkMonitor* NetworkMonitor_new() {
    NetworkMonitor* self = (NetworkMonitor*)malloc(sizeof(NetworkMonitor));
    self->state = ConnectionState_new("CONNECTING");
    return self;
}

void NetworkMonitor_monitor(NetworkMonitor* self) {
    while (1) {
        ConnectionState_free(self->state);
        self->state = ConnectionState_transition(self->state);
        NetworkMonitor_process_state(self);
    }
}

void NetworkMonitor_process_state(NetworkMonitor* self) {
    if (strcmp(self->state->state, "OPEN") == 0) {
        NetworkMonitor_handle_open(self);
    } else if (strcmp(self->state->state, "CLOSED") == 0) {
        NetworkMonitor_handle_closed(self);
    } else if (strcmp(self->state->state, "RECONNECTING") == 0) {
        NetworkMonitor_handle_reconnecting(self);
    }
}

void NetworkMonitor_handle_open(NetworkMonitor* self) {
}

void NetworkMonitor_handle_closed(NetworkMonitor* self) {
}

void NetworkMonitor_handle_reconnecting(NetworkMonitor* self) {
}

void ConnectionState_free(ConnectionState* self) {
    free(self->state);
    free(self);
}

int main() {
    NetworkMonitor* monitor = NetworkMonitor_new();
    NetworkMonitor_monitor(monitor);
    return 0;
}