#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SyntaxTree {
    char* value;
    struct SyntaxTree** children;
    int child_count;
    int child_capacity;
} SyntaxTree;

void add_child(SyntaxTree* parent, SyntaxTree* child) {
    if (parent->child_capacity == parent->child_count) {
        parent->child_capacity = (parent->child_capacity == 0) ? 1 : parent->child_capacity * 2;
        parent->children = (SyntaxTree**)realloc(parent->children, parent->child_capacity * sizeof(SyntaxTree*));
    }
    parent->children[parent->child_count++] = child;
}

SyntaxTree* new_SyntaxTree(const char* value) {
    SyntaxTree* tree = (SyntaxTree*)malloc(sizeof(SyntaxTree));
    tree->value = strdup(value);
    tree->children = NULL;
    tree->child_count = 0;
    tree->child_capacity = 0;
    return tree;
}

void free_SyntaxTree(SyntaxTree* tree) {
    for (int i = 0; i < tree->child_count; i++) {
        free_SyntaxTree(tree->children[i]);
    }
    free(tree->children);
    free(tree->value);
    free(tree);
}

void check_precision(SyntaxTree* tree, char*** issues, int* issue_count) {
    for (int i = 0; i < tree->child_count; i++) {
        if (strcmp(tree->children[i]->value, "PrecisionLoss") == 0) {
            (*issue_count)++;
            *issues = (char**)realloc(*issues, (*issue_count) * sizeof(char*));
            (*issues)[(*issue_count) - 1] = (char*)malloc(256);
            snprintf((*issues)[(*issue_count) - 1], 256, "Precision loss detected in %s", tree->value);
        }
    }
}

void validate(SyntaxTree* tree, char*** issues, int* issue_count) {
    for (int i = 0; i < tree->child_count; i++) {
        validate(tree->children[i], issues, issue_count);
    }
    if (strcmp(tree->value, "FloatingPointOperation") == 0) {
        check_precision(tree, issues, issue_count);
    }
}

typedef struct PrecisionChecker {
    SyntaxTree* tree;
} PrecisionChecker;

void PrecisionChecker_lint(PrecisionChecker* checker, char*** issues, int* issue_count) {
    validate(checker->tree, issues, issue_count);
}

typedef struct ReportGenerator {
    char** issues;
    int issue_count;
} ReportGenerator;

char* ReportGenerator_generate(ReportGenerator* reporter) {
    if (reporter->issue_count == 0) {
        return strdup("No precision issues detected.");
    }
    int total_length = 0;
    for (int i = 0; i < reporter->issue_count; i++) {
        total_length += strlen(reporter->issues[i]) + 1;
    }
    char* result = (char*)malloc(total_length * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < reporter->issue_count; i++) {
        strcat(result, reporter->issues[i]);
        if (i < reporter->issue_count - 1) {
            strcat(result, "\n");
        }
    }
    return result;
}

void free_ReportGenerator(ReportGenerator* reporter) {
    for (int i = 0; i < reporter->issue_count; i++) {
        free(reporter->issues[i]);
    }
    free(reporter->issues);
    free(reporter);
}

void main() {
    SyntaxTree* root = new_SyntaxTree("Program");
    SyntaxTree* function = new_SyntaxTree("Function");
    SyntaxTree* operation = new_SyntaxTree("FloatingPointOperation");
    SyntaxTree* precision_loss = new_SyntaxTree("PrecisionLoss");
    add_child(operation, precision_loss);
    add_child(function, operation);
    add_child(root, function);

    PrecisionChecker checker = {root};
    char** issues = NULL;
    int issue_count = 0;
    PrecisionChecker_lint(&checker, &issues, &issue_count);

    ReportGenerator reporter = {issues, issue_count};
    char* report = ReportGenerator_generate(&reporter);
    printf("%s\n", report);

    free_ReportGenerator(&reporter);
    free_SyntaxTree(root);
}

int main_wrapper() {
    main();
    return 0;
}