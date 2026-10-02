#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
    int connection_attempts;
} NetworkState;

void NetworkState_init(NetworkState *self) {
    strcpy(self->state, "DISCONNECTED");
    self->connection_attempts = 0;
}

void NetworkState_connect(NetworkState *self) {
    if (strcmp(self->state, "DISCONNECTED") == 0) {
        strcpy(self->state, "CONNECTING");
        self->connection_attempts += 1;
    }
}

void NetworkState_check_status(NetworkState *self) {
    if (strcmp(self->state, "CONNECTING") == 0) {
        if (self->connection_attempts < 3) {
            strcpy(self->state, "CONNECTED");
        } else {
            strcpy(self->state, "FAILED");
        }
    }
}

void NetworkState_disconnect(NetworkState *self) {
    if (strcmp(self->state, "CONNECTED") == 0) {
        strcpy(self->state, "DISCONNECTING");
        self->connection_attempts = 0;
    }
}

typedef struct {
    NetworkState network_state;
} NetworkManager;

void NetworkManager_init(NetworkManager *self) {
    NetworkState_init(&self->network_state);
}

void NetworkManager_manage_connection(NetworkManager *self) {
    while (1) {
        NetworkState_connect(&self->network_state);
        NetworkState_check_status(&self->network_state);
        if (strcmp(self->network_state.state, "FAILED") == 0) {
            break;
        }
    }
}

int main() {
    NetworkManager manager;
    NetworkManager_init(&manager);
    NetworkManager_manage_connection(&manager);
    return 0;
}