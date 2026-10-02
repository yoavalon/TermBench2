#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *name;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

typedef struct Graph {
    char *name;
    List *neighbors;
} Graph;

typedef struct Path {
    char *name;
    struct Path *next;
} Path;

Graph *create_graph(char *name) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->name = strdup(name);
    graph->neighbors = (List *)malloc(sizeof(List));
    graph->neighbors->head = NULL;
    return graph;
}

void add_edge(Graph *graph, Graph *neighbor) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->name = strdup(neighbor->name);
    new_node->next = graph->neighbors->head;
    graph->neighbors->head = new_node;
}

int contains(List *list, char *name) {
    Node *current = list->head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

Path *dfs(Graph *graph, char *end, Path *path, int *visited, int visited_size) {
    for (int i = 0; i < visited_size; i++) {
        if (strcmp(graph->name, visited[i]) == 0) {
            return NULL;
        }
    }

    Path *new_path = (Path *)malloc(sizeof(Path));
    new_path->name = strdup(graph->name);
    new_path->next = path;

    if (strcmp(graph->name, end) == 0) {
        return new_path;
    }

    Node *current = graph->neighbors->head;
    while (current) {
        Path *result = dfs(current->name, end, new_path, visited, visited_size);
        if (result) {
            return result;
        }
        current = current->next;
    }

    free(new_path);
    return NULL;
}

Path *find_shortest_path(Graph *graph, char *end) {
    int visited[6];
    int visited_size = 0;
    return dfs(graph, end, NULL, visited, visited_size);
}

void print_path(Path *path) {
    if (!path) {
        return;
    }
    print_path(path->next);
    printf("%s ", path->name);
    free(path);
}

int main() {
    Graph *A = create_graph("A");
    Graph *B = create_graph("B");
    Graph *C = create_graph("C");
    Graph *D = create_graph("D");
    Graph *E = create_graph("E");
    Graph *F = create_graph("F");

    add_edge(A, B);
    add_edge(A, C);
    add_edge(B, D);
    add_edge(B, E);
    add_edge(C, F);
    add_edge(E, F);

    Path *path = find_shortest_path(A, "F");
    if (path) {
        printf("Path found: ");
        print_path(path);
        printf("\n");
    } else {
        printf("No path found\n");
    }

    // Free allocated memory
    free(A->name);
    free(A);
    free(B->name);
    free(B);
    free(C->name);
    free(C);
    free(D->name);
    free(D);
    free(E->name);
    free(E);
    free(F->name);
    free(F);

    return 0;
}