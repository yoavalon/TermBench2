#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 26

typedef struct {
    char name;
    int visited;
    struct Node* next;
} Node;

typedef struct {
    Node** nodes;
    int size;
} Graph;

typedef struct {
    Node** path;
    int size;
    int capacity;
} Path;

Graph* create_graph(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = (Node**)malloc(size * sizeof(Node*));
    graph->size = size;
    for (int i = 0; i < size; i++) {
        graph->nodes[i] = NULL;
    }
    return graph;
}

void add_edge(Graph* graph, char from, char to) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->name = to;
    new_node->visited = 0;
    new_node->next = graph->nodes[from - 'A'];
    graph->nodes[from - 'A'] = new_node;
}

Path* create_path() {
    Path* path = (Path*)malloc(sizeof(Path));
    path->path = (Node**)malloc(MAX_NODES * sizeof(Node*));
    path->size = 0;
    path->capacity = MAX_NODES;
    return path;
}

void add_to_path(Path* path, Node* node) {
    path->path[path->size++] = node;
}

void dfs(Graph* graph, Node* node, Path* path) {
    node->visited = 1;
    add_to_path(path, node);
    Node* current = graph->nodes[node->name - 'A'];
    while (current != NULL) {
        if (!current->visited) {
            dfs(graph, current, path);
        }
        current = current->next;
    }
}

Node* find_node(Graph* graph, char name) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->nodes[i] && graph->nodes[i]->name == name) {
            return graph->nodes[i];
        }
    }
    return NULL;
}

Path* shortest_path(Graph* graph, char start, char end) {
    Node* start_node = find_node(graph, start);
    if (!start_node) return NULL;

    Path* path = create_path();
    dfs(graph, start_node, path);

    for (int i = 0; i < path->size; i++) {
        if (path->path[i]->name == end) {
            return path;
        }
    }
    free(path);
    return NULL;
}

void print_path(Path* path) {
    if (path == NULL) {
        printf("None\n");
        return;
    }
    for (int i = 0; i < path->size; i++) {
        printf("%c ", path->path[i]->name);
    }
    printf("\n");
}

int main() {
    Graph* graph = create_graph(MAX_NODES);
    add_edge(graph, 'A', 'B');
    add_edge(graph, 'A', 'C');
    add_edge(graph, 'B', 'A');
    add_edge(graph, 'B', 'D');
    add_edge(graph, 'B', 'E');
    add_edge(graph, 'C', 'A');
    add_edge(graph, 'C', 'F');
    add_edge(graph, 'D', 'B');
    add_edge(graph, 'E', 'B');
    add_edge(graph, 'E', 'F');
    add_edge(graph, 'F', 'C');
    add_edge(graph, 'F', 'E');

    char start_node = 'A';
    char end_node = 'F';
    Path* result = shortest_path(graph, start_node, end_node);
    print_path(result);

    // Clean up
    for (int i = 0; i < graph->size; i++) {
        Node* current = graph->nodes[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->nodes);
    free(graph);
    if (result != NULL) {
        free(result->path);
        free(result);
    }

    return 0;
}