#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INPUT_SIZE 3
#define HIDDEN_SIZE 4
#define OUTPUT_SIZE 1

double randn() {
    return ((double)rand() / RAND_MAX - 0.5) * 2;
}

double** initialize_weights(int input_size, int hidden_size, int output_size) {
    double** w1 = (double**)malloc(input_size * sizeof(double*));
    double** w2 = (double**)malloc(hidden_size * sizeof(double*));
    
    for (int i = 0; i < input_size; i++) {
        w1[i] = (double*)malloc(hidden_size * sizeof(double));
        for (int j = 0; j < hidden_size; j++) {
            w1[i][j] = randn();
        }
    }
    
    for (int i = 0; i < hidden_size; i++) {
        w2[i] = (double*)malloc(output_size * sizeof(double));
        for (int j = 0; j < output_size; j++) {
            w2[i][j] = randn();
        }
    }
    
    double** weights = (double**)malloc(2 * sizeof(double*));
    weights[0] = (double*)w1;
    weights[1] = (double*)w2;
    return weights;
}

double** forward_pass(double* x, double** w1, double** w2, int input_size, int hidden_size, int output_size) {
    double* z1 = (double*)malloc(hidden_size * sizeof(double));
    double* a1 = (double*)malloc(hidden_size * sizeof(double));
    double* z2 = (double*)malloc(output_size * sizeof(double));
    
    for (int i = 0; i < hidden_size; i++) {
        z1[i] = 0;
        for (int j = 0; j < input_size; j++) {
            z1[i] += x[j] * w1[j][i];
        }
        a1[i] = tanh(z1[i]);
    }
    
    for (int i = 0; i < output_size; i++) {
        z2[i] = 0;
        for (int j = 0; j < hidden_size; j++) {
            z2[i] += a1[j] * w2[j][i];
        }
    }
    
    double** output = (double**)malloc(2 * sizeof(double*));
    output[0] = (double*)a1;
    output[1] = (double*)z2;
    return output;
}

int main() {
    srand(time(NULL));
    int input_size = INPUT_SIZE;
    int hidden_size = HIDDEN_SIZE;
    int output_size = OUTPUT_SIZE;
    
    double** weights = initialize_weights(input_size, hidden_size, output_size);
    double* x = (double*)malloc(input_size * sizeof(double));
    
    for (int i = 0; i < input_size; i++) {
        x[i] = randn();
    }
    
    double** output = forward_pass(x, weights[0], weights[1], input_size, hidden_size, output_size);
    printf("%f\n", output[1][0]);
    
    free(x);
    for (int i = 0; i < input_size; i++) {
        free(weights[0][i]);
    }
    for (int i = 0; i < hidden_size; i++) {
        free(weights[1][i]);
    }
    free(weights[0]);
    free(weights[1]);
    free(weights);
    free(output[0]);
    free(output[1]);
    free(output);
    
    return 0;
}