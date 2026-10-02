#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NetworkConnection {
    char* state;
} NetworkConnection;

void NetworkConnection_init(NetworkConnection* self, char* state) {
    self->state = state;
}

void NetworkConnection_transition(NetworkConnection* self, char* event) {
    if (strcmp(self->state, "disconnected") == 0 && strcmp(event, "connect") == 0) {
        self->state = "connected";
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        self->state = "disconnected";
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "error") == 0) {
        self->state = "error";
    } else if (strcmp(self->state, "error") == 0 && strcmp(event, "recover") == 0) {
        self->state = "connected";
    }
}

typedef struct EventGenerator {
    char* events[4];
} EventGenerator;

void EventGenerator_init(EventGenerator* self) {
    self->events[0] = "connect";
    self->events[1] = "disconnect";
    self->events[2] = "error";
    self->events[3] = "recover";
}

char* EventGenerator_generate(EventGenerator* self) {
    return self->events[rand() % 4];
}

typedef struct StateSimulator {
    NetworkConnection connection;
    EventGenerator generator;
} StateSimulator;

void StateSimulator_init(StateSimulator* self) {
    NetworkConnection_init(&self->connection, "disconnected");
    EventGenerator_init(&self->generator);
}

void StateSimulator_simulate(StateSimulator* self) {
    while (1) {
        char* event = EventGenerator_generate(&self->generator);
        NetworkConnection_transition(&self->connection, event);
        printf("Event: %s, State: %s\n", event, self->connection.state);
    }
}

int main() {
    srand(time(NULL));
    StateSimulator simulator;
    StateSimulator_init(&simulator);
    StateSimulator_simulate(&simulator);
    return 0;
}