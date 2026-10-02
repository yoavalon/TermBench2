#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char* state;
} NetworkConnection;

NetworkConnection* NetworkConnection_init() {
    NetworkConnection* conn = (NetworkConnection*)malloc(sizeof(NetworkConnection));
    conn->state = "disconnected";
    return conn;
}

bool NetworkConnection_connect(NetworkConnection* conn) {
    if (strcmp(conn->state, "disconnected") == 0) {
        conn->state = "connected";
        return true;
    }
    return false;
}

bool NetworkConnection_disconnect(NetworkConnection* conn) {
    if (strcmp(conn->state, "connected") == 0) {
        conn->state = "disconnected";
        return true;
    }
    return false;
}

bool NetworkConnection_is_connected(NetworkConnection* conn) {
    return strcmp(conn->state, "connected") == 0;
}

void monitor_connection(NetworkConnection* conn) {
    while (true) {
        if (NetworkConnection_is_connected(conn)) {
            printf("Connection is active.\n");
        } else {
            printf("No active connection.\n");
            NetworkConnection_connect(conn);
        }
    }
}

int main() {
    NetworkConnection* conn = NetworkConnection_init();
    monitor_connection(conn);
    return 0;
}