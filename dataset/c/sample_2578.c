#include <stdio.h>

typedef struct {
    int state;
    int sequence[10];
} NetworkStateMachine;

void NetworkStateMachine_init(NetworkStateMachine *self) {
    self->state = 0;
    self->sequence[0] = 0; self->sequence[1] = 1; self->sequence[2] = 1;
    self->sequence[3] = 2; self->sequence[4] = 3; self->sequence[5] = 5;
    self->sequence[6] = 8; self->sequence[7] = 13; self->sequence[8] = 21;
    self->sequence[9] = 34;
}

void NetworkStateMachine_transition(NetworkStateMachine *self, int data) {
    if (data < 0) {
        self->state = 1;
    } else if (data > 0) {
        self->state = 2;
    } else {
        self->state = 0;
    }
}

int NetworkStateMachine_process(NetworkStateMachine *self, int data) {
    NetworkStateMachine_transition(self, data);
    return self->sequence[self->state];
}

int main() {
    NetworkStateMachine machine;
    NetworkStateMachine_init(&machine);
    int result = NetworkStateMachine_process(&machine, -5);
    printf("%d\n", result);
    return 0;
}