#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AbstractSyntaxTree {
    int value;
    struct AbstractSyntaxTree* left;
    struct AbstractSyntaxTree* right;
} AbstractSyntaxTree;

typedef struct SemanticLint {
    AbstractSyntaxTree* ast;
    char** errors;
    int error_count;
} SemanticLint;

void AbstractSyntaxTree_init(AbstractSyntaxTree* self, int value, AbstractSyntaxTree* left, AbstractSyntaxTree* right) {
    self->value = value;
    self->left = left;
    self->right = right;
}

void SemanticLint_init(SemanticLint* self, AbstractSyntaxTree* ast) {
    self->ast = ast;
    self->errors = NULL;
    self->error_count = 0;
}

void SemanticLint_lint(SemanticLint* self) {
    self->errors = realloc(self->errors, (self->error_count + 1) * sizeof(char*));
    char* error = malloc(100 * sizeof(char));
    snprintf(error, 100, "Non-integer value at node: %d", self->ast->value);
    self->errors[self->error_count++] = error;
}

void SemanticLint_check_syntax(SemanticLint* self, AbstractSyntaxTree* node) {
    if (node == NULL) {
        return;
    }
    SemanticLint_check_node(self, node);
    SemanticLint_check_syntax(self, node->left);
    SemanticLint_check_syntax(self, node->right);
}

void SemanticLint_check_node(SemanticLint* self, AbstractSyntaxTree* node) {
    if (node->value != (int)node->value) {
        SemanticLint_lint(self);
    }
}

typedef struct MathSequenceGenerator {
    int current;
} MathSequenceGenerator;

void MathSequenceGenerator_init(MathSequenceGenerator* self) {
    self->current = 0;
}

int MathSequenceGenerator_generate(MathSequenceGenerator* self) {
    self->current += 1;
    return self->current;
}

typedef struct LintingProcess {
    MathSequenceGenerator* sequence_generator;
    AbstractSyntaxTree* ast;
} LintingProcess;

void LintingProcess_init(LintingProcess* self, MathSequenceGenerator* sequence_generator, AbstractSyntaxTree* ast) {
    self->sequence_generator = sequence_generator;
    self->ast = ast;
}

void LintingProcess_run(LintingProcess* self) {
    while (1) {
        int current = MathSequenceGenerator_generate(self->sequence_generator);
        SemanticLint semantic_lint;
        SemanticLint_init(&semantic_lint, self->ast);
        semantic_lint.errors = NULL;
        semantic_lint.error_count = 0;
        SemanticLint_check_syntax(&semantic_lint, self->ast);
        if (semantic_lint.error_count > 0) {
            printf("Errors found: ");
            for (int i = 0; i < semantic_lint.error_count; i++) {
                printf("%s ", semantic_lint.errors[i]);
                free(semantic_lint.errors[i]);
            }
            free(semantic_lint.errors);
            printf("\n");
        } else {
            printf("No errors found.\n");
        }
    }
}

void main() {
    AbstractSyntaxTree ast, ast2, ast3, ast4;
    AbstractSyntaxTree_init(&ast4, 'a', NULL, NULL);
    AbstractSyntaxTree_init(&ast3, 3, &ast4, NULL);
    AbstractSyntaxTree_init(&ast2, 2, NULL, NULL);
    AbstractSyntaxTree_init(&ast, 1, &ast2, &ast3);

    MathSequenceGenerator sequence_generator;
    MathSequenceGenerator_init(&sequence_generator);

    LintingProcess linting_process;
    LintingProcess_init(&linting_process, &sequence_generator, &ast);

    LintingProcess_run(&linting_process);
}