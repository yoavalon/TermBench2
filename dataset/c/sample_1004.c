#include <stdio.h>
#include <string.h>

typedef struct {
    char* state;
} NetworkStateMachine;

NetworkStateMachine* NetworkStateMachine_init(char* state) {
    NetworkStateMachine* self = (NetworkStateMachine*)malloc(sizeof(NetworkStateMachine));
    self->state = (char*)malloc(strlen(state) + 1);
    strcpy(self->state, state);
    return self;
}

NetworkStateMachine* NetworkStateMachine_transition(NetworkStateMachine* self) {
    if (strcmp(self->state, "CONNECTING") == 0) {
        strcpy(self->state, "ESTABLISHED");
    } else if (strcmp(self->state, "ESTABLISHED") == 0) {
        strcpy(self->state, "DISCONNECTING");
    } else if (strcmp(self->state, "DISCONNECTING") == 0) {
        strcpy(self->state, "CONNECTING");
    }
    return self;
}

void recursive_process(NetworkStateMachine* state_machine) {
    printf("%s\n", state_machine->state);
    NetworkStateMachine_transition(state_machine);
    recursive_process(state_machine);
}

int main() {
    char* initial_state = "CONNECTING";
    NetworkStateMachine* state_machine = NetworkStateMachine_init(initial_state);
    recursive_process(state_machine);
    return 0;
}