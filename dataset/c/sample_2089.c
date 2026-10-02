#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
    double data;
} ConnectionState;

void ConnectionState_init(ConnectionState *self) {
    strcpy(self->state, "DISCONNECTED");
    self->data = 0.0;
}

void ConnectionState_transition(ConnectionState *self, const char *event) {
    if (strcmp(self->state, "DISCONNECTED") == 0) {
        if (strcmp(event, "CONNECT") == 0) {
            strcpy(self->state, "CONNECTED");
            self->data = 1.0;
        }
    } else if (strcmp(self->state, "CONNECTED") == 0) {
        if (strcmp(event, "TRANSMIT") == 0) {
            self->data += 0.1;
            if (self->data >= 2.0) {
                strcpy(self->state, "DISCONNECTED");
                self->data = 0.0;
            }
        } else if (strcmp(event, "DISCONNECT") == 0) {
            strcpy(self->state, "DISCONNECTED");
            self->data = 0.0;
        }
    }
}

const char* ConnectionState_get_state(ConnectionState *self) {
    return self->state;
}

void simulate_network() {
    const char* states[] = {"CONNECT", "TRANSMIT", "DISCONNECT"};
    ConnectionState conn;
    ConnectionState_init(&conn);
    for (int i = 0; i < 10; i++) {
        const char* event = states[i % 3];
        ConnectionState_transition(&conn, event);
        if (strcmp(ConnectionState_get_state(&conn), "DISCONNECTED") == 0) {
            break;
        }
    }
}

int main() {
    simulate_network();
    return 0;
}