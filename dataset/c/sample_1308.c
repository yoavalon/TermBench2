#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type[20];
    int index;
    int new_value;
} Mutation;

typedef struct {
    int *demand;
    int *supply;
} Data;

Mutation* optimize_inventory(Data data, int *num_mutations) {
    int len = 4; // Assuming fixed length for demand and supply
    Mutation *mutations = (Mutation *)malloc(len * sizeof(Mutation));
    *num_mutations = 0;

    for (int i = 0; i < len; i++) {
        if (data.demand[i] > data.supply[i]) {
            snprintf(mutations[*num_mutations].type, sizeof(mutations[*num_mutations].type), "adjust_supply");
            mutations[*num_mutations].index = i;
            mutations[*num_mutations].new_value = data.demand[i];
        } else {
            snprintf(mutations[*num_mutations].type, sizeof(mutations[*num_mutations].type), "reduce_demand");
            mutations[*num_mutations].index = i;
            mutations[*num_mutations].new_value = data.supply[i];
        }
        (*num_mutations)++;
    }
    return mutations;
}

Data apply_mutations(Data data, Mutation *mutations, int num_mutations) {
    for (int i = 0; i < num_mutations; i++) {
        if (strcmp(mutations[i].type, "adjust_supply") == 0) {
            data.supply[mutations[i].index] = mutations[i].new_value;
        } else if (strcmp(mutations[i].type, "reduce_demand") == 0) {
            data.demand[mutations[i].index] = mutations[i].new_value;
        }
    }
    return data;
}

void main() {
    Data initial_data = {{100, 200, 150, 300}, {120, 180, 160, 310}};
    int num_mutations;
    Mutation *mutations = optimize_inventory(initial_data, &num_mutations);
    Data final_data = apply_mutations(initial_data, mutations, num_mutations);

    printf("Final Data: {");
    printf("demand: [");
    for (int i = 0; i < 4; i++) {
        printf("%d", final_data.demand[i]);
        if (i < 3) printf(", ");
    }
    printf("], ");
    printf("supply: [");
    for (int i = 0; i < 4; i++) {
        printf("%d", final_data.supply[i]);
        if (i < 3) printf(", ");
    }
    printf("]}\n");

    free(mutations);
}