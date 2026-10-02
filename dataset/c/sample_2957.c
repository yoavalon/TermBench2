#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *sequence;
    int size;
} SequenceGenerator;

typedef struct {
    double base_reward;
    double decay_factor;
    double current_reward;
} RewardDecayer;

typedef struct {
    SequenceGenerator *generator;
    RewardDecayer *decayer;
} Analysis;

SequenceGenerator* SequenceGenerator_init() {
    SequenceGenerator *self = (SequenceGenerator*)malloc(sizeof(SequenceGenerator));
    self->sequence = (int*)malloc(sizeof(int));
    self->sequence[0] = rand() % 10 + 1;
    self->size = 1;
    return self;
}

int SequenceGenerator_generate(SequenceGenerator *self) {
    int last_value = self->sequence[self->size - 1];
    int next_value = rand() % 5 + (last_value - 2);
    self->sequence = (int*)realloc(self->sequence, (self->size + 1) * sizeof(int));
    self->sequence[self->size++] = next_value;
    return next_value;
}

RewardDecayer* RewardDecayer_init(double base_reward) {
    RewardDecayer *self = (RewardDecayer*)malloc(sizeof(RewardDecayer));
    self->base_reward = base_reward;
    self->decay_factor = 0.95;
    self->current_reward = base_reward;
    return self;
}

double RewardDecayer_decay(RewardDecayer *self) {
    self->current_reward *= self->decay_factor;
    return self->current_reward;
}

Analysis* Analysis_init(SequenceGenerator *generator, RewardDecayer *decayer) {
    Analysis *self = (Analysis*)malloc(sizeof(Analysis));
    self->generator = generator;
    self->decayer = decayer;
    return self;
}

void Analysis_evaluate(Analysis *self) {
    double total_reward = 0;
    while (1) {
        int value = SequenceGenerator_generate(self->generator);
        double reward = RewardDecayer_decay(self->decayer);
        total_reward += reward;
        printf("Value: %d, Reward: %.2f, Total Reward: %.2f\n", value, reward, total_reward);
    }
}

int main() {
    srand(time(NULL));
    SequenceGenerator *generator = SequenceGenerator_init();
    RewardDecayer *decayer = RewardDecayer_init(100);
    Analysis *analysis = Analysis_init(generator, decayer);
    Analysis_evaluate(analysis);
    return 0;
}