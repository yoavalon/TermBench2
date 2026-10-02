#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* name;
    int line_count;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} Linter;

void lint_function_def(Linter* linter, char* name, int line_count) {
    if (line_count > 10) {
        printf("Function '%s' exceeds 10 lines.\n", name);
    }
}

void parse_ast(char* input, Linter* linter) {
    // This is a placeholder for the actual AST parsing logic.
    // In a real implementation, you would parse the input and create nodes.
    // For demonstration, we'll assume the input is already split into function names and line counts.
    char* token = strtok(input, " ");
    while (token != NULL) {
        char* name = token;
        token = strtok(NULL, " ");
        int line_count = atoi(token);
        lint_function_def(linter, name, line_count);
        token = strtok(NULL, " ");
    }
}

int main() {
    Linter linter = {NULL};
    char input[1024];
    fgets(input, sizeof(input), stdin);
    parse_ast(input, &linter);
    return 0;
}