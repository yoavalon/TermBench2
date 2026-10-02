#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
    int* values;
    int values_size;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator* self) {
    self->state = 0;
    self->values = (int*)malloc(0 * sizeof(int));
    self->values_size = 0;
}

void SequenceGenerator_generate_value(SequenceGenerator* self) {
    if (self->state % 2 == 0) {
        self->values = (int*)realloc(self->values, (self->values_size + 1) * sizeof(int));
        self->values[self->values_size] = self->state;
    } else {
        self->values = (int*)realloc(self->values, (self->values_size + 1) * sizeof(int));
        self->values[self->values_size] = self->state * 2;
    }
    self->values_size++;
    self->state++;
}

int* SequenceGenerator_get_values(SequenceGenerator* self) {
    return self->values;
}

typedef struct {
    SequenceGenerator* generator;
    char* connection_status;
} NetworkState;

void NetworkState_init(NetworkState* self, SequenceGenerator* generator) {
    self->generator = generator;
    self->connection_status = "open";
}

void NetworkState_simulate_connection(NetworkState* self) {
    if (strcmp(self->connection_status, "open") == 0) {
        SequenceGenerator_generate_value(self->generator);
        self->connection_status = "closed";
    } else {
        self->connection_status = "open";
    }
}

typedef struct {
    NetworkState* state;
} NetworkMonitor;

void NetworkMonitor_init(NetworkMonitor* self, NetworkState* state) {
    self->state = state;
}

void NetworkMonitor_monitor(NetworkMonitor* self) {
    while (1) {
        NetworkState_simulate_connection(self->state);
        int* values = SequenceGenerator_get_values(self->state->generator);
        printf("%d\n", values[self->state->generator->values_size - 1]);
    }
}

int main() {
    SequenceGenerator generator;
    SequenceGenerator_init(&generator);
    NetworkState state;
    NetworkState_init(&state, &generator);
    NetworkMonitor monitor;
    NetworkMonitor_init(&monitor, &state);
    NetworkMonitor_monitor(&monitor);
    return 0;
}