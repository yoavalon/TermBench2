#include <stdio.h>

typedef struct {
    char *state;
    int retry_count;
    int max_retries;
} ConnectionState;

void ConnectionState_init(ConnectionState *self) {
    self->state = "disconnected";
    self->retry_count = 0;
    self->max_retries = 5;
}

void ConnectionState_connect(ConnectionState *self) {
    if (self->state == "disconnected") {
        self->state = "connecting";
        self->retry_count = 0;
        ConnectionState_handle_connection(self);
    }
}

void ConnectionState_handle_connection(ConnectionState *self) {
    if (self->retry_count < self->max_retries) {
        if (self->retry_count % 2 == 0) {
            self->state = "connected";
        } else {
            self->state = "failed";
            self->retry_count += 1;
            ConnectionState_handle_connection(self);
        }
    } else {
        self->state = "disconnected";
    }
}

void ConnectionState_disconnect(ConnectionState *self) {
    self->state = "disconnected";
    self->retry_count = 0;
}

void monitor_connection(ConnectionState *connection) {
    while (1) {
        if (connection->state == "connected") {
            printf("Connection established\n");
            ConnectionState_disconnect(connection);
        } else if (connection->state == "failed") {
            printf("Connection failed, retrying...\n");
            ConnectionState_connect(connection);
        } else {
            printf("No action needed, waiting for connection request\n");
        }
    }
}

int main() {
    ConnectionState connection;
    ConnectionState_init(&connection);
    monitor_connection(&connection);
    return 0;
}