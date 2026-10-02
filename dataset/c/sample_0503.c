#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NetworkState {
    char* current_state;
} NetworkState;

void NetworkState_init(NetworkState* self) {
    self->current_state = "idle";
}

void NetworkState_transition(NetworkState* self, const char* event) {
    if (strcmp(self->current_state, "idle") == 0 && strcmp(event, "connect") == 0) {
        self->current_state = "connected";
    } else if (strcmp(self->current_state, "connected") == 0 && strcmp(event, "data") == 0) {
        self->current_state = "transmitting";
    } else if (strcmp(self->current_state, "transmitting") == 0 && strcmp(event, "disconnect") == 0) {
        self->current_state = "idle";
    } else if (strcmp(self->current_state, "idle") == 0 && strcmp(event, "error") == 0) {
        self->current_state = "error_state";
    } else if (strcmp(self->current_state, "error_state") == 0 && strcmp(event, "recover") == 0) {
        self->current_state = "idle";
    }
}

void NetworkState_process_events(NetworkState* self, const char* events[], int count) {
    for (int i = 0; i < count; i++) {
        NetworkState_transition(self, events[i]);
    }
}

typedef struct NetworkController {
    NetworkState state_machine;
    const char** events;
    int event_count;
} NetworkController;

void NetworkController_init(NetworkController* self) {
    NetworkState_init(&self->state_machine);
    self->events = NULL;
    self->event_count = 0;
}

void NetworkController_add_event(NetworkController* self, const char* event) {
    self->event_count++;
    self->events = realloc(self->events, sizeof(const char*) * self->event_count);
    self->events[self->event_count - 1] = event;
}

void NetworkController_run(NetworkController* self) {
    while (1) {
        NetworkState_process_events(&self->state_machine, self->events, self->event_count);
    }
}

int main() {
    NetworkController controller;
    NetworkController_init(&controller);
    NetworkController_add_event(&controller, "connect");
    NetworkController_add_event(&controller, "data");
    NetworkController_add_event(&controller, "disconnect");
    NetworkController_add_event(&controller, "connect");
    NetworkController_add_event(&controller, "data");
    NetworkController_add_event(&controller, "error");
    NetworkController_add_event(&controller, "recover");
    NetworkController_run(&controller);
    return 0;
}