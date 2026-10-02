#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int stop;
} SequenceGenerator;

typedef struct {
    int *sequence;
    int length;
} SemanticValidator;

typedef struct {
    int *sequence;
    int length;
    int is_valid;
} ResultFormatter;

void SequenceGenerator_init(SequenceGenerator *self, int start, int stop) {
    self->start = start;
    self->stop = stop;
}

int* SequenceGenerator_generate_sequence(SequenceGenerator *self, int *length) {
    int size = self->stop - self->start + 1;
    int *sequence = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        sequence[i] = self->start + i;
    }
    *length = size;
    return sequence;
}

void SemanticValidator_init(SemanticValidator *self, int *sequence, int length) {
    self->sequence = sequence;
    self->length = length;
}

int SemanticValidator_validate(SemanticValidator *self) {
    for (int i = 0; i < self->length - 1; i++) {
        if (self->sequence[i] + 1 != self->sequence[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void ResultFormatter_init(ResultFormatter *self, int *sequence, int length, int is_valid) {
    self->sequence = sequence;
    self->length = length;
    self->is_valid = is_valid;
}

char* ResultFormatter_format(ResultFormatter *self) {
    static char result[100];
    char status[10] = "valid";
    if (!self->is_valid) {
        snprintf(status, sizeof(status), "invalid");
    }
    snprintf(result, sizeof(result), "Sequence: ");
    for (int i = 0; i < self->length; i++) {
        snprintf(result + strlen(result), sizeof(result) - strlen(result), "%d ", self->sequence[i]);
    }
    snprintf(result + strlen(result), sizeof(result) - strlen(result), "- Status: %s", status);
    return result;
}

void main() {
    int start = 1;
    int stop = 10;
    SequenceGenerator generator;
    SequenceGenerator_init(&generator, start, stop);
    int length;
    int *sequence = SequenceGenerator_generate_sequence(&generator, &length);
    SemanticValidator validator;
    SemanticValidator_init(&validator, sequence, length);
    int is_valid = SemanticValidator_validate(&validator);
    ResultFormatter formatter;
    ResultFormatter_init(&formatter, sequence, length, is_valid);
    printf("%s\n", ResultFormatter_format(&formatter));
    free(sequence);
}

int main() {
    main();
    return 0;
}