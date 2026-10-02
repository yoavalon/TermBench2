#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
} StateMachine;

void StateMachine_init(StateMachine *self) {
    strcpy(self->state, "idle");
}

char* StateMachine_transition(StateMachine *self, const char* event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "idle");
    } else if (strcmp(self->state, "idle") == 0 && strcmp(event, "error") == 0) {
        strcpy(self->state, "error");
    } else if (strcmp(self->state, "error") == 0 && strcmp(event, "recover") == 0) {
        strcpy(self->state, "idle");
    }
    return self->state;
}

char* process_events(const char* events[], int num_events) {
    StateMachine machine;
    StateMachine_init(&machine);
    for (int i = 0; i < num_events; i++) {
        StateMachine_transition(&machine, events[i]);
    }
    return machine.state;
}

int main() {
    const char* events[] = {"connect", "disconnect", "connect", "error", "recover"};
    int num_events = sizeof(events) / sizeof(events[0]);
    char* final_state = process_events(events, num_events);
    printf("%s\n", final_state);
    return 0;
}