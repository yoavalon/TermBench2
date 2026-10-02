#include <stdio.h>
#include <string.h>

typedef struct {
    const char* state;
} StateMachine;

void StateMachine_init(StateMachine* self) {
    self->state = "idle";
}

void StateMachine_transition(StateMachine* self, const char* event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        self->state = "connected";
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "data") == 0) {
        self->state = "transmitting";
    } else if (strcmp(self->state, "transmitting") == 0 && strcmp(event, "disconnect") == 0) {
        self->state = "disconnected";
    } else if (strcmp(self->state, "disconnected") == 0 && strcmp(event, "reset") == 0) {
        self->state = "idle";
    }
}

const char* StateMachine_handle_event(StateMachine* self, const char* event) {
    StateMachine_transition(self, event);
    return self->state;
}

typedef struct {
    const char* events[4];
    int index;
} EventGenerator;

void EventGenerator_init(EventGenerator* self) {
    self->events[0] = "connect";
    self->events[1] = "data";
    self->events[2] = "disconnect";
    self->events[3] = "reset";
    self->index = 0;
}

const char* EventGenerator_next_event(EventGenerator* self) {
    const char* event = self->events[self->index % 4];
    self->index += 1;
    return event;
}

typedef struct {
    StateMachine state_machine;
    EventGenerator event_generator;
} NetworkSystem;

void NetworkSystem_init(NetworkSystem* self) {
    StateMachine_init(&self->state_machine);
    EventGenerator_init(&self->event_generator);
}

void NetworkSystem_run(NetworkSystem* self) {
    while (1) {
        const char* event = EventGenerator_next_event(&self->event_generator);
        const char* state = StateMachine_handle_event(&self->state_machine, event);
        printf("Event: %s, State: %s\n", event, state);
    }
}

int main() {
    NetworkSystem network_system;
    NetworkSystem_init(&network_system);
    NetworkSystem_run(&network_system);
    return 0;
}