#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct State State;
typedef struct StateMachine StateMachine;
typedef struct EventGenerator EventGenerator;

struct State {
    char* name;
    State* next_state_map[6]; // Assuming max 6 events for simplicity
};

struct StateMachine {
    State* states[3];
    State* current_state;
};

struct EventGenerator {
    char* events[5];
    int index;
};

void StateMachine_init(StateMachine* sm, State* states[], int size) {
    for (int i = 0; i < size; i++) {
        sm->states[i] = states[i];
    }
    sm->current_state = states[0];
}

State* State_next_state(State* state, char* event) {
    for (int i = 0; i < 6; i++) {
        if (strcmp(state->next_state_map[i]->name, event) == 0) {
            return state->next_state_map[i];
        }
    }
    return state;
}

void EventGenerator_init(EventGenerator* eg, char* events[], int size) {
    for (int i = 0; i < size; i++) {
        eg->events[i] = events[i];
    }
    eg->index = 0;
}

char* EventGenerator_next_event(EventGenerator* eg) {
    char* event = eg->events[eg->index % 5];
    eg->index += 1;
    return event;
}

void StateMachine_transition(StateMachine* sm, char* event) {
    State* new_state = State_next_state(sm->current_state, event);
    for (int i = 0; i < 3; i++) {
        if (sm->states[i] == new_state) {
            sm->current_state = new_state;
            break;
        }
    }
}

int main() {
    State state1 = {"CONNECTING", {NULL, NULL, NULL, NULL, NULL, NULL}};
    State state2 = {"CONNECTED", {NULL, NULL, NULL, NULL, NULL, NULL}};
    State state3 = {"DISCONNECTED", {NULL, NULL, NULL, NULL, NULL, NULL}};

    state1.next_state_map[0] = &state2;
    state1.next_state_map[1] = &state3;
    state2.next_state_map[0] = &state3;
    state2.next_state_map[1] = &state1;
    state3.next_state_map[0] = &state1;

    State* states[] = {&state1, &state2, &state3};
    StateMachine sm;
    StateMachine_init(&sm, states, 3);

    char* events[] = {"OK", "LOSE", "RETRY", "KEEP", "FAIL"};
    EventGenerator eg;
    EventGenerator_init(&eg, events, 5);

    while (1) {
        char* event = EventGenerator_next_event(&eg);
        StateMachine_transition(&sm, event);
    }

    return 0;
}