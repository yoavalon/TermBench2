#include <stdio.h>

typedef struct {
    int state;
} StateMachine;

void StateMachine_init(StateMachine *sm) {
    sm->state = 0;
}

void StateMachine_transition(StateMachine *sm) {
    if (sm->state == 0) {
        sm->state = 1;
    } else if (sm->state == 1) {
        sm->state = 2;
    } else if (sm->state == 2) {
        sm->state = 0;
    }
}

int main() {
    StateMachine sm;
    StateMachine_init(&sm);
    while (1) {
        StateMachine_transition(&sm);
        printf("%d\n", sm.state);
    }
    return 0;
}