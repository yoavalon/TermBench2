#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const char *state;
    const char *event;
    const char *next_state;
} Transition;

typedef struct {
    const char **states;
    Transition *transitions;
    int num_transitions;
    const char *current_state;
    const char **sequence;
    int sequence_size;
} StateMachine;

typedef struct {
    StateMachine *state_machine;
} NetworkConnection;

void state_machine_init(StateMachine *sm, const char **states, Transition *transitions, int num_transitions, const char *start_state) {
    sm->states = states;
    sm->transitions = transitions;
    sm->num_transitions = num_transitions;
    sm->current_state = start_state;
    sm->sequence = (const char **)malloc(10 * sizeof(const char *));
    sm->sequence_size = 0;
}

void state_machine_transition(StateMachine *sm, const char *event) {
    for (int i = 0; i < sm->num_transitions; i++) {
        if (strcmp(sm->transitions[i].state, sm->current_state) == 0 && strcmp(sm->transitions[i].event, event) == 0) {
            sm->current_state = sm->transitions[i].next_state;
            sm->sequence[sm->sequence_size++] = event;
            return;
        }
    }
    fprintf(stderr, "Invalid transition\n");
    exit(EXIT_FAILURE);
}

int state_machine_is_terminated(StateMachine *sm) {
    const char *terminal_states[] = {"disconnected", NULL};
    for (int i = 0; terminal_states[i] != NULL; i++) {
        if (strcmp(sm->current_state, terminal_states[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void network_connection_init(NetworkConnection *nc, StateMachine *state_machine) {
    nc->state_machine = state_machine;
}

void network_connection_process_events(NetworkConnection *nc, const char **events, int num_events) {
    for (int i = 0; i < num_events; i++) {
        state_machine_transition(nc->state_machine, events[i]);
        if (state_machine_is_terminated(nc->state_machine)) {
            break;
        }
    }
}

int main() {
    const char *states[] = {"initial", "connected", "sending", "receiving", "disconnected", NULL};
    Transition transitions[] = {
        {"initial", "connect", "connected"},
        {"connected", "send", "sending"},
        {"connected", "receive", "receiving"},
        {"connected", "disconnect", "disconnected"},
        {"sending", "connect", "connected"},
        {"sending", "disconnect", "disconnected"},
        {"receiving", "connect", "connected"},
        {"receiving", "disconnect", "disconnected"}
    };
    const char *start_state = "initial";
    StateMachine state_machine;
    NetworkConnection network_connection;

    state_machine_init(&state_machine, states, transitions, 8, start_state);
    network_connection_init(&network_connection, &state_machine);

    const char *events[] = {"connect", "send", "receive", "disconnect"};
    network_connection_process_events(&network_connection, events, 4);

    printf("Sequence: ");
    for (int i = 0; i < state_machine.sequence_size; i++) {
        printf("%s ", state_machine.sequence[i]);
    }
    printf("\n");

    printf("Terminated: %d\n", state_machine_is_terminated(&state_machine));

    free(state_machine.sequence);

    return 0;
}