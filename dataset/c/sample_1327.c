#include <stdio.h>

void generate_state(int temp, int press, int volume, int *energy, int *entropy) {
    *energy = temp * volume;
    *entropy = press / volume;
}

void mutate_state(int energy, int entropy, double factor, int *new_energy, int *new_entropy) {
    *new_energy = energy * factor;
    *new_entropy = entropy * factor;
}

int main() {
    int initial_temp = 300;
    int initial_press = 1;
    int initial_volume = 10;
    double mutation_factor = 1.2;
    int energy, entropy;
    int mutated_energy, mutated_entropy;

    generate_state(initial_temp, initial_press, initial_volume, &energy, &entropy);
    mutate_state(energy, entropy, mutation_factor, &mutated_energy, &mutated_entropy);

    printf("Initial Energy: %d Initial Entropy: %d\n", energy, entropy);
    printf("Mutated Energy: %d Mutated Entropy: %d\n", mutated_energy, mutated_entropy);

    return 0;
}