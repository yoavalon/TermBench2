c
#include <stdio.h>
#include <string.h>

typedef struct {
    char *state;
} StateMachine;

StateMachine* StateMachine_init(char *state) {
    StateMachine *machine = (StateMachine *)malloc(sizeof(StateMachine));
    machine->state = state;
    return machine;
}

char* StateMachine_transition(StateMachine *machine, char *input_data) {
    if (strcmp(machine->state, "start") == 0) {
        if (strcmp(input_data, "data1") == 0) {
            machine->state = "state1";
        } else if (strcmp(input_data, "data2") == 0) {
            machine->state = "state2";
        }
    } else if (strcmp(machine->state, "state1") == 0) {
        if (strcmp(input_data, "data3") == 0) {
            machine->state = "end";
        } else {
            machine->state = "start";
        }
    } else if (strcmp(machine->state, "state2") == 0) {
        if (strcmp(input_data, "data4") == 0) {
            machine->state = "end";
        } else {
            machine->state = "start";
        }
    }
    return machine->state;
}

char* process_data(StateMachine *machine, char **data_list, int index) {
    if (index == 6) {
        return machine->state;
    }
    StateMachine_transition(machine, data_list[index]);
    return process_data(machine, data_list, index + 1);
}

int main() {
    char *initial_state = "start";
    StateMachine *state_machine = StateMachine_init(initial_state);
    char *data_sequence[] = {"data1", "data2", "data3", "data4", "data1", "data3"};
    char *final_state = process_data(state_machine, data_sequence, 0);
    printf("%s\n", final_state);
    free(state_machine);
    return 0;
}