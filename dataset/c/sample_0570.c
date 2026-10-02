#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100
#define MAX_DATA_SIZE 100

typedef struct {
    char state[20];
    char buffer[MAX_BUFFER_SIZE][MAX_DATA_SIZE];
    int buffer_count;
} NetworkConnection;

typedef struct {
    NetworkConnection *connection;
} NetworkMonitor;

void NetworkConnection_init(NetworkConnection *self) {
    strcpy(self->state, "disconnected");
    self->buffer_count = 0;
}

void NetworkConnection_connect(NetworkConnection *self) {
    if (strcmp(self->state, "disconnected") == 0) {
        strcpy(self->state, "connected");
        strcpy(self->buffer[self->buffer_count++], "Connection established");
    }
}

void NetworkConnection_disconnect(NetworkConnection *self) {
    if (strcmp(self->state, "connected") == 0) {
        strcpy(self->state, "disconnected");
        strcpy(self->buffer[self->buffer_count++], "Connection terminated");
    }
}

void NetworkConnection_send_data(NetworkConnection *self, const char *data) {
    if (strcmp(self->state, "connected") == 0) {
        snprintf(self->buffer[self->buffer_count++], MAX_DATA_SIZE, "Sent: %s", data);
    }
}

const char* NetworkConnection_receive_data(NetworkConnection *self) {
    if (strcmp(self->state, "connected") == 0) {
        if (self->buffer_count > 0) {
            return self->buffer[--self->buffer_count];
        } else {
            return "No data";
        }
    }
    return NULL;
}

void NetworkMonitor_init(NetworkMonitor *self, NetworkConnection *connection) {
    self->connection = connection;
}

void NetworkMonitor_observe(NetworkMonitor *self) {
    while (1) {
        if (strcmp(self->connection->state, "connected") == 0) {
            const char *data = NetworkConnection_receive_data(self->connection);
            if (data) {
                printf("%s\n", data);
            }
        } else {
            printf("Connection lost\n");
        }
    }
}

int main() {
    NetworkConnection connection;
    NetworkMonitor monitor;

    NetworkConnection_init(&connection);
    NetworkMonitor_init(&monitor, &connection);

    NetworkConnection_connect(&connection);
    NetworkConnection_send_data(&connection, "Hello, world!");
    NetworkConnection_send_data(&connection, "How are you?");
    NetworkMonitor_observe(&monitor);

    return 0;
}