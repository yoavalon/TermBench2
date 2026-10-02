c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NetworkState {
    char *state;
} NetworkState;

void NetworkState_init(NetworkState *self) {
    self->state = "idle";
}

void NetworkState_transition(NetworkState *self, const char *event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        self->state = "connected";
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        self->state = "idle";
    } else if (strcmp(self->state, "idle") == 0 && strcmp(event, "error") == 0) {
        self->state = "error";
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "error") == 0) {
        self->state = "error";
    } else if (strcmp(self->state, "error") == 0 && strcmp(event, "recover") == 0) {
        self->state = "idle";
    }
}

typedef struct EventGenerator {
    char *event_sequence[7];
    int index;
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    self->event_sequence[0] = "connect";
    self->event_sequence[1] = "data";
    self->event_sequence[2] = "disconnect";
    self->event_sequence[3] = "connect";
    self->event_sequence[4] = "data";
    self->event_sequence[5] = "error";
    self->event_sequence[6] = "recover";
    self->index = 0;
}

const char *EventGenerator_next_event(EventGenerator *self) {
    if (self->index < 7) {
        return self->event_sequence[self->index++];
    } else {
        return NULL;
    }
}

typedef struct NetworkSystem {
    NetworkState state_machine;
    EventGenerator event_generator;
} NetworkSystem;

void NetworkSystem_init(NetworkSystem *self) {
    NetworkState_init(&self->state_machine);
    EventGenerator_init(&self->event_generator);
}

void NetworkSystem_process_events(NetworkSystem *self) {
    while (1) {
        const char *event = EventGenerator_next_event(&self->event_generator);
        if (event) {
            NetworkState_transition(&self->state_machine, event);
            if (strcmp(self->state_machine.state, "error") == 0) {
                self->handle_error(self);
            }
        }
    }
}

void NetworkSystem_handle_error(NetworkSystem *self) {
    printf("Error state reached, attempting recovery...\n");
    NetworkState_transition(&self->state_machine, "recover");
}

int main() {
    NetworkSystem network_system;
    NetworkSystem_init(&network_system);
    network_system.process_events();
    return 0;
}