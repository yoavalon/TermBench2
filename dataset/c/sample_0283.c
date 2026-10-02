#include <stdio.h>
#include <string.h>

typedef struct {
    char **states;
    int num_states;
    char ***transitions;
    int num_transitions;
    char *current_state;
} NetworkStateMachine;

typedef struct {
    char **events;
    int num_events;
    int index;
} EventManager;

void NetworkStateMachine_init(NetworkStateMachine *self, char **states, int num_states, char ***transitions, int num_transitions) {
    self->states = states;
    self->num_states = num_states;
    self->transitions = transitions;
    self->num_transitions = num_transitions;
    self->current_state = states[0];
}

void NetworkStateMachine_transition(NetworkStateMachine *self, char *event) {
    for (int i = 0; i < self->num_transitions; i++) {
        if (strcmp(self->transitions[i][0], self->current_state) == 0 && strcmp(self->transitions[i][1], event) == 0) {
            self->current_state = self->transitions[i][2];
            return;
        }
    }
    fprintf(stderr, "Invalid transition\n");
    exit(1);
}

int NetworkStateMachine_is_terminal(NetworkStateMachine *self) {
    return strcmp(self->current_state, "disconnected") == 0 || strcmp(self->current_state, "error") == 0;
}

void EventManager_init(EventManager *self, char **events, int num_events) {
    self->events = events;
    self->num_events = num_events;
    self->index = 0;
}

char *EventManager_get_next_event(EventManager *self) {
    if (self->index < self->num_events) {
        char *event = self->events[self->index];
        self->index++;
        return event;
    } else {
        return NULL;
    }
}

int main() {
    char *states[] = {"idle", "connected", "disconnected", "error"};
    int num_states = sizeof(states) / sizeof(states[0]);

    char *transitions_data[][3] = {
        {"idle", "connect", "connected"},
        {"connected", "disconnect", "disconnected"},
        {"connected", "error", "error"},
        {"disconnected", "connect", "connected"},
        {"error", "reset", "idle"}
    };
    char **transitions[] = {
        transitions_data[0],
        transitions_data[1],
        transitions_data[2],
        transitions_data[3],
        transitions_data[4]
    };
    int num_transitions = sizeof(transitions) / sizeof(transitions[0]);

    char *events[] = {"connect", "disconnect", "error", "reset", "connect", "disconnect", "connect", "error", "reset"};
    int num_events = sizeof(events) / sizeof(events[0]);

    NetworkStateMachine network_machine;
    NetworkStateMachine_init(&network_machine, states, num_states, transitions, num_transitions);

    EventManager event_manager;
    EventManager_init(&event_manager, events, num_events);

    while (1) {
        char *event = EventManager_get_next_event(&event_manager);
        if (event == NULL || NetworkStateMachine_is_terminal(&network_machine)) {
            break;
        }
        NetworkStateMachine_transition(&network_machine, event);
    }

    printf("Final state: %s\n", network_machine.current_state);
    return 0;
}