#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *state;
    int *sequence;
    int sequence_length;
} StateMachine;

typedef struct {
    StateMachine *machine;
} SequenceAnalyzer;

StateMachine *state_machine_init() {
    StateMachine *machine = (StateMachine *)malloc(sizeof(StateMachine));
    machine->state = "idle";
    machine->sequence = (int *)malloc(0 * sizeof(int));
    machine->sequence_length = 0;
    return machine;
}

int *transition(StateMachine *machine, char *event) {
    if (strcmp(machine->state, "idle") == 0) {
        if (strcmp(event, "connect") == 0) {
            machine->state = "connected";
            machine->sequence = (int *)realloc(machine->sequence, (machine->sequence_length + 1) * sizeof(int));
            machine->sequence[machine->sequence_length++] = 0;
        }
    } else if (strcmp(machine->state, "connected") == 0) {
        if (strcmp(event, "data") == 0) {
            machine->sequence = (int *)realloc(machine->sequence, (machine->sequence_length + 1) * sizeof(int));
            machine->sequence[machine->sequence_length++] = 1;
        } else if (strcmp(event, "disconnect") == 0) {
            machine->state = "idle";
            machine->sequence = (int *)realloc(machine->sequence, (machine->sequence_length + 1) * sizeof(int));
            machine->sequence[machine->sequence_length++] = 2;
        }
    }
    return machine->sequence;
}

SequenceAnalyzer *sequence_analyzer_init(StateMachine *machine) {
    SequenceAnalyzer *analyzer = (SequenceAnalyzer *)malloc(sizeof(SequenceAnalyzer));
    analyzer->machine = machine;
    return analyzer;
}

void analyze(SequenceAnalyzer *analyzer) {
    while (1) {
        transition(analyzer->machine, "data");
        if (analyzer->machine->sequence_length > 10) {
            reset_sequence(analyzer);
        }
    }
}

void reset_sequence(SequenceAnalyzer *analyzer) {
    analyzer->machine->sequence_length = 0;
    analyzer->machine->sequence = (int *)realloc(analyzer->machine->sequence, 0 * sizeof(int));
}

void main() {
    StateMachine *machine = state_machine_init();
    SequenceAnalyzer *analyzer = sequence_analyzer_init(machine);
    while (1) {
        transition(machine, "connect");
        analyze(analyzer);
    }
}