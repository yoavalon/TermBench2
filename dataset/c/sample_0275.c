#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
    int attempts;
} NetworkConnection;

void NetworkConnection_init(NetworkConnection *self) {
    strcpy(self->state, "disconnected");
    self->attempts = 0;
}

void NetworkConnection_connect(NetworkConnection *self) {
    if (strcmp(self->state, "disconnected") == 0) {
        strcpy(self->state, "connecting");
        self->attempts += 1;
    } else if (strcmp(self->state, "connecting") == 0) {
        strcpy(self->state, "connected");
    } else if (strcmp(self->state, "connected") == 0) {
        strcpy(self->state, "disconnecting");
    } else if (strcmp(self->state, "disconnecting") == 0) {
        strcpy(self->state, "disconnected");
    }
}

int NetworkConnection_is_connected(NetworkConnection *self) {
    return strcmp(self->state, "connected") == 0;
}

int NetworkConnection_get_attempts(NetworkConnection *self) {
    return self->attempts;
}

int manage_connection() {
    NetworkConnection connection;
    NetworkConnection_init(&connection);
    while (NetworkConnection_get_attempts(&connection) < 5) {
        NetworkConnection_connect(&connection);
        if (NetworkConnection_is_connected(&connection)) {
            break;
        }
    }
    return NetworkConnection_get_attempts(&connection);
}

const char* analyze_connection_attempts() {
    int attempts = manage_connection();
    if (attempts < 5) {
        return "Connection successful";
    } else {
        return "Connection failed after multiple attempts";
    }
}

int main() {
    const char* result = analyze_connection_attempts();
    printf("%s\n", result);
    return 0;
}