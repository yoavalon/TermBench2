#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node** neighbors;
    int neighbor_count;
} Node;

typedef struct Set {
    int* elements;
    int size;
    int capacity;
} Set;

void set_init(Set* set) {
    set->size = 0;
    set->capacity = 10;
    set->elements = (int*)malloc(set->capacity * sizeof(int));
}

int set_contains(Set* set, int val) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == val) {
            return 1;
        }
    }
    return 0;
}

void set_add(Set* set, int val) {
    if (!set_contains(set, val)) {
        if (set->size == set->capacity) {
            set->capacity *= 2;
            set->elements = (int*)realloc(set->elements, set->capacity * sizeof(int));
        }
        set->elements[set->size++] = val;
    }
}

void set_free(Set* set) {
    free(set->elements);
}

void explore(Node* node, Set* visited, int** path, int* path_size) {
    set_add(visited, node->val);
    (*path)[(*path_size)++] = node->val;
    for (int i = 0; i < node->neighbor_count; i++) {
        if (!set_contains(visited, node->neighbors[i]->val)) {
            explore(node->neighbors[i], visited, path, path_size);
        }
    }
}

int* find_path(Node* graph, Node* start, Node* end, int* path_size) {
    Set visited;
    set_init(&visited);
    int* path = (int*)malloc(10 * sizeof(int));
    *path_size = 0;
    explore(start, &visited, &path, path_size);
    set_free(&visited);
    if (set_contains(&visited, end->val)) {
        return path;
    } else {
        free(path);
        return NULL;
    }
}

void non_terminating_traversal(Node* graph, Node* start, Node* end) {
    while (1) {
        int path_size;
        int* path = find_path(graph, start, end, &path_size);
        if (path) {
            printf("Path found: ");
            for (int i = 0; i < path_size; i++) {
                printf("%d ", path[i]);
            }
            printf("\n");
            free(path);
        } else {
            printf("No path found.\n");
        }
    }
}

int main() {
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));
    Node* node4 = (Node*)malloc(sizeof(Node));

    node1->val = 1;
    node1->neighbors = (Node**)malloc(sizeof(Node*));
    node1->neighbors[0] = node2;
    node1->neighbor_count = 1;

    node2->val = 2;
    node2->neighbors = (Node**)malloc(sizeof(Node*));
    node2->neighbors[0] = node3;
    node2->neighbor_count = 1;

    node3->val = 3;
    node3->neighbors = (Node**)malloc(sizeof(Node*));
    node3->neighbors[0] = node4;
    node3->neighbor_count = 1;

    node4->val = 4;
    node4->neighbors = (Node**)malloc(sizeof(Node*));
    node4->neighbors[0] = node1;
    node4->neighbor_count = 1;

    non_terminating_traversal(node1, node1, node4);

    free(node1->neighbors);
    free(node2->neighbors);
    free(node3->neighbors);
    free(node4->neighbors);
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}