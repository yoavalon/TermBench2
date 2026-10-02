#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
} StateMachine;

void StateMachine_init(StateMachine *machine) {
    strcpy(machine->state, "closed");
}

char* StateMachine_transition(StateMachine *machine, const char *event) {
    if (strcmp(machine->state, "closed") == 0 && strcmp(event, "connect") == 0) {
        strcpy(machine->state, "open");
    } else if (strcmp(machine->state, "open") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(machine->state, "closed");
    }
    return machine->state;
}

void simulate_network() {
    StateMachine machine;
    StateMachine_init(&machine);
    while (1) {
        const char *event = strcmp(machine.state, "closed") == 0 ? "connect" : "disconnect";
        const char *new_state = StateMachine_transition(&machine, event);
        printf("Event: %s, New State: %s\n", event, new_state);
    }
}

int main() {
    simulate_network();
    return 0;
}