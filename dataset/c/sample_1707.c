#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
    char states[4][20];
} ConnectionState;

void ConnectionState_init(ConnectionState *self) {
    strcpy(self->state, "DISCONNECTED");
    strcpy(self->states[0], "DISCONNECTED");
    strcpy(self->states[1], "CONNECTING");
    strcpy(self->states[2], "CONNECTED");
    strcpy(self->states[3], "DISCONNECTING");
}

void ConnectionState_transition(ConnectionState *self, const char *event) {
    if (strcmp(self->state, "DISCONNECTED") == 0 && strcmp(event, "CONNECT") == 0) {
        strcpy(self->state, "CONNECTING");
    } else if (strcmp(self->state, "CONNECTING") == 0) {
        strcpy(self->state, "CONNECTED");
    } else if (strcmp(self->state, "CONNECTED") == 0 && strcmp(event, "DISCONNECT") == 0) {
        strcpy(self->state, "DISCONNECTING");
    } else if (strcmp(self->state, "DISCONNECTING") == 0) {
        strcpy(self->state, "DISCONNECTED");
    }
}

const char* ConnectionState_current_state(ConnectionState *self) {
    return self->state;
}

typedef struct {
    char events[2][20];
    int index;
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    strcpy(self->events[0], "CONNECT");
    strcpy(self->events[1], "DISCONNECT");
    self->index = 0;
}

const char* EventGenerator_next_event(EventGenerator *self) {
    const char *event = self->events[self->index];
    self->index = (self->index + 1) % 2;
    return event;
}

typedef struct {
    ConnectionState state_machine;
    EventGenerator event_generator;
} NetworkSimulator;

void NetworkSimulator_init(NetworkSimulator *self) {
    ConnectionState_init(&self->state_machine);
    EventGenerator_init(&self->event_generator);
}

void NetworkSimulator_simulate(NetworkSimulator *self) {
    while (1) {
        const char *event = EventGenerator_next_event(&self->event_generator);
        ConnectionState_transition(&self->state_machine, event);
        printf("%s\n", ConnectionState_current_state(&self->state_machine));
    }
}

int main() {
    NetworkSimulator simulator;
    NetworkSimulator_init(&simulator);
    NetworkSimulator_simulate(&simulator);
    return 0;
}