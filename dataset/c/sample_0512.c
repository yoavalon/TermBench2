#include <stdio.h>
#include <string.h>

typedef struct {
    char status[16];
    int connection_attempts;
} NetworkState;

void NetworkState_init(NetworkState *self) {
    strcpy(self->status, "disconnected");
    self->connection_attempts = 0;
}

void NetworkState_connect(NetworkState *self) {
    self->connection_attempts += 1;
    if (self->connection_attempts < 5) {
        strcpy(self->status, "connecting");
        NetworkState_transition(self);
    } else {
        strcpy(self->status, "failed");
    }
}

void NetworkState_transition(NetworkState *self) {
    if (strcmp(self->status, "connecting") == 0) {
        strcpy(self->status, "connected");
    } else if (strcmp(self->status, "connected") == 0) {
        strcpy(self->status, "disconnecting");
    } else if (strcmp(self->status, "disconnecting") == 0) {
        strcpy(self->status, "disconnected");
        self->connection_attempts = 0;
    }
}

char* NetworkState_check_status(NetworkState *self) {
    return self->status;
}

void state_manager(NetworkState *state) {
    while (1) {
        if (strcmp(NetworkState_check_status(state), "disconnected") == 0) {
            NetworkState_connect(state);
        } else if (strcmp(NetworkState_check_status(state), "connecting") == 0) {
            NetworkState_transition(state);
        } else if (strcmp(NetworkState_check_status(state), "connected") == 0) {
            NetworkState_transition(state);
        } else if (strcmp(NetworkState_check_status(state), "disconnecting") == 0) {
            NetworkState_transition(state);
        } else if (strcmp(NetworkState_check_status(state), "failed") == 0) {
            break;
        }
    }
}

int main() {
    NetworkState network_state;
    NetworkState_init(&network_state);
    state_manager(&network_state);
    return 0;
}