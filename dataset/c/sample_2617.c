#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int size;
    double* sequence;
} SequenceGenerator;

typedef struct {
    double discount_factor;
} RewardCalculator;

typedef struct {
    RewardCalculator* reward_calculator;
} SequenceAnalyzer;

SequenceGenerator* SequenceGenerator_init(int size) {
    SequenceGenerator* self = (SequenceGenerator*)malloc(sizeof(SequenceGenerator));
    self->size = size;
    self->sequence = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        self->sequence[i] = (double)rand() / RAND_MAX;
    }
    return self;
}

double* SequenceGenerator_generate(SequenceGenerator* self) {
    return self->sequence;
}

RewardCalculator* RewardCalculator_init(double discount_factor) {
    RewardCalculator* self = (RewardCalculator*)malloc(sizeof(RewardCalculator));
    self->discount_factor = discount_factor;
    return self;
}

double RewardCalculator_calculate(RewardCalculator* self, double* sequence, int size) {
    double reward = 0;
    for (int t = 0; t < size; t++) {
        reward += self->discount_factor * t * sequence[t];
    }
    return reward;
}

SequenceAnalyzer* SequenceAnalyzer_init(RewardCalculator* reward_calculator) {
    SequenceAnalyzer* self = (SequenceAnalyzer*)malloc(sizeof(SequenceAnalyzer));
    self->reward_calculator = reward_calculator;
    return self;
}

double SequenceAnalyzer_analyze(SequenceAnalyzer* self, double* sequence, int size) {
    return RewardCalculator_calculate(self->reward_calculator, sequence, size);
}

void main() {
    int size = 10;
    double discount_factor = 0.9;
    srand(time(NULL));
    SequenceGenerator* generator = SequenceGenerator_init(size);
    RewardCalculator* reward_calculator = RewardCalculator_init(discount_factor);
    SequenceAnalyzer* analyzer = SequenceAnalyzer_init(reward_calculator);
    double* sequence = SequenceGenerator_generate(generator);
    double reward = SequenceAnalyzer_analyze(analyzer, sequence, size);
    printf("Sequence: ");
    for (int i = 0; i < size; i++) {
        printf("%f ", sequence[i]);
    }
    printf("\n");
    printf("Reward: %f\n", reward);
    free(generator->sequence);
    free(generator);
    free(reward_calculator);
    free(analyzer);
}