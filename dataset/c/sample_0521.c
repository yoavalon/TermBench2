#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char state[20];
    char events[100][20];
    int event_count;
} NetworkStateMachine;

void NetworkStateMachine_init(NetworkStateMachine *self) {
    strcpy(self->state, "disconnected");
    self->event_count = 0;
}

void NetworkStateMachine_transition(NetworkStateMachine *self, const char *event) {
    if (strcmp(self->state, "disconnected") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
        strcpy(self->events[self->event_count++], event);
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "disconnected");
        strcpy(self->events[self->event_count++], event);
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "data") == 0) {
        strcpy(self->state, "processing");
        strcpy(self->events[self->event_count++], event);
    } else if (strcmp(self->state, "processing") == 0 && strcmp(event, "complete") == 0) {
        strcpy(self->state, "connected");
        strcpy(self->events[self->event_count++], event);
    } else {
        strcpy(self->events[self->event_count++], "invalid");
    }
}

const char* NetworkStateMachine_get_state(NetworkStateMachine *self) {
    return self->state;
}

const char** NetworkStateMachine_get_events(NetworkStateMachine *self, int *count) {
    *count = self->event_count;
    return (const char**)self->events;
}

typedef struct {
    const char *events[4];
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    self->events[0] = "connect";
    self->events[1] = "data";
    self->events[2] = "complete";
    self->events[3] = "disconnect";
}

const char* EventGenerator_generate(EventGenerator *self) {
    int index = rand() % 4;
    return self->events[index];
}

typedef struct {
    NetworkStateMachine *state_machine;
    EventGenerator *event_generator;
} SystemMonitor;

void SystemMonitor_init(SystemMonitor *self, NetworkStateMachine *state_machine, EventGenerator *event_generator) {
    self->state_machine = state_machine;
    self->event_generator = event_generator;
}

void SystemMonitor_run(SystemMonitor *self) {
    while (1) {
        const char *event = EventGenerator_generate(self->event_generator);
        NetworkStateMachine_transition(self->state_machine, event);
    }
}

int main() {
    srand(time(NULL));
    NetworkStateMachine state_machine;
    EventGenerator event_generator;
    SystemMonitor monitor;

    NetworkStateMachine_init(&state_machine);
    EventGenerator_init(&event_generator);
    SystemMonitor_init(&monitor, &state_machine, &event_generator);

    SystemMonitor_run(&monitor);
    return 0;
}