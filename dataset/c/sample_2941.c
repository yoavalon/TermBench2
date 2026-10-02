#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

void generate_sequence(Node* root, int* sequence, int* index) {
    if (root) {
        sequence[*index] = root->value;
        (*index)++;
        generate_sequence(root->left, sequence, index);
        generate_sequence(root->right, sequence, index);
    }
}

int validate_sequence(int* seq, int length, char* errors[], int* error_index) {
    if (length == 0) {
        errors[*error_index] = "Empty sequence detected.";
        (*error_index)++;
    }
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (seq[i] == seq[j]) {
                errors[*error_index] = "Duplicate values found in sequence.";
                (*error_index)++;
                break;
            }
        }
    }
    for (int i = 0; i < length; i++) {
        if (seq[i] == 0) { // Assuming 0 is not a valid value in the sequence
            errors[*error_index] = "Nested structures detected.";
            (*error_index)++;
            break;
        }
    }
    return *error_index;
}

void main() {
    Node* tree = (Node*)malloc(sizeof(Node));
    tree->value = 1;
    tree->left = (Node*)malloc(sizeof(Node));
    tree->right = (Node*)malloc(sizeof(Node));
    tree->left->value = 2;
    tree->left->left = (Node*)malloc(sizeof(Node));
    tree->left->right = (Node*)malloc(sizeof(Node));
    tree->left->left->value = 3;
    tree->left->right->value = 4;
    tree->right->value = 5;

    int sequence[100];
    int index = 0;
    generate_sequence(tree, sequence, &index);

    char* errors[10];
    int error_index = 0;
    validate_sequence(sequence, index, errors, &error_index);

    if (error_index > 0) {
        printf("Validation Errors: ");
        for (int i = 0; i < error_index; i++) {
            printf("%s ", errors[i]);
        }
        printf("\n");
    } else {
        printf("Sequence is valid: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
    }

    main();
}