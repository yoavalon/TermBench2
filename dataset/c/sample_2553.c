#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_PATH 20

typedef struct {
    char *name;
    int neighbors_count;
    char *neighbors[MAX_NODES];
} Node;

typedef struct {
    Node *nodes[MAX_NODES];
    int size;
} Graph;

typedef struct {
    char *path[MAX_PATH];
    int length;
} Path;

Graph *create_graph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->size = 0;
    return graph;
}

void add_node(Graph *graph, char *name) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->name = (char *)malloc(strlen(name) + 1);
    strcpy(node->name, name);
    node->neighbors_count = 0;
    graph->nodes[graph->size++] = node;
}

void add_edge(Graph *graph, char *from, char *to) {
    for (int i = 0; i < graph->size; i++) {
        if (strcmp(graph->nodes[i]->name, from) == 0) {
            for (int j = 0; j < graph->size; j++) {
                if (strcmp(graph->nodes[j]->name, to) == 0) {
                    graph->nodes[i]->neighbors[graph->nodes[i]->neighbors_count++] = to;
                    break;
                }
            }
            break;
        }
    }
}

Path *bfs(Graph *graph, char *start, char *end) {
    Path *queue[MAX_PATH];
    int queue_size = 0;

    for (int i = 0; i < graph->size; i++) {
        if (strcmp(graph->nodes[i]->name, start) == 0) {
            Path *path = (Path *)malloc(sizeof(Path));
            path->path[0] = start;
            path->length = 1;
            queue[queue_size++] = path;
            break;
        }
    }

    while (queue_size > 0) {
        Path *current_path = queue[0];
        for (int i = 1; i < queue_size; i++) {
            queue[i - 1] = queue[i];
        }
        queue_size--;

        Node *current_node = NULL;
        for (int i = 0; i < graph->size; i++) {
            if (strcmp(graph->nodes[i]->name, current_path->path[current_path->length - 1]) == 0) {
                current_node = graph->nodes[i];
                break;
            }
        }

        for (int i = 0; i < current_node->neighbors_count; i++) {
            int found = 0;
            for (int j = 0; j < current_path->length; j++) {
                if (strcmp(current_node->neighbors[i], current_path->path[j]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found) continue;

            if (strcmp(current_node->neighbors[i], end) == 0) {
                Path *new_path = (Path *)malloc(sizeof(Path));
                for (int j = 0; j < current_path->length; j++) {
                    new_path->path[j] = current_path->path[j];
                }
                new_path->path[current_path->length] = end;
                new_path->length = current_path->length + 1;
                return new_path;
            } else {
                Path *new_path = (Path *)malloc(sizeof(Path));
                for (int j = 0; j < current_path->length; j++) {
                    new_path->path[j] = current_path->path[j];
                }
                new_path->path[current_path->length] = current_node->neighbors[i];
                new_path->length = current_path->length + 1;
                queue[queue_size++] = new_path;
            }
        }
    }
    return NULL;
}

Path *find_shortest_path(Graph *graph, char *start, char *end) {
    return bfs(graph, start, end);
}

void main() {
    Graph *graph = create_graph();
    add_node(graph, "A");
    add_node(graph, "B");
    add_node(graph, "C");
    add_node(graph, "D");
    add_node(graph, "E");
    add_node(graph, "F");

    add_edge(graph, "A", "B");
    add_edge(graph, "A", "C");
    add_edge(graph, "B", "D");
    add_edge(graph, "B", "E");
    add_edge(graph, "C", "F");
    add_edge(graph, "E", "F");

    char *start = "A";
    char *end = "F";
    Path *path = find_shortest_path(graph, start, end);

    if (path) {
        for (int i = 0; i < path->length; i++) {
            printf("%s", path->path[i]);
            if (i < path->length - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }
}