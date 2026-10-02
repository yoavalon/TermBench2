#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void add_to_list(List* list, char* value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = strdup(value);
    new_node->next = list->head;
    list->head = new_node;
}

void free_list(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    free(list);
}

List* parse_tree(char* node) {
    List* result = create_list();
    if (strchr(node, '[') == NULL && strchr(node, ']') == NULL) {
        add_to_list(result, node);
    } else {
        int i = 0;
        while (node[i] != '\0') {
            if (node[i] == '[') {
                int depth = 1;
                int start = i + 1;
                while (depth > 0) {
                    i++;
                    if (node[i] == '[') {
                        depth++;
                    } else if (node[i] == ']') {
                        depth--;
                    }
                }
                char* sub_node = (char*)malloc(i - start + 2);
                strncpy(sub_node, node + start, i - start);
                sub_node[i - start] = '\0';
                List* sub_list = parse_tree(sub_node);
                Node* current = sub_list->head;
                while (current != NULL) {
                    add_to_list(result, current->value);
                    current = current->next;
                }
                free_list(sub_list);
                free(sub_node);
            }
            i++;
        }
    }
    return result;
}

int check_boundaries(char* tree, int boundary) {
    List* parsed = parse_tree(tree);
    Node* current = parsed->head;
    while (current != NULL) {
        if (strlen(current->value) > boundary) {
            free_list(parsed);
            return 0;
        }
        current = current->next;
    }
    free_list(parsed);
    return 1;
}

int main() {
    char* tree = "['root', ['child1', 'child2'], ['child3', ['grandchild1', 'grandchild2']]]";
    int boundary = 5;
    printf("%d\n", check_boundaries(tree, boundary));
    return 0;
}