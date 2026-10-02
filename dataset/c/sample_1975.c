#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 26
#define MAX_PATH 100

typedef struct {
    char node;
    double weight;
} Edge;

typedef struct {
    Edge edges[MAX_NODES];
    int edge_count;
} Node;

typedef struct {
    double cost;
    char path[MAX_PATH];
    int path_length;
} Result;

typedef struct {
    double cost;
    char node;
    char path[MAX_PATH];
    int path_length;
} PriorityQueueElement;

int compare(const void *a, const void *b) {
    PriorityQueueElement *p1 = (PriorityQueueElement *)a;
    PriorityQueueElement *p2 = (PriorityQueueElement *)b;
    if (p1->cost < p2->cost) return -1;
    if (p1->cost > p2->cost) return 1;
    return 0;
}

Result dijkstra(Node graph[], char start, char end) {
    PriorityQueueElement queue[MAX_NODES * MAX_NODES];
    int queue_size = 0;
    int visited[MAX_NODES] = {0};
    Result result;
    result.cost = INT_MAX;
    result.path[0] = '\0';
    result.path_length = 0;

    queue[queue_size].cost = 0;
    queue[queue_size].node = start;
    queue[queue_size].path[0] = start;
    queue[queue_size].path_length = 1;
    queue_size++;

    while (queue_size > 0) {
        qsort(queue, queue_size, sizeof(PriorityQueueElement), compare);
        PriorityQueueElement current = queue[0];
        memmove(queue, queue + 1, (queue_size - 1) * sizeof(PriorityQueueElement));
        queue_size--;

        if (visited[current.node - 'A']) continue;
        visited[current.node - 'A'] = 1;

        if (current.node == end) {
            result.cost = current.cost;
            strncpy(result.path, current.path, MAX_PATH);
            result.path_length = current.path_length;
            break;
        }

        for (int i = 0; i < graph[current.node - 'A'].edge_count; i++) {
            Edge edge = graph[current.node - 'A'].edges[i];
            if (!visited[edge.node - 'A']) {
                PriorityQueueElement new_element;
                new_element.cost = current.cost + edge.weight;
                new_element.node = edge.node;
                strncpy(new_element.path, current.path, MAX_PATH);
                new_element.path[new_element.path_length] = edge.node;
                new_element.path_length = current.path_length + 1;
                queue[queue_size++] = new_element;
            }
        }
    }

    return result;
}

int main() {
    Node graph[MAX_NODES];
    memset(graph, 0, sizeof(graph));

    graph['A' - 'A'].edges[graph['A' - 'A'].edge_count++] = (Edge){'B', 1.5};
    graph['A' - 'A'].edges[graph['A' - 'A'].edge_count++] = (Edge){'C', 2.3};
    graph['B' - 'A'].edges[graph['B' - 'A'].edge_count++] = (Edge){'C', 0.9};
    graph['B' - 'A'].edges[graph['B' - 'A'].edge_count++] = (Edge){'D', 3.2};
    graph['C' - 'A'].edges[graph['C' - 'A'].edge_count++] = (Edge){'D', 1.7};

    char start = 'A';
    char end = 'D';
    Result result = dijkstra(graph, start, end);

    if (result.cost == INT_MAX) {
        printf("(inf, [])\n");
    } else {
        printf("(%.1f, [", result.cost);
        for (int i = 0; i < result.path_length; i++) {
            printf("'%c'", result.path[i]);
            if (i < result.path_length - 1) {
                printf(", ");
            }
        }
        printf("])\n");
    }

    return 0;
}