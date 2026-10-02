#include <stdio.h>
#include <string.h>

typedef struct {
    char* state;
    char* (*states[3])(char*);
} StateMachine;

char* idle(StateMachine* machine, char* event) {
    if (strcmp(event, "connect") == 0) {
        return "connected";
    } else if (strcmp(event, "error") == 0) {
        return "error";
    }
    return "idle";
}

char* connected(StateMachine* machine, char* event) {
    if (strcmp(event, "disconnect") == 0) {
        return "idle";
    } else if (strcmp(event, "error") == 0) {
        return "error";
    }
    return "connected";
}

char* error(StateMachine* machine, char* event) {
    if (strcmp(event, "recover") == 0) {
        return "idle";
    }
    return "error";
}

void transition(StateMachine* machine, char* event) {
    if (strcmp(machine->state, "idle") == 0) {
        machine->state = machine->states[0](machine, event);
    } else if (strcmp(machine->state, "connected") == 0) {
        machine->state = machine->states[1](machine, event);
    } else if (strcmp(machine->state, "error") == 0) {
        machine->state = machine->states[2](machine, event);
    }
}

void simulate_events(StateMachine* machine) {
    char* events[] = {"connect", "data", "disconnect", "connect", "error", "recover"};
    for (int i = 0; i < 6; i++) {
        transition(machine, events[i]);
    }
}

void main() {
    StateMachine machine;
    machine.state = "idle";
    machine.states[0] = (char* (*)(StateMachine*, char*))idle;
    machine.states[1] = (char* (*)(StateMachine*, char*))connected;
    machine.states[2] = (char* (*)(StateMachine*, char*))error;

    simulate_events(&machine);
}