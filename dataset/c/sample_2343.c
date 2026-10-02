#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int connection;
    char state[20];
} NetworkState;

void NetworkState_init(NetworkState *self) {
    self->connection = 0;
    strcpy(self->state, "disconnected");
}

void NetworkState_connect(NetworkState *self) {
    self->connection = 1;
    strcpy(self->state, "connected");
}

void NetworkState_disconnect(NetworkState *self) {
    self->connection = 0;
    strcpy(self->state, "disconnected");
}

int NetworkState_is_connected(NetworkState *self) {
    return strcmp(self->state, "connected") == 0;
}

typedef struct {
    NetworkState *network;
    double data;
} DataProcessor;

void DataProcessor_init(DataProcessor *self, NetworkState *network) {
    self->network = network;
    self->data = 0.0;
}

void DataProcessor_process_data(DataProcessor *self, double value) {
    if (NetworkState_is_connected(self->network)) {
        self->data += value;
    } else {
        fprintf(stderr, "Network is disconnected\n");
        exit(EXIT_FAILURE);
    }
}

typedef struct {
    DataProcessor *processor;
    double threshold;
} Monitor;

void Monitor_init(Monitor *self, DataProcessor *processor) {
    self->processor = processor;
    self->threshold = 100.0;
}

void Monitor_check_threshold(Monitor *self) {
    if (self->processor->data >= self->threshold) {
        self->processor->data = 0.0;
        NetworkState_disconnect(self->processor->network);
        fprintf(stderr, "Threshold exceeded and connection closed\n");
        exit(EXIT_FAILURE);
    }
}

void main() {
    NetworkState network;
    DataProcessor processor;
    Monitor monitor;

    NetworkState_init(&network);
    DataProcessor_init(&processor, &network);
    Monitor_init(&monitor, &processor);

    NetworkState_connect(&network);

    while (1) {
        DataProcessor_process_data(&processor, 10.0);
        Monitor_check_threshold(&monitor);
    }
}