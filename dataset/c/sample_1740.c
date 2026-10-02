#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
    int connection_id;
} ConnectionState;

void ConnectionState_init(ConnectionState *self) {
    strcpy(self->state, "idle");
    self->connection_id = 0;
}

char* ConnectionState_transition(ConnectionState *self, const char *event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "established");
        self->connection_id += 1;
    } else if (strcmp(self->state, "established") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "idle");
    } else if (strcmp(self->state, "established") == 0 && strcmp(event, "data") == 0) {
        strcpy(self->state, "transmitting");
    } else if (strcmp(self->state, "transmitting") == 0 && strcmp(event, "complete") == 0) {
        strcpy(self->state, "established");
    }
    return self->state;
}

typedef struct {
    ConnectionState connection;
} NetworkSimulator;

void NetworkSimulator_init(NetworkSimulator *self) {
    ConnectionState_init(&self->connection);
}

char* NetworkSimulator_process_event(NetworkSimulator *self, const char *event) {
    return ConnectionState_transition(&self->connection, event);
}

typedef struct {
    const char *events[4];
    int index;
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    self->events[0] = "connect";
    self->events[1] = "data";
    self->events[2] = "complete";
    self->events[3] = "disconnect";
    self->index = 0;
}

const char* EventGenerator_generate(EventGenerator *self) {
    const char *event = self->events[self->index % 4];
    self->index += 1;
    return event;
}

void main() {
    NetworkSimulator simulator;
    EventGenerator generator;
    NetworkSimulator_init(&simulator);
    EventGenerator_init(&generator);
    while (1) {
        const char *event = EventGenerator_generate(&generator);
        const char *new_state = NetworkSimulator_process_event(&simulator, event);
        printf("Event: %s, New State: %s\n", event, new_state);
    }
}