#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    IDLE,
    CONNECTED
} State;

typedef struct {
    State state;
    void* connection;
} StateMachine;

typedef struct {
    // Connection structure can be expanded as needed
} Connection;

void send_data(Connection* connection) {
    printf("Sending data...\n");
}

void receive_data(Connection* connection) {
    printf("Receiving data...\n");
}

void handle_input(StateMachine* machine, const char* data) {
    if (machine->state == IDLE && strcmp(data, "connect") == 0) {
        machine->state = CONNECTED;
        machine->connection = malloc(sizeof(Connection));
    } else if (machine->state == CONNECTED && strcmp(data, "disconnect") == 0) {
        machine->state = IDLE;
        free(machine->connection);
        machine->connection = NULL;
    } else if (machine->state == CONNECTED && strcmp(data, "send") == 0) {
        send_data((Connection*)machine->connection);
    } else if (machine->state == CONNECTED && strcmp(data, "receive") == 0) {
        receive_data((Connection*)machine->connection);
    }
}

void process_data(const char* (*data_stream)()) {
    StateMachine machine = {IDLE, NULL};
    while (1) {
        const char* data = data_stream();
        handle_input(&machine, data);
    }
}

const char* generate_data_stream() {
    static const char* actions[] = {"connect", "disconnect", "send", "receive"};
    return actions[rand() % 4];
}

int main() {
    srand(time(NULL));
    process_data(generate_data_stream);
    return 0;
}