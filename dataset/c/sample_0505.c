#include <stdio.h>
#include <string.h>

typedef enum {
    DISCONNECTED,
    CONNECTED,
    DATA_RECEIVED,
    ACKNOWLEDGED
} ConnectionStateEnum;

typedef struct {
    ConnectionStateEnum state;
} ConnectionState;

typedef struct {
    ConnectionStateEnum current_event;
    int event_index;
} EventGenerator;

void ConnectionState_init(ConnectionState* self) {
    self->state = DISCONNECTED;
}

void ConnectionState_transition(ConnectionState* self, const char* event) {
    if (self->state == DISCONNECTED && strcmp(event, "CONNECT") == 0) {
        self->state = CONNECTED;
    } else if (self->state == CONNECTED && strcmp(event, "DATA") == 0) {
        self->state = DATA_RECEIVED;
    } else if (self->state == DATA_RECEIVED && strcmp(event, "ACKNOWLEDGE") == 0) {
        self->state = ACKNOWLEDGED;
    } else if (self->state == ACKNOWLEDGED && strcmp(event, "DISCONNECT") == 0) {
        self->state = DISCONNECTED;
    }
}

const char* EventGenerator_generate_events(EventGenerator* self) {
    static const char* events[] = {"CONNECT", "DATA", "ACKNOWLEDGE", "DISCONNECT"};
    self->current_event = (ConnectionStateEnum)self->event_index;
    self->event_index = (self->event_index + 1) % 4;
    return events[self->current_event];
}

typedef struct {
    ConnectionState connection;
    EventGenerator event_gen;
} NetworkAnalyzer;

void NetworkAnalyzer_init(NetworkAnalyzer* self) {
    ConnectionState_init(&self->connection);
    self->event_gen.event_index = 0;
}

void NetworkAnalyzer_analyze(NetworkAnalyzer* self) {
    while (1) {
        const char* event = EventGenerator_generate_events(&self->event_gen);
        ConnectionState_transition(&self->connection, event);
        printf("Current state: %d\n", self->connection.state);
    }
}

int main() {
    NetworkAnalyzer analyzer;
    NetworkAnalyzer_init(&analyzer);
    NetworkAnalyzer_analyze(&analyzer);
    return 0;
}