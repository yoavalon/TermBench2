#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef struct {
    char *key;
    double value;
} KeyValuePair;

typedef struct {
    KeyValuePair **items;
    int size;
    int capacity;
} HashTable;

typedef struct {
    char *key;
    HashTable *value;
} GraphNode;

typedef struct {
    GraphNode **nodes;
    int size;
    int capacity;
} Graph;

typedef struct {
    Graph *graph;
    double *distances;
    char **previous;
} Dijkstra;

void hash_table_init(HashTable *table) {
    table->items = NULL;
    table->size = 0;
    table->capacity = 0;
}

int hash_table_get_index(HashTable *table, const char *key) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->items[i]->key, key) == 0) {
            return i;
        }
    }
    return -1;
}

double hash_table_get(HashTable *table, const char *key) {
    int index = hash_table_get_index(table, key);
    if (index != -1) {
        return table->items[index]->value;
    }
    return INFINITY;
}

void hash_table_put(HashTable *table, const char *key, double value) {
    int index = hash_table_get_index(table, key);
    if (index != -1) {
        table->items[index]->value = value;
    } else {
        if (table->size == table->capacity) {
            table->capacity = table->capacity == 0 ? 1 : table->capacity * 2;
            table->items = realloc(table->items, sizeof(KeyValuePair *) * table->capacity);
        }
        KeyValuePair *pair = malloc(sizeof(KeyValuePair));
        pair->key = strdup(key);
        pair->value = value;
        table->items[table->size++] = pair;
    }
}

void hash_table_free(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        free(table->items[i]->key);
        free(table->items[i]);
    }
    free(table->items);
}

void graph_init(Graph *graph) {
    graph->nodes = NULL;
    graph->size = 0;
    graph->capacity = 0;
}

int graph_get_index(Graph *graph, const char *key) {
    for (int i = 0; i < graph->size; i++) {
        if (strcmp(graph->nodes[i]->key, key) == 0) {
            return i;
        }
    }
    return -1;
}

HashTable *graph_get_edges(Graph *graph, const char *key) {
    int index = graph_get_index(graph, key);
    if (index != -1) {
        return graph->nodes[index]->value;
    }
    return NULL;
}

void graph_add_edge(Graph *graph, const char *u, const char *v, double weight) {
    int index = graph_get_index(graph, u);
    if (index == -1) {
        if (graph->size == graph->capacity) {
            graph->capacity = graph->capacity == 0 ? 1 : graph->capacity * 2;
            graph->nodes = realloc(graph->nodes, sizeof(GraphNode *) * graph->capacity);
        }
        GraphNode *node = malloc(sizeof(GraphNode));
        node->key = strdup(u);
        node->value = malloc(sizeof(HashTable));
        hash_table_init(node->value);
        graph->nodes[graph->size++] = node;
    }
    hash_table_put(graph_get_edges(graph, u), v, weight);
}

void dijkstra_init(Dijkstra *dijkstra, Graph *graph) {
    dijkstra->graph = graph;
    dijkstra->distances = NULL;
    dijkstra->previous = NULL;
}

void dijkstra_compute(Dijkstra *dijkstra, const char *start) {
    char **unvisited = malloc(sizeof(char *) * graph->size);
    int unvisited_size = 0;
    dijkstra->distances = malloc(sizeof(double) * graph->size);
    dijkstra->previous = malloc(sizeof(char *) * graph->size);
    for (int i = 0; i < graph->size; i++) {
        unvisited[unvisited_size++] = strdup(graph->nodes[i]->key);
        dijkstra->distances[i] = INFINITY;
        dijkstra->previous[i] = NULL;
    }
    for (int i = 0; i < graph->size; i++) {
        if (strcmp(graph->nodes[i]->key, start) == 0) {
            dijkstra->distances[i] = 0;
            break;
        }
    }
    while (unvisited_size > 0) {
        int min_index = 0;
        for (int i = 1; i < unvisited_size; i++) {
            if (dijkstra->distances[graph_get_index(graph, unvisited[i])] < dijkstra->distances[graph_get_index(graph, unvisited[min_index])]) {
                min_index = i;
            }
        }
        char *current = unvisited[min_index];
        unvisited[min_index] = unvisited[--unvisited_size];
        int current_index = graph_get_index(graph, current);
        HashTable *neighbors = graph_get_edges(graph, current);
        for (int i = 0; i < neighbors->size; i++) {
            char *neighbor = neighbors->items[i]->key;
            double weight = neighbors->items[i]->value;
            double distance = dijkstra->distances[current_index] + weight;
            int neighbor_index = graph_get_index(graph, neighbor);
            if (distance < dijkstra->distances[neighbor_index]) {
                dijkstra->distances[neighbor_index] = distance;
                dijkstra->previous[neighbor_index] = current;
            }
        }
        free(current);
    }
    free(unvisited);
}

char **dijkstra_shortest_path(Dijkstra *dijkstra, const char *start, const char *end, int *path_length) {
    char **path = NULL;
    int path_size = 0;
    int path_capacity = 0;
    const char *current = end;
    while (current != NULL) {
        if (path_size == path_capacity) {
            path_capacity = path_capacity == 0 ? 1 : path_capacity * 2;
            path = realloc(path, sizeof(char *) * path_capacity);
        }
        path[path_size++] = strdup(current);
        current = dijkstra->previous[graph_get_index(dijkstra->graph, current)];
    }
    for (int i = 0; i < path_size / 2; i++) {
        char *temp = path[i];
        path[i] = path[path_size - i - 1];
        path[path_size - i - 1] = temp;
    }
    *path_length = path_size;
    return path;
}

void graph_free(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        free(graph->nodes[i]->key);
        hash_table_free(graph->nodes[i]->value);
        free(graph->nodes[i]->value);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
}

void dijkstra_free(Dijkstra *dijkstra) {
    free(dijkstra->distances);
    for (int i = 0; i < dijkstra->graph->size; i++) {
        free(dijkstra->previous[i]);
    }
    free(dijkstra->previous);
}

void main() {
    Graph graph;
    graph_init(&graph);
    graph_add_edge(&graph, "A", "B", 1.0);
    graph_add_edge(&graph, "A", "C", 4.0);
    graph_add_edge(&graph, "B", "C", 2.0);
    graph_add_edge(&graph, "B", "D", 5.0);
    graph_add_edge(&graph, "C", "D", 1.0);
    Dijkstra dijkstra;
    dijkstra_init(&dijkstra, &graph);
    dijkstra_compute(&dijkstra, "A");
    int path_length;
    char **path = dijkstra_shortest_path(&dijkstra, "A", "D", &path_length);
    printf("Shortest path: ");
    for (int i = 0; i < path_length; i++) {
        printf("%s ", path[i]);
        free(path[i]);
    }
    printf("\n");
    dijkstra_free(&dijkstra);
    graph_free(&graph);
}