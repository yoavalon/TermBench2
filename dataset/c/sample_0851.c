#include <stdio.h>
#include <string.h>

typedef struct {
    char status[10];
} Connection;

void Connection_init(Connection *self, const char *status) {
    strcpy(self->status, status);
}

void Connection_change_status(Connection *self, const char *new_status) {
    strcpy(self->status, new_status);
}

typedef struct {
    char current_state[10];
} StateMachine;

void StateMachine_init(StateMachine *self, const char *initial_state) {
    strcpy(self->current_state, initial_state);
}

void StateMachine_transition(StateMachine *self, const char *event) {
    if (strcmp(self->current_state, "disconnected") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->current_state, "connected");
    } else if (strcmp(self->current_state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->current_state, "disconnected");
    }
}

void process_event(StateMachine *state_machine, const char *event, Connection *connection) {
    if (strcmp(event, "connect") == 0) {
        Connection_change_status(connection, "active");
    } else if (strcmp(event, "disconnect") == 0) {
        Connection_change_status(connection, "inactive");
    }
    StateMachine_transition(state_machine, event);
}

void simulate_network_activity(StateMachine *state_machine, Connection *connection, const char *events[], int event_count) {
    if (event_count == 0) {
        return;
    }
    process_event(state_machine, events[0], connection);
    simulate_network_activity(state_machine, connection, events + 1, event_count - 1);
}

int main() {
    Connection connection;
    StateMachine state_machine;
    const char *events[] = {"connect", "disconnect", "connect", "disconnect", "connect"};
    int event_count = sizeof(events) / sizeof(events[0]);

    Connection_init(&connection, "inactive");
    StateMachine_init(&state_machine, "disconnected");

    simulate_network_activity(&state_machine, &connection, events, event_count);

    return 0;
}