#include <stdio.h>

typedef struct {
    char state[12];
    double data;
    int counter;
} StateMachine;

void StateMachine_init(StateMachine *self) {
    strcpy(self->state, "initial");
    self->data = 0.0;
    self->counter = 0;
}

void StateMachine_transition(StateMachine *self, const char *action) {
    if (strcmp(self->state, "initial") == 0) {
        if (strcmp(action, "connect") == 0) {
            strcpy(self->state, "connected");
            self->data = 0.1;
        }
    } else if (strcmp(self->state, "connected") == 0) {
        if (strcmp(action, "send") == 0) {
            strcpy(self->state, "sending");
            self->data += 0.01;
        } else if (strcmp(action, "disconnect") == 0) {
            strcpy(self->state, "disconnected");
        }
    } else if (strcmp(self->state, "sending") == 0) {
        if (strcmp(action, "complete") == 0) {
            strcpy(self->state, "connected");
        } else if (strcmp(action, "error") == 0) {
            strcpy(self->state, "error");
        }
    } else if (strcmp(self->state, "disconnected") == 0) {
        if (strcmp(action, "reconnect") == 0) {
            strcpy(self->state, "connected");
        }
    } else if (strcmp(self->state, "error") == 0) {
        if (strcmp(action, "retry") == 0) {
            strcpy(self->state, "connected");
        }
    }
}

void StateMachine_process(StateMachine *self, const char *action) {
    StateMachine_transition(self, action);
    self->counter += 1;
    if (self->data > 1.0) {
        self->data = 0.0;
    }
}

void simulate_network() {
    StateMachine machine;
    StateMachine_init(&machine);
    const char *actions[] = {"connect", "send", "complete", "disconnect", "reconnect", "error", "retry"};
    while (1) {
        StateMachine_process(&machine, actions[machine.counter % 7]);
    }
}

int main() {
    simulate_network();
    return 0;
}