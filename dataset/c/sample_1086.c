#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node** neighbors;
    int neighbor_count;
} Node;

void add_edge(Node* a, Node* b) {
    a->neighbors = realloc(a->neighbors, (a->neighbor_count + 1) * sizeof(Node*));
    a->neighbors[a->neighbor_count++] = b;
    b->neighbors = realloc(b->neighbors, (b->neighbor_count + 1) * sizeof(Node*));
    b->neighbors[b->neighbor_count++] = a;
}

int find_path(Node* start, Node* end, Node** path, int path_length) {
    path[path_length++] = start;
    if (start == end) {
        return 1;
    }
    for (int i = 0; i < start->neighbor_count; i++) {
        Node* node = start->neighbors[i];
        int found = 0;
        for (int j = 0; j < path_length; j++) {
            if (node == path[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            if (find_path(node, end, path, path_length)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    Node* a = (Node*)malloc(sizeof(Node));
    Node* b = (Node*)malloc(sizeof(Node));
    Node* c = (Node*)malloc(sizeof(Node));
    Node* d = (Node*)malloc(sizeof(Node));
    Node* e = (Node*)malloc(sizeof(Node));
    a->value = 1; a->neighbors = NULL; a->neighbor_count = 0;
    b->value = 2; b->neighbors = NULL; b->neighbor_count = 0;
    c->value = 3; c->neighbors = NULL; c->neighbor_count = 0;
    d->value = 4; d->neighbors = NULL; d->neighbor_count = 0;
    e->value = 5; e->neighbors = NULL; e->neighbor_count = 0;
    add_edge(a, b);
    add_edge(b, c);
    add_edge(c, d);
    add_edge(d, e);
    add_edge(e, a);
    Node* path[10];
    while (1) {
        if (find_path(a, e, path, 0)) {
            for (int i = 0; i < 10; i++) {
                if (path[i] == NULL) break;
                printf("%d ", path[i]->value);
            }
            printf("\n");
        }
    }
    return 0;
}