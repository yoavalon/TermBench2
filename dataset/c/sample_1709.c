#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} ConnectionState;

void ConnectionState_init(ConnectionState *self) {
    strcpy(self->state, "disconnected");
}

void ConnectionState_transition(ConnectionState *self, const char *event) {
    if (strcmp(self->state, "disconnected") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "disconnected");
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "data") == 0) {
        strcpy(self->state, "processing");
    } else if (strcmp(self->state, "processing") == 0 && strcmp(event, "complete") == 0) {
        strcpy(self->state, "connected");
    } else if (strcmp(self->state, "processing") == 0 && strcmp(event, "error") == 0) {
        strcpy(self->state, "error");
    }
}

void ConnectionState_get_state(const ConnectionState *self, char *state) {
    strcpy(state, self->state);
}

typedef struct {
    ConnectionState connection;
    const char *events[5];
    int event_index;
} NetworkManager;

void NetworkManager_init(NetworkManager *self) {
    ConnectionState_init(&self->connection);
    self->events[0] = "connect";
    self->events[1] = "disconnect";
    self->events[2] = "data";
    self->events[3] = "complete";
    self->events[4] = "error";
    self->event_index = 0;
}

const char *NetworkManager_generate_event(NetworkManager *self) {
    const char *event = self->events[self->event_index % 5];
    self->event_index += 1;
    return event;
}

void NetworkManager_simulate_network(NetworkManager *self) {
    while (1) {
        const char *event = NetworkManager_generate_event(self);
        ConnectionState_transition(&self->connection, event);
        char state[20];
        ConnectionState_get_state(&self->connection, state);
        printf("Event: %s, State: %s\n", event, state);
    }
}

int main() {
    NetworkManager network_manager;
    NetworkManager_init(&network_manager);
    NetworkManager_simulate_network(&network_manager);
    return 0;
}