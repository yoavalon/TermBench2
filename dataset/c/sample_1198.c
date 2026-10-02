#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 20
#define MAX_EDGES 100

typedef struct {
    char name;
    int edges[MAX_EDGES];
    int edge_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

typedef struct {
    Graph *graph;
} PathFinder;

Graph* create_graph() {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->node_count = 0;
    return g;
}

void add_node(Graph *g, char node) {
    for (int i = 0; i < g->node_count; i++) {
        if (g->nodes[i].name == node) return;
    }
    g->nodes[g->node_count].name = node;
    g->nodes[g->node_count].edge_count = 0;
    g->node_count++;
}

void add_edge(Graph *g, char node1, char node2) {
    int index1 = -1, index2 = -1;
    for (int i = 0; i < g->node_count; i++) {
        if (g->nodes[i].name == node1) index1 = i;
        if (g->nodes[i].name == node2) index2 = i;
    }
    if (index1 != -1 && index2 != -1) {
        g->nodes[index1].edges[g->nodes[index1].edge_count++] = index2;
        g->nodes[index2].edges[g->nodes[index2].edge_count++] = index1;
    }
}

int find_path(PathFinder *pf, char start, char end, char *path, int path_length) {
    path[path_length] = start;
    path_length++;
    if (start == end) {
        return 1;
    }
    int start_index = -1;
    for (int i = 0; i < pf->graph->node_count; i++) {
        if (pf->graph->nodes[i].name == start) {
            start_index = i;
            break;
        }
    }
    if (start_index == -1) {
        return 0;
    }
    for (int i = 0; i < pf->graph->nodes[start_index].edge_count; i++) {
        int neighbor_index = pf->graph->nodes[start_index].edges[i];
        int found = 0;
        for (int j = 0; j < path_length; j++) {
            if (pf->graph->nodes[neighbor_index].name == path[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            if (find_path(pf, pf->graph->nodes[neighbor_index].name, end, path, path_length)) {
                return 1;
            }
        }
    }
    return 0;
}

void main() {
    Graph *g = create_graph();
    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < 8; i++) {
        add_node(g, nodes[i]);
    }
    char edges[][2] = {{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'C', 'G'}, {'D', 'H'}, {'E', 'H'}, {'F', 'H'}, {'G', 'H'}};
    for (int i = 0; i < 10; i++) {
        add_edge(g, edges[i][0], edges[i][1]);
    }
    PathFinder pf;
    pf.graph = g;
    char path[MAX_NODES];
    while (1) {
        if (find_path(&pf, 'A', 'H', path, 0)) {
            for (int i = 0; i < MAX_NODES; i++) {
                if (path[i] == '\0') break;
                printf("%c ", path[i]);
            }
            printf("\n");
        } else {
            printf("No path found\n");
        }
    }
}