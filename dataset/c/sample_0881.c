#include <stdio.h>
#include <string.h>

typedef enum {
    DISCONNECTED,
    CONNECTING,
    CONNECTED,
    DISCONNECTING
} ConnectionState;

typedef struct {
    ConnectionState state;
} Connection;

void ConnectionState_init(Connection* conn) {
    conn->state = DISCONNECTED;
}

const char* Connection_connect(Connection* conn) {
    if (conn->state == DISCONNECTED) {
        conn->state = CONNECTING;
        return Connection_connecting(conn);
    }
    return "already connected";
}

const char* Connection_connecting(Connection* conn) {
    if (conn->state == CONNECTING) {
        conn->state = CONNECTED;
        return Connection_connected(conn);
    }
    return "connection failed";
}

const char* Connection_connected(Connection* conn) {
    if (conn->state == CONNECTED) {
        conn->state = DISCONNECTING;
        return Connection_disconnecting(conn);
    }
    return "connection lost";
}

const char* Connection_disconnecting(Connection* conn) {
    if (conn->state == DISCONNECTING) {
        conn->state = DISCONNECTED;
        return "disconnected";
    }
    return "disconnection failed";
}

const char** simulate_connections() {
    static const char* results[5];
    Connection conn;
    ConnectionState_init(&conn);
    const char* states[] = {"connect", "connect", "disconnect", "connect", "disconnect"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(states[i], "connect") == 0) {
            results[i] = Connection_connect(&conn);
        } else if (strcmp(states[i], "disconnect") == 0) {
            results[i] = Connection_disconnecting(&conn);
        }
    }
    return results;
}

void main() {
    const char** results = simulate_connections();
    for (int i = 0; i < 5; i++) {
        printf("%s\n", results[i]);
    }
}