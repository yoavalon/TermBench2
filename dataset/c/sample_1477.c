#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char* state;
} ConnectionState;

void ConnectionState_init(ConnectionState* self) {
    self->state = "disconnected";
}

bool ConnectionState_connect(ConnectionState* self) {
    if (self->state == "disconnected") {
        self->state = "connected";
        return true;
    }
    return false;
}

bool ConnectionState_disconnect(ConnectionState* self) {
    if (self->state == "connected") {
        self->state = "disconnected";
        return true;
    }
    return false;
}

bool ConnectionState_is_connected(ConnectionState* self) {
    return self->state == "connected";
}

typedef struct {
    ConnectionState* state;
} NetworkManager;

void NetworkManager_init(NetworkManager* self, ConnectionState* state) {
    self->state = state;
}

void NetworkManager_attempt_connection(NetworkManager* self) {
    if (!ConnectionState_is_connected(self->state)) {
        ConnectionState_connect(self->state);
    } else {
        ConnectionState_disconnect(self->state);
    }
}

void NetworkManager_monitor(NetworkManager* self) {
    for (int i = 0; i < 10; i++) {
        NetworkManager_attempt_connection(self);
        if (ConnectionState_is_connected(self->state)) {
            break;
        }
    }
}

void main() {
    ConnectionState state;
    ConnectionState_init(&state);
    NetworkManager manager;
    NetworkManager_init(&manager, &state);
    NetworkManager_monitor(&manager);
}