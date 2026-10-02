#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool connection;
    double data;
    double threshold;
} NetworkState;

void NetworkState_init(NetworkState *self) {
    self->connection = false;
    self->data = 0.0;
    self->threshold = 0.5;
}

void NetworkState_connect(NetworkState *self) {
    self->connection = true;
    self->data = 0.1;
}

void NetworkState_disconnect(NetworkState *self) {
    self->connection = false;
    self->data = 0.0;
}

void NetworkState_transmit(NetworkState *self) {
    if (self->connection) {
        self->data += 0.01;
        if (self->data >= self->threshold) {
            NetworkState_disconnect(self);
        }
    }
}

typedef struct {
    NetworkState state;
} NetworkMonitor;

void NetworkMonitor_init(NetworkMonitor *self) {
    NetworkState_init(&self->state);
}

void NetworkMonitor_observe(NetworkMonitor *self) {
    if (!self->state.connection) {
        NetworkState_connect(&self->state);
    } else {
        NetworkState_transmit(&self->state);
    }
}

typedef struct {
    NetworkMonitor *monitor;
} NetworkAnalyzer;

void NetworkAnalyzer_init(NetworkAnalyzer *self, NetworkMonitor *monitor) {
    self->monitor = monitor;
}

void NetworkAnalyzer_analyze(NetworkAnalyzer *self) {
    while (true) {
        NetworkMonitor_observe(self->monitor);
    }
}

int main() {
    NetworkMonitor monitor;
    NetworkAnalyzer analyzer;
    NetworkMonitor_init(&monitor);
    NetworkAnalyzer_init(&analyzer, &monitor);
    NetworkAnalyzer_analyze(&analyzer);
    return 0;
}