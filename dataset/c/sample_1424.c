#include <stdio.h>
#include <string.h>

typedef struct {
    char state[16];
} ConnectionState;

void ConnectionState_init(ConnectionState *self) {
    strcpy(self->state, "disconnected");
}

char* ConnectionState_connect(ConnectionState *self) {
    if (strcmp(self->state, "disconnected") == 0) {
        strcpy(self->state, "connected");
        return "Connection established";
    } else {
        return "Already connected";
    }
}

char* ConnectionState_disconnect(ConnectionState *self) {
    if (strcmp(self->state, "connected") == 0) {
        strcpy(self->state, "disconnected");
        return "Connection terminated";
    } else {
        return "Already disconnected";
    }
}

char* ConnectionState_toggle(ConnectionState *self) {
    if (strcmp(self->state, "disconnected") == 0) {
        return ConnectionState_connect(self);
    } else {
        return ConnectionState_disconnect(self);
    }
}

char** process_connections(ConnectionState *connections, char *actions[], int num_actions, int *num_results) {
    char **results = (char **)malloc(num_actions * sizeof(char *));
    for (int i = 0; i < num_actions; i++) {
        if (strcmp(actions[i], "toggle") == 0) {
            results[i] = ConnectionState_toggle(connections);
        } else if (strcmp(actions[i], "connect") == 0) {
            results[i] = ConnectionState_connect(connections);
        } else if (strcmp(actions[i], "disconnect") == 0) {
            results[i] = ConnectionState_disconnect(connections);
        }
    }
    *num_results = num_actions;
    return results;
}

void main() {
    ConnectionState connections;
    ConnectionState_init(&connections);
    char *actions[] = {"connect", "toggle", "disconnect", "toggle", "connect", "disconnect"};
    int num_actions = sizeof(actions) / sizeof(actions[0]);
    int num_results;
    char **results = process_connections(&connections, actions, num_actions, &num_results);
    for (int i = 0; i < num_results; i++) {
        printf("%s\n", results[i]);
    }
    free(results);
}