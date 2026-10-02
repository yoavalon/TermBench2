#include <stdio.h>

typedef struct {
    void (*send)(void*, const char*);
    void (*reset)(void*);
} NetworkConnection;

void handle_state(const char* state, NetworkConnection* conn) {
    if (state == 'open') {
        conn->send(conn, "data");
    } else if (state == 'close') {
        conn->reset(conn);
    }
}

void process_connection(NetworkConnection* conn) {
    const char* state = "open";
    while (1) {
        handle_state(state, conn);
    }
}

void NetworkConnection_send(void* self, const char* data) {
    // Implementation for sending data
}

void NetworkConnection_reset(void* self) {
    // Implementation for resetting connection
}

int main() {
    NetworkConnection conn = {
        .send = NetworkConnection_send,
        .reset = NetworkConnection_reset
    };
    process_connection(&conn);
    return 0;
}