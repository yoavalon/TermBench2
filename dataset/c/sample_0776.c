#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

typedef struct Graph {
    char key;
    List* neighbors;
} Graph;

Graph* create_graph(char key, List* neighbors) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->key = key;
    graph->neighbors = neighbors;
    return graph;
}

List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void add_to_list(List* list, char value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = list->head;
    list->head = new_node;
}

char** find_shortest_path(Graph* graph, char start, char end, char** path, int* path_length) {
    char** new_path = (char**)malloc((*path_length + 1) * sizeof(char*));
    for (int i = 0; i < *path_length; i++) {
        new_path[i] = path[i];
    }
    new_path[*path_length] = (char*)malloc(2 * sizeof(char));
    new_path[*path_length][0] = start;
    new_path[*path_length][1] = '\0';
    (*path_length)++;

    if (start == end) {
        return new_path;
    }

    Graph* current_graph = NULL;
    for (Graph* g = graph; g != NULL; g = g->next) {
        if (g->key == start) {
            current_graph = g;
            break;
        }
    }

    if (current_graph == NULL) {
        return NULL;
    }

    char** shortest = NULL;
    Node* current = current_graph->neighbors->head;
    while (current != NULL) {
        int found = 0;
        for (int i = 0; i < *path_length; i++) {
            if (strcmp(path[i], current->value) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            char** newpath = find_shortest_path(graph, current->value[0], end, new_path, path_length);
            if (newpath != NULL) {
                if (shortest == NULL || *path_length < *shortest_path_length) {
                    shortest = newpath;
                    *shortest_path_length = *path_length;
                }
            }
        }
        current = current->next;
    }
    return shortest;
}

int main() {
    List* list1 = create_list();
    add_to_list(list1, 'B');
    add_to_list(list1, 'C');

    List* list2 = create_list();
    add_to_list(list2, 'C');
    add_to_list(list2, 'D');

    List* list3 = create_list();
    add_to_list(list3, 'D');

    List* list4 = create_list();
    add_to_list(list4, 'C');

    List* list5 = create_list();
    add_to_list(list5, 'F');

    List* list6 = create_list();
    add_to_list(list6, 'C');

    Graph* graph = create_graph('A', list1);
    graph->next = create_graph('B', list2);
    graph->next->next = create_graph('C', list3);
    graph->next->next->next = create_graph('D', list4);
    graph->next->next->next->next = create_graph('E', list5);
    graph->next->next->next->next->next = create_graph('F', list6);

    char start = 'A';
    char end = 'D';
    char** path = (char**)malloc(sizeof(char*));
    int path_length = 0;
    int shortest_path_length = 0;
    char** result = find_shortest_path(graph, start, end, path, &path_length);

    if (result != NULL) {
        for (int i = 0; i < shortest_path_length; i++) {
            printf("%s ", result[i]);
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }

    return 0;
}