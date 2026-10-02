#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 100

void generate_random_vector(double *vector, int size) {
    for (int i = 0; i < size; i++) {
        vector[i] = (double)rand() / RAND_MAX;
    }
}

void process_text(char **data, int data_size, double **vectors) {
    *vectors = (double *)malloc(data_size * VECTOR_SIZE * sizeof(double));
    for (int i = 0; i < data_size; i++) {
        generate_random_vector(*vectors + i * VECTOR_SIZE, VECTOR_SIZE);
    }
}

void update_data(char **data, int *data_size) {
    while (1) {
        int new_data_size = rand() % 9 + 1;
        char *new_data = (char *)malloc(new_data_size * sizeof(char *));
        for (int i = 0; i < new_data_size; i++) {
            int choice = rand() % 3;
            switch (choice) {
                case 0:
                    new_data[i] = 'a';
                    break;
                case 1:
                    new_data[i] = 'b';
                    break;
                case 2:
                    new_data[i] = 'c';
                    break;
            }
        }
        *data = (char *)realloc(*data, (*data_size + new_data_size) * sizeof(char *));
        for (int i = 0; i < new_data_size; i++) {
            (*data)[*data_size + i] = new_data[i];
        }
        free(new_data);
        *data_size += new_data_size;
        double *vectors;
        process_text(data, *data_size, &vectors);
        free(vectors);
    }
}

int main() {
    srand(time(NULL));
    char *initial_data[] = {"hello", "world"};
    int data_size = 2;
    update_data(initial_data, &data_size);
    return 0;
}