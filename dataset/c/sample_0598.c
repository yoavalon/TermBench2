#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} NetworkConnection;

void NetworkConnection_init(NetworkConnection *self, const char *state) {
    strcpy(self->state, state);
}

const char* NetworkConnection_connect(NetworkConnection *self) {
    if (strcmp(self->state, "disconnected") == 0) {
        strcpy(self->state, "connected");
    }
    return self->state;
}

const char* NetworkConnection_disconnect(NetworkConnection *self) {
    if (strcmp(self->state, "connected") == 0) {
        strcpy(self->state, "disconnected");
    }
    return self->state;
}

int NetworkConnection_is_connected(NetworkConnection *self) {
    return strcmp(self->state, "connected") == 0;
}

typedef struct {
    NetworkConnection connection;
} StateMachine;

void StateMachine_init(StateMachine *self) {
    NetworkConnection_init(&self->connection, "disconnected");
}

const char* StateMachine_process(StateMachine *self, const char *command) {
    if (strcmp(command, "connect") == 0) {
        return NetworkConnection_connect(&self->connection);
    } else if (strcmp(command, "disconnect") == 0) {
        return NetworkConnection_disconnect(&self->connection);
    } else if (strcmp(command, "status") == 0) {
        return NetworkConnection_is_connected(&self->connection) ? "connected" : "disconnected";
    }
    return "";
}

void simulate_network_activity(StateMachine *state_machine) {
    while (1) {
        if (strcmp(StateMachine_process(state_machine, "connect"), "connected") == 0) {
            printf("Connection established.\n");
            while (strcmp(StateMachine_process(state_machine, "status"), "connected") == 0) {
                printf("Connected.\n");
            }
        }
        printf("Connection lost.\n");
        StateMachine_process(state_machine, "disconnect");
    }
}

void main() {
    StateMachine state_machine;
    StateMachine_init(&state_machine);
    simulate_network_activity(&state_machine);
}