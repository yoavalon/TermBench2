#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
    char *connection;
} StateMachine;

void StateMachine_init(StateMachine *sm) {
    strcpy(sm->state, "idle");
    sm->connection = NULL;
}

void StateMachine_transition(StateMachine *sm, const char *event) {
    if (strcmp(sm->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        strcpy(sm->state, "connected");
        sm->connection = "active";
    } else if (strcmp(sm->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(sm->state, "idle");
        sm->connection = NULL;
    } else if (strcmp(sm->state, "connected") == 0 && strcmp(event, "data") == 0) {
        strcpy(sm->state, "processing");
    } else if (strcmp(sm->state, "processing") == 0 && strcmp(event, "complete") == 0) {
        strcpy(sm->state, "connected");
    }
}

typedef struct {
    StateMachine sm;
} Network;

void Network_init(Network *net) {
    StateMachine_init(&net->sm);
}

void Network_process_events(Network *net, const char *events[], int num_events) {
    for (int i = 0; i < num_events; i++) {
        StateMachine_transition(&net->sm, events[i]);
    }
}

typedef struct {
    Network network;
} Processor;

void Processor_init(Processor *proc) {
    Network_init(&proc->network);
}

void Processor_run(Processor *proc) {
    while (1) {
        const char *events[] = {"connect", "data", "complete", "disconnect"};
        Network_process_events(&proc->network, events, 4);
    }
}

int main() {
    Processor processor;
    Processor_init(&processor);
    Processor_run(&processor);
    return 0;
}