#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    IDLE,
    ACTIVE,
    DISCONNECTED
} ConnectionState;

typedef struct {
    ConnectionState state;
} ConnectionState_t;

void ConnectionState_init(ConnectionState_t *self) {
    self->state = IDLE;
}

void ConnectionState_transition(ConnectionState_t *self, const char *event) {
    if (self->state == IDLE) {
        if (strcmp(event, "connect") == 0) {
            self->state = ACTIVE;
        }
    } else if (self->state == ACTIVE) {
        if (strcmp(event, "disconnect") == 0) {
            self->state = IDLE;
        }
    } else if (self->state == DISCONNECTED) {
        if (strcmp(event, "retry") == 0) {
            self->state = ACTIVE;
        }
    }
}

typedef struct {
    ConnectionState_t connection;
    char **events;
    size_t event_count;
    size_t event_capacity;
} NetworkManager;

void NetworkManager_init(NetworkManager *self) {
    ConnectionState_init(&self->connection);
    self->events = NULL;
    self->event_count = 0;
    self->event_capacity = 0;
}

void NetworkManager_add_event(NetworkManager *self, const char *event) {
    if (self->event_count >= self->event_capacity) {
        self->event_capacity = self->event_capacity == 0 ? 1 : self->event_capacity * 2;
        self->events = realloc(self->events, self->event_capacity * sizeof(char *));
    }
    self->events[self->event_count++] = strdup(event);
}

void NetworkManager_process_events(NetworkManager *self) {
    while (self->event_count > 0) {
        char *event = self->events[0];
        for (size_t i = 1; i < self->event_count; i++) {
            self->events[i - 1] = self->events[i];
        }
        self->event_count--;
        ConnectionState_transition(&self->connection, event);
        free(event);
    }
}

typedef struct {
    const char *states[3];
    size_t index;
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    self->states[0] = "connect";
    self->states[1] = "disconnect";
    self->states[2] = "retry";
    self->index = 0;
}

const char *EventGenerator_generate_event(EventGenerator *self) {
    const char *event = self->states[self->index];
    self->index = (self->index + 1) % 3;
    return event;
}

int main() {
    NetworkManager manager;
    NetworkManager_init(&manager);
    EventGenerator generator;
    EventGenerator_init(&generator);
    while (1) {
        const char *event = EventGenerator_generate_event(&generator);
        NetworkManager_add_event(&manager, event);
        NetworkManager_process_events(&manager);
    }
    return 0;
}