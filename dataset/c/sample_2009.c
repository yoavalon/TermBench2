#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
    char data_buffer[100][20];
    int buffer_index;
} ConnectionState;

void ConnectionState_init(ConnectionState *self) {
    strcpy(self->state, "DISCONNECTED");
    self->buffer_index = 0;
}

char* ConnectionState_transition(ConnectionState *self, char *event) {
    if (strcmp(self->state, "DISCONNECTED") == 0 && strcmp(event, "CONNECT") == 0) {
        strcpy(self->state, "CONNECTED");
    } else if (strcmp(self->state, "CONNECTED") == 0 && strcmp(event, "SEND") == 0) {
        strcpy(self->state, "SENDING");
    } else if (strcmp(self->state, "SENDING") == 0 && strcmp(event, "ACKNOWLEDGE") == 0) {
        strcpy(self->state, "ACKNOWLEDGED");
    } else if (strcmp(self->state, "ACKNOWLEDGED") == 0 && strcmp(event, "DISCONNECT") == 0) {
        strcpy(self->state, "DISCONNECTED");
    } else if (strcmp(self->state, "CONNECTED") == 0 && strcmp(event, "DATA") == 0) {
        strcpy(self->data_buffer[self->buffer_index++], event);
    } else if (strcmp(self->state, "SENDING") == 0 && strcmp(event, "REJECT") == 0) {
        strcpy(self->state, "REJECTED");
    } else if (strcmp(self->state, "REJECTED") == 0 && strcmp(event, "RETRY") == 0) {
        strcpy(self->state, "SENDING");
    }
    return self->state;
}

typedef struct {
    ConnectionState connection;
} NetworkHandler;

void NetworkHandler_init(NetworkHandler *self) {
    ConnectionState_init(&self->connection);
}

char* NetworkHandler_process_event(NetworkHandler *self, char *event) {
    return ConnectionState_transition(&self->connection, event);
}

typedef struct {
    char events[5][20];
} EventSimulator;

void EventSimulator_init(EventSimulator *self) {
    strcpy(self->events[0], "CONNECT");
    strcpy(self->events[1], "DATA");
    strcpy(self->events[2], "SEND");
    strcpy(self->events[3], "ACKNOWLEDGE");
    strcpy(self->events[4], "DISCONNECT");
}

char* EventSimulator_generate_events(EventSimulator *self) {
    return self->events[0];
}

void main() {
    NetworkHandler handler;
    EventSimulator simulator;
    NetworkHandler_init(&handler);
    EventSimulator_init(&simulator);
    for (int i = 0; i < 5; i++) {
        char* event = EventSimulator_generate_events(&simulator) + i * 20;
        char* state = NetworkHandler_process_event(&handler, event);
        printf("Event: %s, New State: %s\n", event, state);
    }
}