#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char state[10];
    bool connection;
} StateMachine;

void StateMachine_init(StateMachine *self) {
    strcpy(self->state, "idle");
    self->connection = false;
}

void StateMachine_transition(StateMachine *self, const char *event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
        self->connection = true;
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "idle");
        self->connection = false;
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "error") == 0) {
        strcpy(self->state, "error");
        self->connection = false;
    } else if (strcmp(self->state, "error") == 0 && strcmp(event, "recover") == 0) {
        strcpy(self->state, "connected");
        self->connection = true;
    }
}

void StateMachine_get_status(StateMachine *self, char *state, bool *connection) {
    strcpy(state, self->state);
    *connection = self->connection;
}

void simulate_events(const char *events[], int size) {
    StateMachine machine;
    StateMachine_init(&machine);
    char state[10];
    bool connection;
    for (int i = 0; i < size; i++) {
        StateMachine_transition(&machine, events[i]);
        StateMachine_get_status(&machine, state, &connection);
        printf("(%s, %s)\n", state, connection ? "True" : "False");
    }
}

int main() {
    const char *events_sequence[] = {"connect", "data", "disconnect", "connect", "error", "recover"};
    int size = sizeof(events_sequence) / sizeof(events_sequence[0]);
    simulate_events(events_sequence, size);
    return 0;
}