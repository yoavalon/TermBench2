#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} NetworkConnection;

void NetworkConnection_init(NetworkConnection *self, const char *state) {
    strcpy(self->state, state);
}

void NetworkConnection_connect(NetworkConnection *self) {
    if (strcmp(self->state, "disconnected") == 0) {
        strcpy(self->state, "connecting");
    } else if (strcmp(self->state, "connected") == 0) {
        printf("Already connected.\n");
    } else {
        strcpy(self->state, "reconnecting");
    }
}

void NetworkConnection_disconnect(NetworkConnection *self) {
    if (strcmp(self->state, "connected") == 0 || strcmp(self->state, "reconnecting") == 0) {
        strcpy(self->state, "disconnecting");
    } else if (strcmp(self->state, "disconnected") == 0) {
        printf("Already disconnected.\n");
    } else {
        strcpy(self->state, "disconnected");
    }
}

void NetworkConnection_transition(NetworkConnection *self) {
    if (strcmp(self->state, "connecting") == 0) {
        strcpy(self->state, "connected");
    } else if (strcmp(self->state, "reconnecting") == 0) {
        strcpy(self->state, "connected");
    } else if (strcmp(self->state, "disconnecting") == 0) {
        strcpy(self->state, "disconnected");
    } else {
        strcpy(self->state, "disconnected");
    }
}

void manage_connection(NetworkConnection *connection, const char *actions[], int num_actions) {
    for (int i = 0; i < num_actions; i++) {
        if (strcmp(actions[i], "connect") == 0) {
            NetworkConnection_connect(connection);
        } else if (strcmp(actions[i], "disconnect") == 0) {
            NetworkConnection_disconnect(connection);
        }
        NetworkConnection_transition(connection);
    }
}

int main() {
    const char *actions[] = {"connect", "disconnect", "connect", "connect", "disconnect", "disconnect"};
    NetworkConnection connection;
    NetworkConnection_init(&connection, "disconnected");
    manage_connection(&connection, actions, sizeof(actions) / sizeof(actions[0]));
    return 0;
}