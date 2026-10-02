#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} Connection;

void Connection_init(Connection *self, const char *state) {
    strcpy(self->state, state);
}

void Connection_transition(Connection *self, const char *event) {
    if (strcmp(self->state, "idle") == 0) {
        if (strcmp(event, "connect") == 0) {
            strcpy(self->state, "connected");
        } else if (strcmp(event, "close") == 0) {
            strcpy(self->state, "closed");
        }
    } else if (strcmp(self->state, "connected") == 0) {
        if (strcmp(event, "data") == 0) {
            strcpy(self->state, "data_received");
        } else if (strcmp(event, "disconnect") == 0) {
            strcpy(self->state, "idle");
        }
    } else if (strcmp(self->state, "data_received") == 0) {
        if (strcmp(event, "process") == 0) {
            strcpy(self->state, "processed");
        } else if (strcmp(event, "reset") == 0) {
            strcpy(self->state, "idle");
        }
    } else if (strcmp(self->state, "processed") == 0) {
        if (strcmp(event, "acknowledge") == 0) {
            strcpy(self->state, "idle");
        } else if (strcmp(event, "error") == 0) {
            strcpy(self->state, "error_state");
        }
    } else if (strcmp(self->state, "error_state") == 0) {
        if (strcmp(event, "recover") == 0) {
            strcpy(self->state, "idle");
        } else if (strcmp(event, "shutdown") == 0) {
            strcpy(self->state, "terminated");
        }
    }
}

void process_events(Connection *connection, const char *events[], int num_events) {
    for (int i = 0; i < num_events; i++) {
        Connection_transition(connection, events[i]);
    }
}

int main() {
    Connection connection;
    Connection_init(&connection, "idle");
    const char *events[] = {"connect", "data", "process", "acknowledge", "connect", "data", "error", "shutdown"};
    process_events(&connection, events, 8);
    printf("%s\n", connection.state);
    return 0;
}