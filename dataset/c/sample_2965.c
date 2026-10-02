#include <stdio.h>
#include <stdlib.h>

typedef struct SequenceGenerator {
    int state;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int state) {
    self->state = state;
}

int SequenceGenerator_transition(SequenceGenerator *self, int current_state) {
    if (current_state % 2 == 0) {
        return current_state * 3 + 1;
    } else {
        return current_state / 2;
    }
}

int SequenceGenerator_generate(SequenceGenerator *self) {
    self->state = SequenceGenerator_transition(self, self->state);
    return self->state;
}

typedef struct NetworkConnectionSimulator {
    SequenceGenerator *sequence;
    int current_value;
} NetworkConnectionSimulator;

void NetworkConnectionSimulator_init(NetworkConnectionSimulator *self, SequenceGenerator *sequence) {
    self->sequence = sequence;
    self->current_value = SequenceGenerator_generate(self->sequence);
}

int NetworkConnectionSimulator_simulate(NetworkConnectionSimulator *self) {
    printf("%d\n", self->current_value);
    self->current_value = SequenceGenerator_generate(self->sequence);
    return self->current_value;
}

typedef struct ConnectionMonitor {
    NetworkConnectionSimulator *simulator;
} ConnectionMonitor;

void ConnectionMonitor_init(ConnectionMonitor *self, NetworkConnectionSimulator *simulator) {
    self->simulator = simulator;
}

void ConnectionMonitor_monitor(ConnectionMonitor *self) {
    while (1) {
        NetworkConnectionSimulator_simulate(self->simulator);
    }
}

int main() {
    int initial_state = 6;
    SequenceGenerator sequence_generator;
    SequenceGenerator_init(&sequence_generator, initial_state);

    NetworkConnectionSimulator network_simulator;
    NetworkConnectionSimulator_init(&network_simulator, &sequence_generator);

    ConnectionMonitor connection_monitor;
    ConnectionMonitor_init(&connection_monitor, &network_simulator);

    ConnectionMonitor_monitor(&connection_monitor);

    return 0;
}