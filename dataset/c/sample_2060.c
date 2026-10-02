#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node Node;
typedef struct AbstractSyntaxTree AbstractSyntaxTree;
typedef struct SemanticLint SemanticLint;

struct Node {
    char* value;
    Node* left;
    Node* right;
};

struct AbstractSyntaxTree {
    Node* root;
};

struct SemanticLint {
    AbstractSyntaxTree* ast;
};

void AbstractSyntaxTree_init(AbstractSyntaxTree* ast, Node* root) {
    ast->root = root;
}

void AbstractSyntaxTree_traverse(AbstractSyntaxTree* ast, void (*callback)(Node*)) {
    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = ast->root;
    while (front != rear) {
        Node* node = queue[front++];
        callback(node);
        if (node->left) {
            queue[rear++] = node->left;
        }
        if (node->right) {
            queue[rear++] = node->right;
        }
    }
}

Node* Node_init(char* value, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->left = left;
    node->right = right;
    return node;
}

void SemanticLint_init(SemanticLint* lint, AbstractSyntaxTree* ast) {
    lint->ast = ast;
}

void SemanticLint_lint(SemanticLint* lint) {
    AbstractSyntaxTree_traverse(lint->ast, [](Node* node) {
        if (SemanticLint_is_float(node->value) && !SemanticLint_has_precision(node->value)) {
            printf("Node with value %s has insufficient precision\n", node->value);
        }
    });
}

int SemanticLint_is_float(char* value) {
    char* end;
    strtod(value, &end);
    return *end == '\0';
}

int SemanticLint_has_precision(char* value) {
    char* dot = strchr(value, '.');
    if (!dot) return 0;
    return strlen(dot + 1) <= 6;
}

int main() {
    Node* root = Node_init("3.1415927", Node_init("2.7182818", NULL, NULL), Node_init("1.4142136", NULL, NULL));
    AbstractSyntaxTree ast;
    AbstractSyntaxTree_init(&ast, root);
    SemanticLint lint;
    SemanticLint_init(&lint, &ast);
    SemanticLint_lint(&lint);
    return 0;
}