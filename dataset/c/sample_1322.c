#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    char name;
    int weight;
    struct node *next;
} node;

typedef struct {
    char name;
    node *head;
} graph_node;

typedef struct {
    int distance;
    char name;
} queue_node;

void swap(queue_node *a, queue_node *b) {
    queue_node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(queue_node arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].distance < arr[smallest].distance)
        smallest = l;

    if (r < n && arr[r].distance < arr[smallest].distance)
        smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void build_heap(queue_node arr[], int n) {
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void insert(queue_node arr[], int *n, int distance, char name) {
    if (*n == MAX_NODES) return;

    arr[*n].distance = distance;
    arr[*n].name = name;
    (*n)++;

    build_heap(arr, *n);
}

queue_node extract_min(queue_node arr[], int *n) {
    if (*n <= 0) {
        queue_node temp;
        temp.distance = -1;
        temp.name = '\0';
        return temp;
    }

    queue_node root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);

    return root;
}

int dijkstra(graph_node graph[], int num_nodes, char start, char end) {
    int dist[MAX_NODES];
    int visited[MAX_NODES];
    queue_node queue[MAX_NODES];
    int queue_size = 0;

    for (int i = 0; i < num_nodes; i++) {
        dist[i] = 99999;
        visited[i] = 0;
    }

    int start_index = -1;
    for (int i = 0; i < num_nodes; i++) {
        if (graph[i].name == start) {
            start_index = i;
            break;
        }
    }

    if (start_index == -1) return -1;

    dist[start_index] = 0;
    insert(queue, &queue_size, 0, start);

    while (queue_size > 0) {
        queue_node current = extract_min(queue, &queue_size);

        int current_index = -1;
        for (int i = 0; i < num_nodes; i++) {
            if (graph[i].name == current.name) {
                current_index = i;
                break;
            }
        }

        if (visited[current_index]) continue;
        visited[current_index] = 1;

        node *temp = graph[current_index].head;
        while (temp != NULL) {
            int neighbor_index = -1;
            for (int i = 0; i < num_nodes; i++) {
                if (graph[i].name == temp->name) {
                    neighbor_index = i;
                    break;
                }
            }

            if (dist[neighbor_index] > dist[current_index] + temp->weight) {
                dist[neighbor_index] = dist[current_index] + temp->weight;
                insert(queue, &queue_size, dist[neighbor_index], temp->name);
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < num_nodes; i++) {
        if (graph[i].name == end) {
            return dist[i];
        }
    }

    return -1;
}

int main() {
    graph_node graph[MAX_NODES];
    int num_nodes = 4;

    graph[0].name = 'A';
    graph[0].head = (node *)malloc(sizeof(node));
    graph[0].head->name = 'B';
    graph[0].head->weight = 1;
    graph[0].head->next = (node *)malloc(sizeof(node));
    graph[0].head->next->name = 'C';
    graph[0].head->next->weight = 4;
    graph[0].head->next->next = NULL;

    graph[1].name = 'B';
    graph[1].head = (node *)malloc(sizeof(node));
    graph[1].head->name = 'A';
    graph[1].head->weight = 1;
    graph[1].head->next = (node *)malloc(sizeof(node));
    graph[1].head->next->name = 'C';
    graph[1].head->next->weight = 2;
    graph[1].head->next->next = (node *)malloc(sizeof(node));
    graph[1].head->next->next->name = 'D';
    graph[1].head->next->next->weight = 5;
    graph[1].head->next->next->next = NULL;

    graph[2].name = 'C';
    graph[2].head = (node *)malloc(sizeof(node));
    graph[2].head->name = 'A';
    graph[2].head->weight = 4;
    graph[2].head->next = (node *)malloc(sizeof(node));
    graph[2].head->next->name = 'B';
    graph[2].head->next->weight = 2;
    graph[2].head->next->next = (node *)malloc(sizeof(node));
    graph[2].head->next->next->name = 'D';
    graph[2].head->next->next->weight = 1;
    graph[2].head->next->next->next = NULL;

    graph[3].name = 'D';
    graph[3].head = (node *)malloc(sizeof(node));
    graph[3].head->name = 'B';
    graph[3].head->weight = 5;
    graph[3].head->next = (node *)malloc(sizeof(node));
    graph[3].head->next->name = 'C';
    graph[3].head->next->weight = 1;
    graph[3].head->next->next = NULL;

    char start = 'A';
    char end = 'D';
    int result = dijkstra(graph, num_nodes, start, end);
    printf("%d\n", result);

    for (int i = 0; i < num_nodes; i++) {
        node *temp = graph[i].head;
        while (temp != NULL) {
            node *next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}