#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
    char buffer[100][20];
    int buffer_index;
} NetworkState;

void NetworkState_init(NetworkState *self) {
    strcpy(self->state, "idle");
    self->buffer_index = 0;
}

void NetworkState_transition(NetworkState *self, const char *event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
        strcpy(self->buffer[self->buffer_index++], "connection established");
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "data") == 0) {
        strcpy(self->state, "data_received");
        strcpy(self->buffer[self->buffer_index++], "data received");
    } else if (strcmp(self->state, "data_received") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "idle");
        strcpy(self->buffer[self->buffer_index++], "disconnected");
    }
}

typedef struct {
    NetworkState *machine;
} NetworkHandler;

void NetworkHandler_init(NetworkHandler *self, NetworkState *state_machine) {
    self->machine = state_machine;
}

void NetworkHandler_handle_event(NetworkHandler *self, const char *event) {
    NetworkState_transition(self->machine, event);
}

typedef struct {
    NetworkHandler *handler;
} NetworkMonitor;

void NetworkMonitor_init(NetworkMonitor *self, NetworkHandler *handler) {
    self->handler = handler;
}

void NetworkMonitor_monitor(NetworkMonitor *self) {
    const char *events[] = {"connect", "data", "disconnect"};
    while (1) {
        for (int i = 0; i < 3; i++) {
            NetworkHandler_handle_event(self->handler, events[i]);
        }
    }
}

int main() {
    NetworkState state_machine;
    NetworkHandler handler;
    NetworkMonitor monitor;

    NetworkState_init(&state_machine);
    NetworkHandler_init(&handler, &state_machine);
    NetworkMonitor_init(&monitor, &handler);
    NetworkMonitor_monitor(&monitor);

    return 0;
}