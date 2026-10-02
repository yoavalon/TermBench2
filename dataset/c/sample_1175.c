#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
} Connection;

void Connection_init(Connection *conn, const char *state) {
    strcpy(conn->state, state);
}

void Connection_transition(Connection *conn, const char *event) {
    if (strcmp(conn->state, "closed") == 0) {
        if (strcmp(event, "open") == 0) {
            strcpy(conn->state, "open");
        }
    } else if (strcmp(conn->state, "open") == 0) {
        if (strcmp(event, "data") == 0) {
            strcpy(conn->state, "processing");
        } else if (strcmp(event, "close") == 0) {
            strcpy(conn->state, "closing");
        }
    } else if (strcmp(conn->state, "processing") == 0) {
        if (strcmp(event, "complete") == 0) {
            strcpy(conn->state, "open");
        }
    } else if (strcmp(conn->state, "closing") == 0) {
        if (strcmp(event, "closed") == 0) {
            strcpy(conn->state, "closed");
        }
    }
}

int Connection_is_active(Connection *conn) {
    return strcmp(conn->state, "open") == 0 || strcmp(conn->state, "processing") == 0 || strcmp(conn->state, "closing") == 0;
}

typedef struct {
    Connection connections[10];
} Network;

void Network_init(Network *net) {
    for (int i = 0; i < 10; i++) {
        Connection_init(&net->connections[i], "closed");
    }
}

void Network_process_event(Network *net, const char *event) {
    for (int i = 0; i < 10; i++) {
        if (Connection_is_active(&net->connections[i])) {
            Connection_transition(&net->connections[i], event);
        }
    }
}

typedef struct {
    Network network;
    const char *events[4];
} Simulator;

void Simulator_init(Simulator *sim, Network *net) {
    sim->network = *net;
    sim->events[0] = "open";
    sim->events[1] = "data";
    sim->events[2] = "complete";
    sim->events[3] = "close";
}

void Simulator_simulate(Simulator *sim, int event_index) {
    Network_process_event(&sim->network, sim->events[event_index]);
    if (event_index < 3) {
        Simulator_simulate(sim, event_index + 1);
    } else {
        Simulator_simulate(sim, 0);
    }
}

int main() {
    Network network;
    Network_init(&network);
    Simulator simulator;
    Simulator_init(&simulator, &network);
    Simulator_simulate(&simulator, 0);
    return 0;
}