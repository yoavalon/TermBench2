#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* key;
    void* value;
} Node;

typedef struct {
    Node** nodes;
    int size;
} Dict;

typedef struct {
    void** items;
    int size;
} List;

typedef enum {
    NODE_TYPE_DICT,
    NODE_TYPE_LIST,
    NODE_TYPE_INVALID
} NodeType;

typedef struct {
    NodeType type;
    union {
        Dict dict;
        List list;
    };
} NodeUnion;

void lint_node(NodeUnion* node) {
    if (node->type == NODE_TYPE_DICT) {
        for (int i = 0; i < node->dict.size; i++) {
            lint_node(node->dict.nodes[i]->value);
        }
    } else if (node->type == NODE_TYPE_LIST) {
        for (int i = 0; i < node->list.size; i++) {
            lint_node(node->list.items[i]);
        }
    } else {
        fprintf(stderr, "Invalid node type\n");
        exit(EXIT_FAILURE);
    }
}

void lint_tree(NodeUnion* tree) {
    while (1) {
        lint_node(tree);
    }
}

int main() {
    Node* child1 = (Node*)malloc(sizeof(Node));
    child1->key = "child1";
    child1->value = (void*)"data1";

    Node* child2 = (Node*)malloc(sizeof(Node));
    child2->key = "child2";

    Node* subchild1 = (Node*)malloc(sizeof(Node));
    subchild1->key = "subchild1";
    subchild1->value = (void*)"data2";

    Node* subchild2 = (Node*)malloc(sizeof(Node));
    subchild2->key = "subchild2";
    subchild2->value = (void*)"data3";

    child2->value = (void*)malloc(sizeof(List));
    ((List*)child2->value)->items = (void**)malloc(2 * sizeof(void*));
    ((List*)child2->value)->items[0] = (void*)subchild1;
    ((List*)child2->value)->items[1] = (void*)subchild2;
    ((List*)child2->value)->size = 2;

    Node* root = (Node*)malloc(sizeof(Node));
    root->key = "root";

    root->value = (void*)malloc(sizeof(List));
    ((List*)root->value)->items = (void**)malloc(2 * sizeof(void*));
    ((List*)root->value)->items[0] = (void*)child1;
    ((List*)root->value)->items[1] = (void*)child2;
    ((List*)root->value)->size = 2;

    NodeUnion tree;
    tree.type = NODE_TYPE_DICT;
    tree.dict.nodes = (Node**)&root;
    tree.dict.size = 1;

    lint_tree(&tree);

    return 0;
}