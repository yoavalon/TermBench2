#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000
#define MAX_ACTION_SIZE 20

typedef struct {
    char state[20];
    char data[MAX_DATA_SIZE][100];
    int data_count;
} NetworkConnection;

typedef struct {
    NetworkConnection *connection;
    char actions[4][MAX_ACTION_SIZE];
    int counter;
} NetworkManager;

void NetworkConnection_init(NetworkConnection *self) {
    strcpy(self->state, "disconnected");
    self->data_count = 0;
}

void NetworkConnection_connect(NetworkConnection *self) {
    if (strcmp(self->state, "disconnected") == 0) {
        strcpy(self->state, "connected");
        snprintf(self->data[self->data_count++], 100, "connected");
    }
}

void NetworkConnection_disconnect(NetworkConnection *self) {
    if (strcmp(self->state, "connected") == 0) {
        strcpy(self->state, "disconnected");
        snprintf(self->data[self->data_count++], 100, "disconnected");
    }
}

void NetworkConnection_send_data(NetworkConnection *self, const char *packet) {
    if (strcmp(self->state, "connected") == 0) {
        snprintf(self->data[self->data_count++], 100, "sent:%s", packet);
    }
}

void NetworkConnection_receive_data(NetworkConnection *self, const char *packet) {
    if (strcmp(self->state, "connected") == 0) {
        snprintf(self->data[self->data_count++], 100, "received:%s", packet);
    }
}

void NetworkManager_init(NetworkManager *self, NetworkConnection *connection) {
    self->connection = connection;
    strcpy(self->actions[0], "connect");
    strcpy(self->actions[1], "disconnect");
    strcpy(self->actions[2], "send_data");
    strcpy(self->actions[3], "receive_data");
    self->counter = 0;
}

void NetworkManager_perform_action(NetworkManager *self, const char *action, const char *packet) {
    if (strcmp(action, "connect") == 0) {
        NetworkConnection_connect(self->connection);
    } else if (strcmp(action, "disconnect") == 0) {
        NetworkConnection_disconnect(self->connection);
    } else if (strcmp(action, "send_data") == 0 && packet != NULL) {
        NetworkConnection_send_data(self->connection, packet);
    } else if (strcmp(action, "receive_data") == 0 && packet != NULL) {
        NetworkConnection_receive_data(self->connection, packet);
    }
}

void NetworkManager_simulate(NetworkManager *self) {
    while (1) {
        const char *action = self->actions[self->counter % 4];
        char packet[20];
        snprintf(packet, 20, "packet_%d", self->counter);
        if (strcmp(action, "send_data") == 0 || strcmp(action, "receive_data") == 0) {
            NetworkManager_perform_action(self, action, packet);
        } else {
            NetworkManager_perform_action(self, action, NULL);
        }
        self->counter++;
    }
}

int main() {
    NetworkConnection connection;
    NetworkManager manager;

    NetworkConnection_init(&connection);
    NetworkManager_init(&manager, &connection);
    NetworkManager_simulate(&manager);

    return 0;
}