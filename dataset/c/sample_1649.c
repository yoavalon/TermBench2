#include <stdio.h>
#include <string.h>

typedef struct {
    char node1[10];
    char node2[10];
    char node3[10];
} Nodes;

Nodes update_node_status(Nodes nodes, int node_id, const char* new_status) {
    switch (node_id) {
        case 1:
            strcpy(nodes.node1, new_status);
            break;
        case 2:
            strcpy(nodes.node2, new_status);
            break;
        case 3:
            strcpy(nodes.node3, new_status);
            break;
    }
    return nodes;
}

Nodes simulate_network_activity(Nodes nodes) {
    for (int node_id = 1; node_id <= 3; node_id++) {
        const char* current_status;
        switch (node_id) {
            case 1:
                current_status = nodes.node1;
                break;
            case 2:
                current_status = nodes.node2;
                break;
            case 3:
                current_status = nodes.node3;
                break;
        }
        if (strcmp(current_status, "inactive") == 0) {
            nodes = update_node_status(nodes, node_id, "active");
        } else {
            nodes = update_node_status(nodes, node_id, "inactive");
        }
    }
    return nodes;
}

int main() {
    Nodes initial_nodes;
    strcpy(initial_nodes.node1, "inactive");
    strcpy(initial_nodes.node2, "active");
    strcpy(initial_nodes.node3, "inactive");
    while (1) {
        initial_nodes = simulate_network_activity(initial_nodes);
    }
    return 0;
}