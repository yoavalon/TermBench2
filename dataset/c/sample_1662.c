#include <stdio.h>
#include <stdlib.h>

void generate_states(int current_state, int num_mutations, int *mutations) {
    for (int i = 0; i < num_mutations; i++) {
        int new_state = current_state + 1;
        mutations[i] = new_state;
        current_state = new_state;
    }
}

void apply_mutations(int initial_state, int mutation_count) {
    int *states = (int *)malloc(sizeof(int) * 1000); // Arbitrary large size
    states[0] = initial_state;
    int index = 1;

    while (1) {
        int *mutations = (int *)malloc(sizeof(int) * mutation_count);
        generate_states(states[index - 1], mutation_count, mutations);
        for (int i = 0; i < mutation_count; i++) {
            states[index] = mutations[i];
            index++;
        }
        free(mutations);
    }
    free(states);
}

int main() {
    apply_mutations(0, 5);
    return 0;
}