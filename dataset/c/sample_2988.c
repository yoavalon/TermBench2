#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char state[10];
    int sequence[100];
    int seq_index;
} NetworkState;

void NetworkState_init(NetworkState *self) {
    strcpy(self->state, "idle");
    self->seq_index = 0;
}

void NetworkState_transition(NetworkState *self, const char *action) {
    if (strcmp(self->state, "idle") == 0 && strcmp(action, "connect") == 0) {
        strcpy(self->state, "active");
        self->sequence[self->seq_index++] = 1;
    } else if (strcmp(self->state, "active") == 0 && strcmp(action, "data") == 0) {
        self->sequence[self->seq_index++] = 2;
    } else if (strcmp(self->state, "active") == 0 && strcmp(action, "disconnect") == 0) {
        strcpy(self->state, "idle");
        self->sequence[self->seq_index++] = 3;
    } else if (strcmp(self->state, "idle") == 0 && strcmp(action, "reset") == 0) {
        self->sequence[self->seq_index++] = 4;
    } else {
        self->sequence[self->seq_index++] = 0;
    }
}

void NetworkState_get_sequence(NetworkState *self, int *sequence, int *length) {
    for (int i = 0; i < self->seq_index; i++) {
        sequence[i] = self->sequence[i];
    }
    *length = self->seq_index;
}

const char* generate_actions(int *index) {
    static const char *actions[] = {"connect", "data", "disconnect", "reset"};
    *index = (*index + 1) % 4;
    return actions[*index];
}

int main() {
    NetworkState network;
    NetworkState_init(&network);
    int action_index = -1;
    while (1) {
        const char *action = generate_actions(&action_index);
        NetworkState_transition(&network, action);
        int sequence[100];
        int length;
        NetworkState_get_sequence(&network, sequence, &length);
        for (int i = 0; i < length; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
    }
    return 0;
}