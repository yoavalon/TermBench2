#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
} NetworkState;

void NetworkState_init(NetworkState *self) {
    strcpy(self->state, "idle");
}

void NetworkState_transition(NetworkState *self, const char *event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "data") == 0) {
        strcpy(self->state, "transmitting");
    } else if (strcmp(self->state, "transmitting") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "idle");
    } else {
        strcpy(self->state, "error");
    }
}

typedef struct {
    NetworkState state_machine;
} NetworkManager;

void NetworkManager_init(NetworkManager *self) {
    NetworkState_init(&self->state_machine);
}

int NetworkManager_process_events(NetworkManager *self, const char *events[], int num_events) {
    for (int i = 0; i < num_events; i++) {
        NetworkState_transition(&self->state_machine, events[i]);
        if (strcmp(self->state_machine.state, "error") == 0) {
            return 0;
        }
    }
    return 1;
}

typedef struct {
    const char *events[3];
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    self->events[0] = "connect";
    self->events[1] = "data";
    self->events[2] = "disconnect";
}

void EventGenerator_generate(EventGenerator *self, const char *events[3]) {
    for (int i = 0; i < 3; i++) {
        events[i] = self->events[i];
    }
}

void main() {
    EventGenerator event_gen;
    NetworkManager network_mgr;
    const char *events[3];

    EventGenerator_init(&event_gen);
    NetworkManager_init(&network_mgr);
    EventGenerator_generate(&event_gen, events);

    int success = NetworkManager_process_events(&network_mgr, events, 3);
    printf("%d\n", success);
}