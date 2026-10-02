c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(char* value, Node** children, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = children;
    node->child_count = child_count;
    return node;
}

bool validate(Node* node, char* rules[], int rule_count) {
    if (!node) {
        return true;
    }
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(node->value, rules[i]) == 0) {
            break;
        }
        if (i == rule_count - 1) {
            return false;
        }
    }
    for (int i = 0; i < node->child_count; i++) {
        if (!validate(node->children[i], rules, rule_count)) {
            return false;
        }
    }
    return true;
}

int main() {
    Node* b = create_node("b", NULL, 0);
    Node* c = create_node("c", NULL, 0);
    Node* a = create_node("a", (Node*[]){b, c}, 2);
    Node* e = create_node("e", NULL, 0);
    Node* d = create_node("d", (Node*[]){e}, 1);
    Node* root = create_node("root", (Node*[]){a, d}, 2);

    char* rules[] = {"root", "a", "b", "c", "d", "e"};
    int rule_count = sizeof(rules) / sizeof(rules[0]);

    printf("%d\n", validate(root, rules, rule_count));

    // Clean up memory (not required for termination but good practice)
    free(b);
    free(c);
    free(a);
    free(e);
    free(d);
    free(root);

    return 0;
}