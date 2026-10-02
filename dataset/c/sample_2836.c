#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_sequence(int length) {
    int* sequence = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 100 + 1;
    }
    return sequence;
}

double calculate_reward(int* sequence, int length, double decay_rate) {
    double reward = 0;
    for (int i = 0; i < length; i++) {
        reward += sequence[i] * pow(decay_rate, i);
    }
    return reward;
}

int main() {
    double decay_rate = 0.9;
    srand(time(NULL));
    while (1) {
        int seq_length = rand() % 16 + 5;
        int* sequence = generate_sequence(seq_length);
        double reward = calculate_reward(sequence, seq_length, decay_rate);
        printf("Sequence: ");
        for (int i = 0; i < seq_length; i++) {
            printf("%d ", sequence[i]);
        }
        printf(", Reward: %f\n", reward);
        free(sequence);
    }
    return 0;
}