#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char name[2];
    struct Node* neighbours[6];
    int neighbour_count;
} Node;

void add_neighbour(Node* node, Node* neighbour) {
    node->neighbours[node->neighbour_count++] = neighbour;
}

bool find_path(Node* start, Node* end, bool visited[6], Node* path, int* path_length) {
    visited[start - &start[-1]] = true;
    path[(*path_length)++] = *start;
    if (start == end) {
        return true;
    }
    for (int i = 0; i < start->neighbour_count; i++) {
        if (!visited[start->neighbours[i] - &start[-1]]) {
            if (find_path(start->neighbours[i], end, visited, path, path_length)) {
                return true;
            }
        }
    }
    (*path_length)--;
    return false;
}

Node* shortest_path(Node* graph, int graph_size, const char* start_name, const char* end_name) {
    Node* start = NULL;
    Node* end = NULL;
    for (int i = 0; i < graph_size; i++) {
        if (strcmp(graph[i].name, start_name) == 0) {
            start = &graph[i];
        }
        if (strcmp(graph[i].name, end_name) == 0) {
            end = &graph[i];
        }
        if (start && end) {
            break;
        }
    }
    if (start && end) {
        bool visited[6] = {0};
        Node path[6];
        int path_length = 0;
        if (find_path(start, end, visited, path, &path_length)) {
            return path;
        }
    }
    return NULL;
}

void main() {
    Node a = {"A", {NULL}, 0};
    Node b = {"B", {NULL}, 0};
    Node c = {"C", {NULL}, 0};
    Node d = {"D", {NULL}, 0};
    Node e = {"E", {NULL}, 0};
    Node f = {"F", {NULL}, 0};
    add_neighbour(&a, &b);
    add_neighbour(&a, &c);
    add_neighbour(&b, &d);
    add_neighbour(&c, &d);
    add_neighbour(&d, &e);
    add_neighbour(&e, &f);
    Node graph[6] = {a, b, c, d, e, f};
    Node* path = shortest_path(graph, 6, "A", "F");
    if (path) {
        for (int i = 0; path[i].name[0] != '\0'; i++) {
            printf("%s", path[i].name);
            if (path[i + 1].name[0] != '\0') {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }
}