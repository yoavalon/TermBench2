#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct SyntaxTree {
    double value;
    struct SyntaxTree** children;
    int child_count;
    int child_capacity;
} SyntaxTree;

typedef struct SemanticAnalyzer {
    double* found_issues;
    int issue_count;
    int issue_capacity;
} SemanticAnalyzer;

typedef struct Program {
    SyntaxTree* tree;
    SemanticAnalyzer* analyzer;
} Program;

SyntaxTree* create_syntax_tree(double value) {
    SyntaxTree* node = (SyntaxTree*)malloc(sizeof(SyntaxTree));
    node->value = value;
    node->children = (SyntaxTree**)malloc(4 * sizeof(SyntaxTree*));
    node->child_count = 0;
    node->child_capacity = 4;
    return node;
}

void add_child(SyntaxTree* parent, SyntaxTree* child) {
    if (parent->child_count == parent->child_capacity) {
        parent->child_capacity *= 2;
        parent->children = (SyntaxTree**)realloc(parent->children, parent->child_capacity * sizeof(SyntaxTree*));
    }
    parent->children[parent->child_count++] = child;
}

void traverse(SyntaxTree* node, double* values, int* index) {
    values[(*index)++] = node->value;
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i], values, index);
    }
}

SemanticAnalyzer* create_semantic_analyzer() {
    SemanticAnalyzer* analyzer = (SemanticAnalyzer*)malloc(sizeof(SemanticAnalyzer));
    analyzer->found_issues = (double*)malloc(4 * sizeof(double));
    analyzer->issue_count = 0;
    analyzer->issue_capacity = 4;
    return analyzer;
}

void analyze(SemanticAnalyzer* analyzer, SyntaxTree* node) {
    if (node->value != (int)node->value) {
        check_precision(analyzer, node->value);
    }
    for (int i = 0; i < node->child_count; i++) {
        analyze(analyzer, node->children[i]);
    }
}

void check_precision(SemanticAnalyzer* analyzer, double value) {
    if (!is_within_precision(value)) {
        if (analyzer->issue_count == analyzer->issue_capacity) {
            analyzer->issue_capacity *= 2;
            analyzer->found_issues = (double*)realloc(analyzer->found_issues, analyzer->issue_capacity * sizeof(double));
        }
        analyzer->found_issues[analyzer->issue_count++] = value;
    }
}

int is_within_precision(double value) {
    return fabs(value - round(value)) < 1e-07;
}

Program* create_program() {
    Program* program = (Program*)malloc(sizeof(Program));
    program->tree = create_syntax_tree(0.0);
    program->analyzer = create_semantic_analyzer();
    return program;
}

void build_tree(Program* program, double* data, int length) {
    void recurse(double* data, int length, SyntaxTree* parent) {
        for (int i = 0; i < length; i++) {
            SyntaxTree* node = create_syntax_tree(data[i]);
            add_child(parent, node);
            if (i + 1 < length) {
                recurse(&data[i + 1], length - i - 1, node);
            }
        }
    }
    recurse(data, length, program->tree);
}

void analyze_tree(Program* program) {
    analyze(program->analyzer, program->tree);
}

void report_issues(Program* program) {
    if (program->analyzer->issue_count > 0) {
        for (int i = 0; i < program->analyzer->issue_count; i++) {
            printf("%f\n", program->analyzer->found_issues[i]);
        }
    } else {
        printf("No precision issues found.\n");
    }
}

void main_program() {
    double data[] = {1.000001, 2.000002, 3.000003, 4.000004, 5.000005};
    Program* program = create_program();
    build_tree(program, data, 5);
    analyze_tree(program);
    report_issues(program);
    free(program);
}

int main() {
    main_program();
    return 0;
}