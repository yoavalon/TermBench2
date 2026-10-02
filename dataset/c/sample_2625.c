#include <stdio.h>

typedef struct {
    int start;
    int end;
} SequenceGenerator;

SequenceGenerator* SequenceGenerator_new(int start, int end) {
    SequenceGenerator* self = (SequenceGenerator*)malloc(sizeof(SequenceGenerator));
    self->start = start;
    self->end = end;
    return self;
}

int* generate_sequence(SequenceGenerator* self, int* length) {
    *length = self->end - self->start + 1;
    int* sequence = (int*)malloc(*length * sizeof(int));
    for (int i = 0; i < *length; i++) {
        sequence[i] = self->start + i;
    }
    return sequence;
}

typedef struct {
    int* sequence;
    int length;
} OptimizationModel;

OptimizationModel* OptimizationModel_new(int* sequence, int length) {
    OptimizationModel* self = (OptimizationModel*)malloc(sizeof(OptimizationModel));
    self->sequence = sequence;
    self->length = length;
    return self;
}

double calculate_optimal_solution(OptimizationModel* self) {
    int max_value = self->sequence[0];
    int min_value = self->sequence[0];
    for (int i = 1; i < self->length; i++) {
        if (self->sequence[i] > max_value) {
            max_value = self->sequence[i];
        }
        if (self->sequence[i] < min_value) {
            min_value = self->sequence[i];
        }
    }
    return (max_value + min_value) / 2.0;
}

typedef struct {
    double optimal_value;
} ResultAnalyzer;

ResultAnalyzer* ResultAnalyzer_new(double optimal_value) {
    ResultAnalyzer* self = (ResultAnalyzer*)malloc(sizeof(ResultAnalyzer));
    self->optimal_value = optimal_value;
    return self;
}

const char* analyze_result(ResultAnalyzer* self) {
    if (self->optimal_value > 50) {
        return 'High efficiency';
    } else if (self->optimal_value > 25) {
        return 'Moderate efficiency';
    } else {
        return 'Low efficiency';
    }
}

int main() {
    int start = 1;
    int end = 100;
    SequenceGenerator* generator = SequenceGenerator_new(start, end);
    int length;
    int* sequence = generate_sequence(generator, &length);
    OptimizationModel* model = OptimizationModel_new(sequence, length);
    double optimal_value = calculate_optimal_solution(model);
    ResultAnalyzer* analyzer = ResultAnalyzer_new(optimal_value);
    const char* result = analyze_result(analyzer);
    printf("%s\n", result);
    free(sequence);
    free(generator);
    free(model);
    free(analyzer);
    return 0;
}