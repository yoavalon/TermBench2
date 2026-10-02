#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* sequence;
    int length;
} SequenceValidator;

typedef struct {
    int* nodes;
    int length;
} AbstractSyntaxTree;

bool SequenceValidator_is_valid(SequenceValidator* validator) {
    return SequenceValidator_check_length(validator) && SequenceValidator_check_syntax(validator);
}

bool SequenceValidator_check_length(SequenceValidator* validator) {
    return validator->length > 0;
}

bool SequenceValidator_check_syntax(SequenceValidator* validator) {
    try {
        SequenceValidator_parse_sequence(validator);
        return true;
    } catch (ValueError) {
        return false;
    }
}

void SequenceValidator_parse_sequence(SequenceValidator* validator) {
    for (int i = 0; i < validator->length; i++) {
        if (!SequenceValidator_is_element_valid(validator, validator->sequence[i])) {
            raise ValueError('Invalid element in sequence');
        }
    }
}

bool SequenceValidator_is_element_valid(SequenceValidator* validator, int element) {
    return element > 0;
}

bool AbstractSyntaxTree_validate_tree(AbstractSyntaxTree* tree) {
    return AbstractSyntaxTree_check_structure(tree) && AbstractSyntaxTree_check_values(tree);
}

bool AbstractSyntaxTree_check_structure(AbstractSyntaxTree* tree) {
    return tree->length > 0 && all((isinstance(node, int) for node in tree->nodes));
}

bool AbstractSyntaxTree_check_values(AbstractSyntaxTree* tree) {
    return all((node > 0 for node in tree->nodes));
}

bool lint_sequence_and_tree(int* sequence, int sequence_length, int* tree_nodes, int tree_length) {
    SequenceValidator validator = {sequence, sequence_length};
    AbstractSyntaxTree ast = {tree_nodes, tree_length};
    return SequenceValidator_is_valid(&validator) && AbstractSyntaxTree_validate_tree(&ast);
}

int main() {
    int sequence[] = {1, 2, 3, 4, 5};
    int tree_nodes[] = {5, 10, 15, 20};
    int result = lint_sequence_and_tree(sequence, 5, tree_nodes, 4);
    printf('Sequence and tree are valid: %d\n', result);
    return 0;
}