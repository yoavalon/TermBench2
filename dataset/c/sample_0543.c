#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *state;
    char *connection;
} StateMachine;

void StateMachine_init(StateMachine *self) {
    self->state = strdup("idle");
    self->connection = NULL;
}

void StateMachine_transition(StateMachine *self, const char *event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        free(self->state);
        self->state = strdup("connected");
        self->connection = strdup("active");
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        free(self->state);
        self->state = strdup("idle");
        free(self->connection);
        self->connection = NULL;
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "data") == 0) {
        StateMachine_process_data(self);
    } else if (strcmp(self->state, "idle") == 0 && strcmp(event, "data") == 0) {
        // do nothing
    }
}

void StateMachine_process_data(StateMachine *self) {
    printf("Processing data in state: %s\n", self->state);
}

typedef struct {
    char **events;
    int size;
    int index;
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    self->events = malloc(7 * sizeof(char *));
    self->events[0] = strdup("connect");
    self->events[1] = strdup("data");
    self->events[2] = strdup("disconnect");
    self->events[3] = strdup("data");
    self->events[4] = strdup("connect");
    self->events[5] = strdup("data");
    self->events[6] = strdup("disconnect");
    self->size = 7;
    self->index = 0;
}

const char *EventGenerator_generate(EventGenerator *self) {
    if (self->index < self->size) {
        return self->events[self->index++];
    } else {
        return "idle";
    }
}

typedef struct {
    StateMachine state_machine;
    EventGenerator event_generator;
} NetworkManager;

void NetworkManager_init(NetworkManager *self) {
    StateMachine_init(&self->state_machine);
    EventGenerator_init(&self->event_generator);
}

void NetworkManager_run(NetworkManager *self) {
    while (1) {
        const char *event = EventGenerator_generate(&self->event_generator);
        StateMachine_transition(&self->state_machine, event);
    }
}

int main() {
    NetworkManager network_manager;
    NetworkManager_init(&network_manager);
    NetworkManager_run(&network_manager);
    return 0;
}