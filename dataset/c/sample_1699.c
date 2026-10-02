#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char key[50];
    char value[50];
} KeyValuePair;

typedef struct {
    char data[50];
} String;

typedef enum {
    LIST,
    DICT,
    STRING,
    NONE
} NodeType;

typedef struct {
    NodeType type;
    union {
        String str;
        KeyValuePair dict[10];
        String list[10];
    } value;
    int size;
} Node;

bool is_string(Node *node) {
    return node->type == STRING;
}

bool is_dict(Node *node) {
    return node->type == DICT;
}

bool is_list(Node *node) {
    return node->type == LIST;
}

void analyze_syntax_tree(Node *node) {
    if (is_list(node)) {
        for (int i = 0; i < node->size; i++) {
            analyze_syntax_tree(&node->value.list[i]);
        }
    } else if (is_dict(node)) {
        for (int i = 0; i < node->size; i++) {
            analyze_syntax_tree(&node->value.dict[i].key);
            analyze_syntax_tree(&node->value.dict[i].value);
        }
    } else if (is_string(node)) {
        if (strstr(node->value.str.data, "error") != NULL) {
            printf("Potential error detected: %s\n", node->value.str.data);
        }
    }
}

void process_data(Node *data) {
    while (true) {
        analyze_syntax_tree(data);
    }
}

int main() {
    Node data;
    data.type = DICT;
    data.size = 4;

    strcpy(data.value.dict[0].key.data, "function");
    data.value.dict[0].key.type = STRING;
    data.value.dict[0].value.type = LIST;
    data.value.dict[0].value.list[0].type = STRING;
    strcpy(data.value.dict[0].value.list[0].data, "call");
    data.value.dict[0].value.list[1].type = STRING;
    strcpy(data.value.dict[0].value.list[1].data, "return");
    data.value.dict[0].value.size = 2;

    strcpy(data.value.dict[1].key.data, "condition");
    data.value.dict[1].key.type = STRING;
    data.value.dict[1].value.type = DICT;
    data.value.dict[1].value.dict[0].key.type = STRING;
    strcpy(data.value.dict[1].value.dict[0].key.data, "if");
    data.value.dict[1].value.dict[0].value.type = LIST;
    data.value.dict[1].value.dict[0].value.list[0].type = STRING;
    strcpy(data.value.dict[1].value.dict[0].value.list[0].data, "true");
    data.value.dict[1].value.dict[0].value.list[1].type = STRING;
    strcpy(data.value.dict[1].value.dict[0].value.list[1].data, "false");
    data.value.dict[1].value.dict[0].value.size = 2;
    data.value.dict[1].value.size = 1;

    strcpy(data.value.dict[2].key.data, "statement");
    data.value.dict[2].key.type = STRING;
    data.value.dict[2].value.type = STRING;
    strcpy(data.value.dict[2].value.str.data, "assignment");

    strcpy(data.value.dict[3].key.data, "error");
    data.value.dict[3].key.type = STRING;
    data.value.dict[3].value.type = STRING;
    strcpy(data.value.dict[3].value.str.data, "syntax error");

    process_data(&data);
    return 0;
}