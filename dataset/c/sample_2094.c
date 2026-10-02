#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NetworkConnection {
    char* state;
    double precision;
} NetworkConnection;

void NetworkConnection_init(NetworkConnection* self, const char* state, double precision) {
    self->state = strdup(state);
    self->precision = precision;
}

void NetworkConnection_transition(NetworkConnection* self, const char* event) {
    if (strcmp(self->state, "closed") == 0 && strcmp(event, "connect") == 0) {
        free(self->state);
        self->state = strdup("open");
    } else if (strcmp(self->state, "open") == 0 && strcmp(event, "data") == 0) {
        free(self->state);
        self->state = strdup("transmitting");
    } else if (strcmp(self->state, "transmitting") == 0 && strcmp(event, "disconnect") == 0) {
        free(self->state);
        self->state = strdup("closing");
    } else if (strcmp(self->state, "closing") == 0 && strcmp(event, "acknowledge") == 0) {
        free(self->state);
        self->state = strdup("closed");
    }
}

const char* NetworkConnection_get_state(NetworkConnection* self) {
    return self->state;
}

typedef struct NetworkAnalyzer {
    NetworkConnection** connections;
    int connection_count;
} NetworkAnalyzer;

void NetworkAnalyzer_init(NetworkAnalyzer* self, NetworkConnection** connections, int connection_count) {
    self->connections = connections;
    self->connection_count = connection_count;
}

const char** NetworkAnalyzer_analyze(NetworkAnalyzer* self) {
    const char** states = (const char**)malloc(self->connection_count * sizeof(const char*));
    for (int i = 0; i < self->connection_count; i++) {
        states[i] = NetworkConnection_get_state(self->connections[i]);
    }
    return states;
}

typedef struct EventGenerator {
    const char** events;
    int event_count;
} EventGenerator;

void EventGenerator_init(EventGenerator* self, const char** events, int event_count) {
    self->events = events;
    self->event_count = event_count;
}

const char** EventGenerator_generate(EventGenerator* self) {
    return self->events;
}

void main() {
    NetworkConnection conn1;
    NetworkConnection conn2;
    NetworkConnection_init(&conn1, "closed", 0.5);
    NetworkConnection_init(&conn2, "closed", 0.75);
    NetworkConnection* connections[] = {&conn1, &conn2};
    int connection_count = 2;

    const char* events[] = {"connect", "data", "disconnect", "acknowledge", "connect"};
    int event_count = 5;
    EventGenerator event_generator;
    EventGenerator_init(&event_generator, events, event_count);

    NetworkAnalyzer analyzer;
    NetworkAnalyzer_init(&analyzer, connections, connection_count);

    const char** generated_events = EventGenerator_generate(&event_generator);
    for (int i = 0; i < event_count; i++) {
        for (int j = 0; j < connection_count; j++) {
            NetworkConnection_transition(connections[j], generated_events[i]);
        }
    }

    const char** final_states = NetworkAnalyzer_analyze(&analyzer);
    for (int i = 0; i < connection_count; i++) {
        printf("%s ", final_states[i]);
    }
    printf("\n");

    // Clean up
    for (int i = 0; i < connection_count; i++) {
        free(connections[i]->state);
    }
    free(final_states);
}

int main() {
    main();
    return 0;
}