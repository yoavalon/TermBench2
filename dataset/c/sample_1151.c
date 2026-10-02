#include <stdio.h>
#include <string.h>

typedef struct {
    char status[16];
} ConnectionState;

void ConnectionState_init(ConnectionState *self, const char *status) {
    strcpy(self->status, status);
}

const char* ConnectionState_connect(ConnectionState *self) {
    if (strcmp(self->status, "disconnected") == 0) {
        strcpy(self->status, "connected");
        return "Connection established";
    }
    return "Already connected";
}

const char* ConnectionState_disconnect(ConnectionState *self) {
    if (strcmp(self->status, "connected") == 0) {
        strcpy(self->status, "disconnected");
        return "Connection terminated";
    }
    return "Already disconnected";
}

const char* ConnectionState_toggle(ConnectionState *self) {
    if (strcmp(self->status, "connected") == 0) {
        strcpy(self->status, "disconnected");
    } else {
        strcpy(self->status, "connected");
    }
    return self->status;
}

typedef struct {
    ConnectionState state;
} NetworkHandler;

void NetworkHandler_init(NetworkHandler *self) {
    ConnectionState_init(&self->state, "disconnected");
}

void NetworkHandler_manage_connection(NetworkHandler *self) {
    while (1) {
        const char* action = NetworkHandler_decide_action(self);
        if (strcmp(action, "connect") == 0) {
            printf("%s\n", ConnectionState_connect(&self->state));
        } else if (strcmp(action, "disconnect") == 0) {
            printf("%s\n", ConnectionState_disconnect(&self->state));
        } else if (strcmp(action, "toggle") == 0) {
            printf("Status toggled to %s\n", ConnectionState_toggle(&self->state));
        } else {
            break;
        }
    }
}

const char* NetworkHandler_decide_action(NetworkHandler *self) {
    if (strcmp(self->state.status, "connected") == 0) {
        return "disconnect";
    } else {
        return "connect";
    }
}

int main() {
    NetworkHandler handler;
    NetworkHandler_init(&handler);
    NetworkHandler_manage_connection(&handler);
    return 0;
}