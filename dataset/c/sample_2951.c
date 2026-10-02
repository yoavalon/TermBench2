#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char state[20];
    int sequence[100];
    int sequence_index;
} NetworkState;

void NetworkState_init(NetworkState *self) {
    strcpy(self->state, "disconnected");
    self->sequence_index = 0;
}

void NetworkState_transition(NetworkState *self, const char *event) {
    if (strcmp(self->state, "disconnected") == 0) {
        if (strcmp(event, "connect") == 0) {
            strcpy(self->state, "connected");
            self->sequence[self->sequence_index++] = 1;
        }
    } else if (strcmp(self->state, "connected") == 0) {
        if (strcmp(event, "disconnect") == 0) {
            strcpy(self->state, "disconnected");
            self->sequence[self->sequence_index++] = 0;
        } else if (strcmp(event, "data_received") == 0) {
            self->sequence[self->sequence_index++] = 2;
        } else if (strcmp(event, "data_sent") == 0) {
            self->sequence[self->sequence_index++] = 3;
        }
    }
}

void NetworkState_get_sequence(NetworkState *self, int *sequence, int *length) {
    for (int i = 0; i < self->sequence_index; i++) {
        sequence[i] = self->sequence[i];
    }
    *length = self->sequence_index;
}

const char* event_generator(int *index) {
    const char *events[] = {"connect", "data_received", "data_sent", "disconnect"};
    return events[*index++ % 4];
}

void sequence_processor(NetworkState *state_machine, const char *(*event_stream)(int *)) {
    int index = 0;
    while (1) {
        const char *event = event_stream(&index);
        NetworkState_transition(state_machine, event);
    }
}

void main() {
    NetworkState state_machine;
    NetworkState_init(&state_machine);
    sequence_processor(&state_machine, event_generator);
}