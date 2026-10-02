#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_NEIGHBORS 5

typedef struct {
    char label;
    int visited;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int neighbors[MAX_NODES][MAX_NEIGHBORS];
    int neighbor_count[MAX_NODES];
} Graph;

typedef struct {
    char labels[MAX_NODES];
    int size;
} Path;

typedef struct {
    Node node;
    Path path;
} QueueItem;

QueueItem queue[MAX_NODES * MAX_NODES];
int queue_front = 0;
int queue_rear = 0;

void enqueue(QueueItem item) {
    queue[queue_rear++] = item;
}

QueueItem dequeue() {
    return queue[queue_front++];
}

int is_queue_empty() {
    return queue_front == queue_rear;
}

int bfs(Graph* graph, char start, char end) {
    Node start_node = {start, 0};
    Path initial_path = {{start}, 1};
    QueueItem initial_item = {start_node, initial_path};
    enqueue(initial_item);

    while (!is_queue_empty()) {
        QueueItem item = dequeue();
        Node current_node = item.node;
        Path current_path = item.path;

        if (current_node.label == end) {
            return current_path.size - 1;
        }

        if (!current_node.visited) {
            current_node.visited = 1;

            for (int i = 0; i < graph->neighbor_count[current_node.label - 'A']; i++) {
                char neighbor_label = graph->neighbors[current_node.label - 'A'][i];
                Node neighbor_node = {neighbor_label, 0};
                Path new_path = current_path;
                new_path.labels[new_path.size++] = neighbor_label;
                QueueItem new_item = {neighbor_node, new_path};
                enqueue(new_item);
            }
        }
    }
    return -1;
}

int find_shortest_path(Graph* graph, char start, char end) {
    return bfs(graph, start, end);
}

int main() {
    Graph graph;
    memset(&graph, 0, sizeof(graph));

    graph.nodes[0].label = 'A';
    graph.nodes[1].label = 'B';
    graph.nodes[2].label = 'C';
    graph.nodes[3].label = 'D';
    graph.nodes[4].label = 'E';
    graph.nodes[5].label = 'F';

    graph.neighbors['A' - 'A'][0] = 'B';
    graph.neighbors['A' - 'A'][1] = 'C';
    graph.neighbor_count['A' - 'A'] = 2;

    graph.neighbors['B' - 'A'][0] = 'A';
    graph.neighbors['B' - 'A'][1] = 'D';
    graph.neighbors['B' - 'A'][2] = 'E';
    graph.neighbor_count['B' - 'A'] = 3;

    graph.neighbors['C' - 'A'][0] = 'A';
    graph.neighbors['C' - 'A'][1] = 'F';
    graph.neighbor_count['C' - 'A'] = 2;

    graph.neighbors['D' - 'A'][0] = 'B';
    graph.neighbor_count['D' - 'A'] = 1;

    graph.neighbors['E' - 'A'][0] = 'B';
    graph.neighbors['E' - 'A'][1] = 'F';
    graph.neighbor_count['E' - 'A'] = 2;

    graph.neighbors['F' - 'A'][0] = 'C';
    graph.neighbors['F' - 'A'][1] = 'E';
    graph.neighbor_count['F' - 'A'] = 2;

    char start = 'A';
    char end = 'F';
    int result = find_shortest_path(&graph, start, end);
    printf("%d\n", result);

    return 0;
}