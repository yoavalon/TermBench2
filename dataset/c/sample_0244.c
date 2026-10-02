#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} NetworkState;

void NetworkState_init(NetworkState *self) {
    strcpy(self->state, "init");
}

void NetworkState_transition(NetworkState *self, const char *event) {
    if (strcmp(self->state, "init") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "disconnected");
    } else if (strcmp(self->state, "disconnected") == 0 && strcmp(event, "reconnect") == 0) {
        strcpy(self->state, "connected");
    }
}

typedef struct {
    NetworkState *state_machine;
    char events[10][20];
    int event_count;
} EventProcessor;

void EventProcessor_init(EventProcessor *self, NetworkState *state_machine) {
    self->state_machine = state_machine;
    self->event_count = 0;
}

void EventProcessor_add_event(EventProcessor *self, const char *event) {
    strcpy(self->events[self->event_count], event);
    self->event_count++;
}

void EventProcessor_process_events(EventProcessor *self) {
    for (int i = 0; i < self->event_count; i++) {
        NetworkState_transition(self->state_machine, self->events[i]);
    }
    self->event_count = 0;
}

void main() {
    NetworkState state_machine;
    EventProcessor processor;
    NetworkState_init(&state_machine);
    EventProcessor_init(&processor, &state_machine);
    EventProcessor_add_event(&processor, "connect");
    EventProcessor_process_events(&processor);
    EventProcessor_add_event(&processor, "disconnect");
    EventProcessor_process_events(&processor);
    EventProcessor_add_event(&processor, "reconnect");
    EventProcessor_process_events(&processor);
    printf("%s\n", state_machine.state);
}