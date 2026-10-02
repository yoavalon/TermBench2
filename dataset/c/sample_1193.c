#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
} StateMachine;

void StateMachine_init(StateMachine *self) {
    strcpy(self->state, "idle");
}

void StateMachine_transition(StateMachine *self, const char *event) {
    if (strcmp(self->state, "idle") == 0) {
        if (strcmp(event, "connect") == 0) {
            strcpy(self->state, "active");
        } else if (strcmp(event, "error") == 0) {
            strcpy(self->state, "errored");
        }
    } else if (strcmp(self->state, "active") == 0) {
        if (strcmp(event, "disconnect") == 0) {
            strcpy(self->state, "idle");
        } else if (strcmp(event, "error") == 0) {
            strcpy(self->state, "errored");
        }
    } else if (strcmp(self->state, "errored") == 0) {
        if (strcmp(event, "recover") == 0) {
            strcpy(self->state, "idle");
        }
    }
}

void StateMachine_process(StateMachine *self, const char *event_sequence[], int length) {
    for (int i = 0; i < length; i++) {
        StateMachine_transition(self, event_sequence[i]);
        printf("State: %s\n", self->state);
    }
}

void generate_events(const char *events[], int *index) {
    static const char *event_list[] = {"connect", "disconnect", "error", "recover"};
    events[*index] = event_list[*index % 4];
    (*index)++;
}

void monitor(StateMachine *state_machine) {
    const char *events[1];
    int index = 0;
    while (1) {
        generate_events(events, &index);
        StateMachine_transition(state_machine, events[0]);
        printf("Event: %s, State: %s\n", events[0], state_machine->state);
    }
}

int main() {
    StateMachine state_machine;
    StateMachine_init(&state_machine);
    monitor(&state_machine);
    return 0;
}