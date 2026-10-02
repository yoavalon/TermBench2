#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char value[10];
    struct Node* left;
    struct Node* right;
} Node;

void init_node(Node* node, const char* value, Node* left, Node* right) {
    strcpy(node->value, value);
    node->left = left;
    node->right = right;
}

void analyze_tree(Node* node, int* depth, int* precision) {
    if (node == NULL) {
        *depth = 0;
        *precision = 0;
        return;
    }
    int l_depth, l_precision;
    int r_depth, r_precision;
    analyze_tree(node->left, &l_depth, &l_precision);
    analyze_tree(node->right, &r_depth, &r_precision);
    *depth = (l_depth > r_depth) ? l_depth + 1 : r_depth + 1;
    *precision = l_precision + r_precision + (node->value[0] == '.');
}

Node* build_tree(char** tokens) {
    if (**tokens == '\0') {
        return NULL;
    }
    char* token = *tokens;
    (*tokens)++;
    if (*token == '(') {
        Node* node = (Node*)malloc(sizeof(Node));
        init_node(node, token, build_tree(tokens), NULL);
        (*tokens)++;
        node->right = build_tree(tokens);
        return node;
    } else {
        Node* node = (Node*)malloc(sizeof(Node));
        init_node(node, token, NULL, NULL);
        return node;
    }
}

void evaluate_expression(const char* expression, int* depth, int* precision) {
    char tokens[100][10];
    int token_count = 0;
    const char* char_ptr = expression;
    while (*char_ptr != '\0') {
        if (*char_ptr == '(' || *char_ptr == ')') {
            strcpy(tokens[token_count], char_ptr);
            token_count++;
            char_ptr++;
        } else if (*char_ptr == '.') {
            strcpy(tokens[token_count], ".");
            token_count++;
            char_ptr++;
        } else {
            char num_str[10] = "";
            int i = 0;
            while ((*char_ptr >= '0' && *char_ptr <= '9') || *char_ptr == '.') {
                num_str[i++] = *char_ptr;
                char_ptr++;
            }
            strcpy(tokens[token_count], num_str);
            token_count++;
        }
    }
    tokens[token_count][0] = '\0';
    char** token_ptr = tokens;
    Node* root = build_tree(&token_ptr);
    analyze_tree(root, depth, precision);
}

int main() {
    while (1) {
        const char* expression = "1.234+(5.678*(9.012/3.456))";
        int depth, precision;
        evaluate_expression(expression, &depth, &precision);
        printf("Depth: %d, Precision: %d\n", depth, precision);
    }
    return 0;
}