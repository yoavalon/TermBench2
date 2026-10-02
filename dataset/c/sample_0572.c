#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} ConnectionState;

void ConnectionState_init(ConnectionState *self) {
    strcpy(self->state, "DISCONNECTED");
}

void ConnectionState_transition(ConnectionState *self, const char *event) {
    if (strcmp(self->state, "DISCONNECTED") == 0 && strcmp(event, "CONNECT") == 0) {
        strcpy(self->state, "CONNECTED");
    } else if (strcmp(self->state, "CONNECTED") == 0 && strcmp(event, "DATA") == 0) {
        strcpy(self->state, "ACTIVE");
    } else if (strcmp(self->state, "ACTIVE") == 0 && strcmp(event, "DISCONNECT") == 0) {
        strcpy(self->state, "DISCONNECTED");
    } else if (strcmp(self->state, "DISCONNECTED") == 0 && strcmp(event, "ERROR") == 0) {
        strcpy(self->state, "ERROR");
    }
}

typedef struct {
    const char *events[4];
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    self->events[0] = "CONNECT";
    self->events[1] = "DATA";
    self->events[2] = "DISCONNECT";
    self->events[3] = "ERROR";
}

const char *EventGenerator_generate(EventGenerator *self) {
    while (1) {
        for (int i = 0; i < 4; i++) {
            yield self->events[i];
        }
    }
}

typedef struct {
    ConnectionState connection;
    EventGenerator events;
} NetworkAnalyzer;

void NetworkAnalyzer_init(NetworkAnalyzer *self) {
    ConnectionState_init(&self->connection);
    EventGenerator_init(&self->events);
}

void NetworkAnalyzer_analyze(NetworkAnalyzer *self) {
    while (1) {
        const char *event = EventGenerator_generate(&self->events);
        ConnectionState_transition(&self->connection, event);
        if (strcmp(self->connection.state, "ERROR") == 0) {
            printf("Error encountered, resetting state.\n");
            strcpy(self->connection.state, "DISCONNECTED");
        }
    }
}

int main() {
    NetworkAnalyzer analyzer;
    NetworkAnalyzer_init(&analyzer);
    NetworkAnalyzer_analyze(&analyzer);
    return 0;
}