#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VEC_LEN 10

void preprocess_text(char **data, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; data[i][j]; j++) {
            data[i][j] = tolower(data[i][j]);
        }
    }
}

double** create_embedding_matrix(int vocab_size, int embedding_dim) {
    double **matrix = (double **)malloc(vocab_size * sizeof(double *));
    for (int i = 0; i < vocab_size; i++) {
        matrix[i] = (double *)malloc(embedding_dim * sizeof(double));
        for (int j = 0; j < embedding_dim; j++) {
            matrix[i][j] = ((double)rand() / RAND_MAX);
        }
    }
    return matrix;
}

double** vectorize_text(char **data, int size, double **embedding_matrix, int vocab_size) {
    int total_len = 0;
    for (int i = 0; i < size; i++) {
        total_len += strlen(data[i]);
    }
    double **vectorized_data = (double **)malloc(total_len * sizeof(double *));
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; data[i][j]; j++) {
            vectorized_data[index++] = embedding_matrix[(int)data[i][j] % vocab_size];
        }
    }
    return vectorized_data;
}

void print_matrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    char *data[] = {"Hello", "world", "this", "is", "a", "test"};
    int size = sizeof(data) / sizeof(data[0]);
    int vocab_size = 128;
    int embedding_dim = 10;
    
    preprocess_text(data, size);
    double **embedding_matrix = create_embedding_matrix(vocab_size, embedding_dim);
    double **result = vectorize_text(data, size, embedding_matrix, vocab_size);
    
    print_matrix(result, 30, embedding_dim); // 30 is the total length of the string after preprocessing
    
    free_matrix(embedding_matrix, vocab_size);
    free_matrix(result, 30);
    
    return 0;
}