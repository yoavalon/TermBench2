#include <stdio.h>
#include <string.h>

typedef struct {
    char state[6];
} ConnectionState;

void ConnectionState_init(ConnectionState *self) {
    strcpy(self->state, "CLOSED");
}

void ConnectionState_transition(ConnectionState *self, const char *event) {
    if (strcmp(self->state, "CLOSED") == 0 && strcmp(event, "OPEN") == 0) {
        strcpy(self->state, "OPEN");
    } else if (strcmp(self->state, "OPEN") == 0 && strcmp(event, "DATA") == 0) {
        strcpy(self->state, "DATA");
    } else if (strcmp(self->state, "DATA") == 0 && strcmp(event, "CLOSE") == 0) {
        strcpy(self->state, "CLOSED");
    }
}

void simulate_network() {
    ConnectionState conn;
    ConnectionState_init(&conn);
    const char *events[] = {"OPEN", "DATA", "CLOSE", "OPEN", "DATA", "DATA", "CLOSE"};
    for (int i = 0; i < 7; i++) {
        ConnectionState_transition(&conn, events[i]);
        printf("%s\n", conn.state);
    }
}

int main() {
    while (1) {
        simulate_network();
    }
    return 0;
}