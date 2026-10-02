#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *name;
    struct Edge *edges;
    struct Node *next;
} Node;

typedef struct Edge {
    Node *to;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Graph {
    Node *nodes;
} Graph;

typedef struct PathFinder {
    Graph *graph;
} PathFinder;

Graph* Graph_new() {
    Graph *self = malloc(sizeof(Graph));
    self->nodes = NULL;
    return self;
}

void Graph_add_node(Graph *self, const char *node) {
    Node *new_node = malloc(sizeof(Node));
    new_node->name = strdup(node);
    new_node->edges = NULL;
    new_node->next = self->nodes;
    self->nodes = new_node;
}

void Graph_add_edge(Graph *self, const char *node1, const char *node2, int weight) {
    Node *from = self->nodes;
    Node *to = self->nodes;
    while (from && strcmp(from->name, node1) != 0) {
        from = from->next;
    }
    while (to && strcmp(to->name, node2) != 0) {
        to = to->next;
    }
    if (from && to) {
        Edge *new_edge1 = malloc(sizeof(Edge));
        new_edge1->to = to;
        new_edge1->weight = weight;
        new_edge1->next = from->edges;
        from->edges = new_edge1;

        Edge *new_edge2 = malloc(sizeof(Edge));
        new_edge2->to = from;
        new_edge2->weight = weight;
        new_edge2->next = to->edges;
        to->edges = new_edge2;
    }
}

PathFinder* PathFinder_new(Graph *graph) {
    PathFinder *self = malloc(sizeof(PathFinder));
    self->graph = graph;
    return self;
}

char** find_shortest_path(PathFinder *self, const char *start, const char *end, int *path_length) {
    Node *start_node = self->graph->nodes;
    Node *end_node = self->graph->nodes;
    while (start_node && strcmp(start_node->name, start) != 0) {
        start_node = start_node->next;
    }
    while (end_node && strcmp(end_node->name, end) != 0) {
        end_node = end_node->next;
    }
    if (!start_node || !end_node) {
        *path_length = 0;
        return NULL;
    }

    Node **queue = malloc(sizeof(Node*) * 100);
    int queue_size = 0;
    int *distances = malloc(sizeof(int) * 100);
    char **paths = malloc(sizeof(char*) * 100);
    int *path_lengths = malloc(sizeof(int) * 100);
    int *visited = malloc(sizeof(int) * 100);

    queue[queue_size++] = start_node;
    distances[0] = 0;
    paths[0] = strdup(start);
    path_lengths[0] = 1;
    visited[0] = 1;

    while (queue_size > 0) {
        Node *node = queue[0];
        int distance = distances[0];
        for (int i = 1; i < queue_size; i++) {
            if (distances[i] < distance) {
                node = queue[i];
                distance = distances[i];
            }
        }

        for (int i = 0; i < queue_size; i++) {
            if (queue[i] == node) {
                for (int j = i + 1; j < queue_size; j++) {
                    queue[j - 1] = queue[j];
                }
                queue_size--;
                break;
            }
        }

        if (node == end_node) {
            *path_length = path_lengths[0];
            return paths;
        }

        for (Edge *edge = node->edges; edge; edge = edge->next) {
            if (!visited[edge->to - self->graph->nodes]) {
                visited[edge->to - self->graph->nodes] = 1;
                queue[queue_size++] = edge->to;
                distances[queue_size - 1] = distance + edge->weight;
                paths[queue_size - 1] = strdup(paths[0]);
                path_lengths[queue_size - 1] = path_lengths[0] + 1;
                paths[queue_size - 1] = realloc(paths[queue_size - 1], sizeof(char*) * path_lengths[queue_size - 1]);
                paths[queue_size - 1][path_lengths[queue_size - 1] - 1] = edge->to->name;
            }
        }
    }

    *path_length = 0;
    return NULL;
}

void main() {
    Graph *g = Graph_new();
    Graph_add_node(g, "A");
    Graph_add_node(g, "B");
    Graph_add_node(g, "C");
    Graph_add_node(g, "D");
    Graph_add_node(g, "E");
    Graph_add_node(g, "F");
    Graph_add_node(g, "G");
    Graph_add_edge(g, "A", "B", 1);
    Graph_add_edge(g, "A", "C", 4);
    Graph_add_edge(g, "B", "C", 2);
    Graph_add_edge(g, "B", "D", 5);
    Graph_add_edge(g, "C", "D", 1);
    Graph_add_edge(g, "C", "E", 3);
    Graph_add_edge(g, "D", "E", 1);
    Graph_add_edge(g, "D", "F", 8);
    Graph_add_edge(g, "E", "F", 2);
    Graph_add_edge(g, "E", "G", 2);
    Graph_add_edge(g, "F", "G", 7);

    PathFinder *pf = PathFinder_new(g);
    int path_length;
    char **path = find_shortest_path(pf, "A", "G", &path_length);

    if (path) {
        for (int i = 0; i < path_length; i++) {
            printf("%s ", path[i]);
        }
        printf("\n");
    }

    free(g);
    free(pf);
}