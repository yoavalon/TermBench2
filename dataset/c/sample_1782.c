#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* state;
    int connection_attempts;
} NetworkState;

void NetworkState_init(NetworkState* self) {
    self->state = "disconnected";
    self->connection_attempts = 0;
}

void NetworkState_transition(NetworkState* self, const char* event) {
    if (strcmp(self->state, "disconnected") == 0 && strcmp(event, "connect") == 0) {
        self->state = "connecting";
    } else if (strcmp(self->state, "connecting") == 0) {
        if (strcmp(event, "success") == 0) {
            self->state = "connected";
            self->connection_attempts = 0;
        } else if (strcmp(event, "failure") == 0) {
            self->connection_attempts++;
            if (self->connection_attempts < 5) {
                self->state = "connecting";
            } else {
                self->state = "disconnected";
            }
        }
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        self->state = "disconnected";
    }
}

typedef struct {
} EventGenerator;

const char* EventGenerator_generate(EventGenerator* self) {
    if (rand() % 2 == 0) {
        return "connect";
    } else {
        return "disconnect";
    }
}

typedef struct {
    NetworkState network;
    EventGenerator generator;
} ConnectionHandler;

void ConnectionHandler_init(ConnectionHandler* self) {
    NetworkState_init(&self->network);
}

void ConnectionHandler_run(ConnectionHandler* self) {
    while (1) {
        const char* event = EventGenerator_generate(&self->generator);
        NetworkState_transition(&self->network, event);
        if (strcmp(self->network.state, "connected") == 0) {
            printf("Connected\n");
        } else if (strcmp(self->network.state, "disconnected") == 0) {
            printf("Disconnected\n");
        }
    }
}

void main() {
    ConnectionHandler handler;
    ConnectionHandler_init(&handler);
    ConnectionHandler_run(&handler);
}