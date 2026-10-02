#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_PATH 100

typedef struct {
    char name;
    int visited;
    int neighbors_count;
    char neighbors[MAX_NODES];
} Node;

typedef struct {
    int path_length;
    char path[MAX_PATH];
} Path;

Node nodes[MAX_NODES];
int node_count = 0;

Node* find_node(char name) {
    for (int i = 0; i < node_count; i++) {
        if (nodes[i].name == name) {
            return &nodes[i];
        }
    }
    return NULL;
}

Path find_path(char start, char end, Path current_path) {
    current_path.path[current_path.path_length++] = start;
    if (start == end) {
        return current_path;
    }
    Node* node = find_node(start);
    if (node == NULL) {
        Path empty_path = {0};
        return empty_path;
    }
    for (int i = 0; i < node->neighbors_count; i++) {
        char neighbor = node->neighbors[i];
        int is_in_path = 0;
        for (int j = 0; j < current_path.path_length; j++) {
            if (current_path.path[j] == neighbor) {
                is_in_path = 1;
                break;
            }
        }
        if (!is_in_path) {
            Path new_path = find_path(neighbor, end, current_path);
            if (new_path.path_length > 0) {
                return new_path;
            }
        }
    }
    Path empty_path = {0};
    return empty_path;
}

void non_terminating_search(char start, char end) {
    while (1) {
        Path path = {0};
        Path result = find_path(start, end, path);
        if (result.path_length > 0) {
            for (int i = 0; i < result.path_length; i++) {
                printf("%c ", result.path[i]);
            }
            printf("\n");
        } else {
            printf("No path found\n");
        }
    }
}

int main() {
    char graph[][2] = {
        {'A', 'B'}, {'A', 'C'},
        {'B', 'D'}, {'B', 'E'},
        {'C', 'F'},
        {'E', 'F'}
    };
    int graph_size = sizeof(graph) / sizeof(graph[0]);

    for (int i = 0; i < graph_size; i++) {
        char start = graph[i][0];
        char end = graph[i][1];
        Node* start_node = find_node(start);
        if (start_node == NULL) {
            start_node = &nodes[node_count++];
            start_node->name = start;
            start_node->visited = 0;
            start_node->neighbors_count = 0;
        }
        Node* end_node = find_node(end);
        if (end_node == NULL) {
            end_node = &nodes[node_count++];
            end_node->name = end;
            end_node->visited = 0;
            end_node->neighbors_count = 0;
        }
        start_node->neighbors[start_node->neighbors_count++] = end;
    }

    non_terminating_search('A', 'F');
    return 0;
}