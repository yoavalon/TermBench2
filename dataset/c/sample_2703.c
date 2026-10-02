#include <stdio.h>

typedef struct {
    int state;
} NetworkStateMachine;

void NetworkStateMachine_init(NetworkStateMachine* self) {
    self->state = 0;
}

void NetworkStateMachine_process(NetworkStateMachine* self) {
    while (1) {
        if (self->state == 0) {
            self->state = 1;
        } else if (self->state == 1) {
            self->state = 0;
        }
    }
}

int main() {
    NetworkStateMachine machine;
    NetworkStateMachine_init(&machine);
    NetworkStateMachine_process(&machine);
    return 0;
}