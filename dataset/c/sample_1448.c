#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char state[10];
    char events[100][10];
    int event_count;
} StateMachine;

void StateMachine_init(StateMachine *sm) {
    strcpy(sm->state, "closed");
    sm->event_count = 0;
}

void StateMachine_transition(StateMachine *sm, const char *event) {
    if (strcmp(sm->state, "closed") == 0 && strcmp(event, "open") == 0) {
        strcpy(sm->state, "opened");
    } else if (strcmp(sm->state, "opened") == 0 && strcmp(event, "data") == 0) {
        strcpy(sm->state, "transmitting");
    } else if (strcmp(sm->state, "transmitting") == 0 && strcmp(event, "close") == 0) {
        strcpy(sm->state, "closing");
    } else if (strcmp(sm->state, "closing") == 0 && strcmp(event, "closed") == 0) {
        strcpy(sm->state, "closed");
    }
    strcpy(sm->events[sm->event_count++], event);
}

int StateMachine_is_terminal(StateMachine *sm) {
    return strcmp(sm->state, "closed") == 0 &&
           sm->event_count > 1 &&
           strcmp(sm->events[sm->event_count - 2], "close") == 0 &&
           strcmp(sm->events[sm->event_count - 1], "close") == 0;
}

typedef struct {
    StateMachine machine;
} Network;

void Network_init(Network *net) {
    StateMachine_init(&net->machine);
}

void Network_process_event(Network *net, const char *event) {
    StateMachine_transition(&net->machine, event);
}

int Network_check_termination(Network *net) {
    return StateMachine_is_terminal(&net->machine);
}

int main() {
    Network net;
    Network_init(&net);
    const char *events[] = {"open", "data", "data", "close", "close", "open", "data", "close"};
    for (int i = 0; i < 8; i++) {
        Network_process_event(&net, events[i]);
        if (Network_check_termination(&net)) {
            break;
        }
    }
    return 0;
}