#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char state[20];
    char** data;
    int data_count;
} NetworkStateMachine;

void NetworkStateMachine_init(NetworkStateMachine* self) {
    strcpy(self->state, "disconnected");
    self->data = NULL;
    self->data_count = 0;
}

void transition(NetworkStateMachine* self, const char* event) {
    if (strcmp(self->state, "disconnected") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "send") == 0) {
        self->data = realloc(self->data, (self->data_count + 1) * sizeof(char*));
        self->data[self->data_count] = strdup("data");
        self->data_count++;
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "disconnected");
        for (int i = 0; i < self->data_count; i++) {
            free(self->data[i]);
        }
        free(self->data);
        self->data = NULL;
        self->data_count = 0;
    }
}

void process_events(NetworkStateMachine* self, const char** events, int count) {
    for (int i = 0; i < count; i++) {
        transition(self, events[i]);
    }
}

void get_status(NetworkStateMachine* self, char* state, char*** data, int* data_count) {
    strcpy(state, self->state);
    *data = self->data;
    *data_count = self->data_count;
}

const char** generate_events(int count) {
    const char* events[] = {"connect", "send", "disconnect"};
    const char** generated_events = malloc(count * sizeof(const char*));
    for (int i = 0; i < count; i++) {
        double random_value = (double)rand() / RAND_MAX;
        if (random_value < 0.3) {
            generated_events[i] = "connect";
        } else if (random_value < 0.5) {
            generated_events[i] = "send";
        } else {
            generated_events[i] = "disconnect";
        }
    }
    return generated_events;
}

int main() {
    NetworkStateMachine state_machine;
    NetworkStateMachine_init(&state_machine);
    const char** events = generate_events(100);
    process_events(&state_machine, events, 100);
    char final_state[20];
    char** final_data;
    int final_data_count;
    get_status(&state_machine, final_state, &final_data, &final_data_count);
    printf("%s ", final_state);
    for (int i = 0; i < final_data_count; i++) {
        printf("%s ", final_data[i]);
    }
    printf("\n");
    free(events);
    for (int i = 0; i < final_data_count; i++) {
        free(final_data[i]);
    }
    free(final_data);
    return 0;
}