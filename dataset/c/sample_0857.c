#include <stdio.h>
#include <string.h>

typedef struct {
    const char* state;
} ConnectionState;

ConnectionState* ConnectionState_new(const char* state) {
    ConnectionState* self = (ConnectionState*)malloc(sizeof(ConnectionState));
    self->state = state;
    return self;
}

ConnectionState* ConnectionState_transition(ConnectionState* self, const char* event) {
    if (strcmp(self->state, "disconnected") == 0) {
        if (strcmp(event, "connect") == 0) {
            return ConnectionState_new("connected");
        } else {
            return self;
        }
    } else if (strcmp(self->state, "connected") == 0) {
        if (strcmp(event, "disconnect") == 0) {
            return ConnectionState_new("disconnected");
        } else if (strcmp(event, "send") == 0) {
            return ConnectionState_new("sending");
        } else {
            return self;
        }
    } else if (strcmp(self->state, "sending") == 0) {
        if (strcmp(event, "receive") == 0) {
            return ConnectionState_new("receiving");
        } else if (strcmp(event, "complete") == 0) {
            return ConnectionState_new("connected");
        } else {
            return self;
        }
    } else if (strcmp(self->state, "receiving") == 0) {
        if (strcmp(event, "complete") == 0) {
            return ConnectionState_new("connected");
        } else {
            return self;
        }
    }
    return self;
}

ConnectionState* process_events(ConnectionState* state, const char* events[], int size) {
    if (size == 0) {
        return state;
    } else {
        ConnectionState* next_state = ConnectionState_transition(state, events[0]);
        ConnectionState* final_state = process_events(next_state, events + 1, size - 1);
        free(state);
        return final_state;
    }
}

int main() {
    ConnectionState* initial_state = ConnectionState_new("disconnected");
    const char* event_sequence[] = {"connect", "send", "receive", "complete", "disconnect"};
    ConnectionState* final_state = process_events(initial_state, event_sequence, 5);
    printf("%s\n", final_state->state);
    free(final_state);
    return 0;
}