#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[2];
    struct Node* next;
} Node;

typedef struct {
    Node* start;
    Node* end;
    int cost;
} Edge;

typedef struct {
    Node* nodes;
    Edge* edges;
    int num_nodes;
    int num_edges;
} SupplyChain;

SupplyChain* create_supply_chain(Node* nodes, Edge* edges, int num_nodes, int num_edges) {
    SupplyChain* supply_chain = (SupplyChain*)malloc(sizeof(SupplyChain));
    supply_chain->nodes = nodes;
    supply_chain->edges = edges;
    supply_chain->num_nodes = num_nodes;
    supply_chain->num_edges = num_edges;
    return supply_chain;
}

int optimize(SupplyChain* supply_chain, char* start, char* end) {
    Node* visited = NULL;
    Node* path = find_path(supply_chain, start, end, visited);
    if (path) {
        return calculate_cost(supply_chain, path);
    }
    return INT_MAX;
}

Node* find_path(SupplyChain* supply_chain, char* current, char* end, Node* visited) {
    Node* current_node = supply_chain->nodes;
    while (current_node != NULL) {
        if (strcmp(current_node->name, current) == 0) {
            break;
        }
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return NULL;
    }
    Node* visited_node = visited;
    while (visited_node != NULL) {
        if (strcmp(visited_node->name, current) == 0) {
            return NULL;
        }
        visited_node = visited_node->next;
    }
    if (strcmp(current, end) == 0) {
        Node* path = (Node*)malloc(sizeof(Node));
        strcpy(path->name, current);
        path->next = NULL;
        return path;
    }
    Node* neighbors = get_neighbors(supply_chain, current);
    Node* neighbor = neighbors;
    while (neighbor != NULL) {
        Node* path = find_path(supply_chain, neighbor->name, end, visited);
        if (path) {
            Node* new_path = (Node*)malloc(sizeof(Node));
            strcpy(new_path->name, current);
            new_path->next = path;
            return new_path;
        }
        neighbor = neighbor->next;
    }
    return NULL;
}

Node* get_neighbors(SupplyChain* supply_chain, char* node) {
    Node* neighbors = NULL;
    for (int i = 0; i < supply_chain->num_edges; i++) {
        if (strcmp(supply_chain->edges[i].start->name, node) == 0) {
            Node* neighbor = (Node*)malloc(sizeof(Node));
            strcpy(neighbor->name, supply_chain->edges[i].end->name);
            neighbor->next = neighbors;
            neighbors = neighbor;
        }
    }
    return neighbors;
}

int calculate_cost(SupplyChain* supply_chain, Node* path) {
    int cost = 0;
    Node* current = path;
    while (current->next != NULL) {
        for (int i = 0; i < supply_chain->num_edges; i++) {
            if (strcmp(supply_chain->edges[i].start->name, current->name) == 0 && strcmp(supply_chain->edges[i].end->name, current->next->name) == 0) {
                cost += supply_chain->edges[i].cost;
                break;
            }
        }
        current = current->next;
    }
    return cost;
}

int main() {
    Node* nodes = (Node*)malloc(4 * sizeof(Node));
    strcpy(nodes[0].name, "A");
    strcpy(nodes[1].name, "B");
    strcpy(nodes[2].name, "C");
    strcpy(nodes[3].name, "D");
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[2].next = &nodes[3];
    nodes[3].next = NULL;

    Edge* edges = (Edge*)malloc(4 * sizeof(Edge));
    edges[0].start = &nodes[0];
    edges[0].end = &nodes[1];
    edges[0].cost = 10;
    edges[1].start = &nodes[1];
    edges[1].end = &nodes[2];
    edges[1].cost = 20;
    edges[2].start = &nodes[2];
    edges[2].end = &nodes[3];
    edges[2].cost = 30;
    edges[3].start = &nodes[3];
    edges[3].end = &nodes[0];
    edges[3].cost = 40;

    SupplyChain* supply_chain = create_supply_chain(nodes, edges, 4, 4);

    while (1) {
        int cost = optimize(supply_chain, "A", "D");
        printf("Optimized cost: %d\n", cost);
    }

    return 0;
}