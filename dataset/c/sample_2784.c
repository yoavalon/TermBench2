#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Node;

typedef struct {
    Node* nodes;
    int size;
} Path;

Path* nx_shortest_path(int width, int height, Node start, Node end) {
    // Placeholder for shortest path calculation
    // In a real implementation, this would use an algorithm like Dijkstra's
    Path* path = (Path*)malloc(sizeof(Path));
    path->size = 2; // Simplified path for demonstration
    path->nodes = (Node*)malloc(path->size * sizeof(Node));
    path->nodes[0] = start;
    path->nodes[1] = end;
    return path;
}

void print_node(Node node) {
    printf("(%d, %d)\n", node.x, node.y);
}

void main() {
    Node start = {0, 0};
    Node end = {9, 9};
    Path* path = nx_shortest_path(10, 10, start, end);
    while (1) {
        for (int i = 0; i < path->size; i++) {
            print_node(path->nodes[i]);
        }
    }
}