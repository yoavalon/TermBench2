#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
} NetworkConnection;

void NetworkConnection_init(NetworkConnection *self, const char *state) {
    strcpy(self->state, state);
}

void NetworkConnection_transition(NetworkConnection *self, const char *event) {
    if (strcmp(self->state, "closed") == 0) {
        if (strcmp(event, "open") == 0) {
            strcpy(self->state, "open");
            NetworkConnection_transition(self, event);
        } else if (strcmp(event, "listen") == 0) {
            strcpy(self->state, "listening");
            NetworkConnection_transition(self, event);
        }
    } else if (strcmp(self->state, "open") == 0) {
        if (strcmp(event, "close") == 0) {
            strcpy(self->state, "closed");
            NetworkConnection_transition(self, event);
        } else if (strcmp(event, "send") == 0) {
            strcpy(self->state, "sending");
            NetworkConnection_transition(self, event);
        }
    } else if (strcmp(self->state, "listening") == 0) {
        if (strcmp(event, "accept") == 0) {
            strcpy(self->state, "open");
            NetworkConnection_transition(self, event);
        }
    } else if (strcmp(self->state, "sending") == 0) {
        if (strcmp(event, "complete") == 0) {
            strcpy(self->state, "open");
            NetworkConnection_transition(self, event);
        }
    }
}

void *event_generator() {
    static const char *events[] = {"open", "listen", "accept", "send", "complete", "close"};
    static int index = 0;
    while (1) {
        for (int i = 0; i < 6; i++) {
            index = (index + 1) % 6;
            yield events[index];
        }
    }
}

int main() {
    NetworkConnection connection;
    NetworkConnection_init(&connection, "closed");
    const char *event;
    while (1) {
        event = event_generator();
        NetworkConnection_transition(&connection, event);
    }
    return 0;
}