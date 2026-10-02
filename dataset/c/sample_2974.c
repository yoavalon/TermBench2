#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
    int sequence[100];
    int counter;
    int seq_index;
} NetworkStateMachine;

void NetworkStateMachine_init(NetworkStateMachine *self) {
    strcpy(self->state, "idle");
    self->counter = 0;
    self->seq_index = 0;
}

void NetworkStateMachine_transition(NetworkStateMachine *self, const char *event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
        self->sequence[self->seq_index++] = 1;
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "data") == 0) {
        strcpy(self->state, "processing");
        self->sequence[self->seq_index++] = 2;
    } else if (strcmp(self->state, "processing") == 0 && strcmp(event, "complete") == 0) {
        strcpy(self->state, "idle");
        self->sequence[self->seq_index++] = 3;
        self->counter++;
    } else if (strcmp(self->state, "idle") == 0 && strcmp(event, "error") == 0) {
        strcpy(self->state, "error");
        self->sequence[self->seq_index++] = 4;
    } else if (strcmp(self->state, "error") == 0 && strcmp(event, "reset") == 0) {
        strcpy(self->state, "idle");
        self->sequence[self->seq_index++] = 5;
        self->counter = 0;
    } else {
        self->sequence[self->seq_index++] = 0;
    }
}

void NetworkStateMachine_get_sequence(NetworkStateMachine *self, int *sequence) {
    for (int i = 0; i < self->seq_index; i++) {
        sequence[i] = self->sequence[i];
    }
}

int NetworkStateMachine_get_counter(NetworkStateMachine *self) {
    return self->counter;
}

const char *generate_events(int *index) {
    static const char *events[] = {"connect", "data", "complete", "connect", "data", "complete", "error", "reset", "connect", "data", "complete"};
    int len = sizeof(events) / sizeof(events[0]);
    int idx = *index % len;
    *index = idx + 1;
    return events[idx];
}

int main() {
    NetworkStateMachine state_machine;
    NetworkStateMachine_init(&state_machine);
    int event_index = 0;
    while (1) {
        const char *event = generate_events(&event_index);
        NetworkStateMachine_transition(&state_machine, event);
    }
    return 0;
}