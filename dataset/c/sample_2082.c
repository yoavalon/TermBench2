#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double** weights;
    double** bias;
} Layer;

Layer* create_layer(int input_size, int output_size) {
    Layer* layer = (Layer*)malloc(sizeof(Layer));
    layer->weights = (double**)malloc(input_size * sizeof(double*));
    layer->bias = (double**)malloc(1 * sizeof(double*));
    for (int i = 0; i < input_size; i++) {
        layer->weights[i] = (double*)malloc(output_size * sizeof(double));
        for (int j = 0; j < output_size; j++) {
            layer->weights[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    for (int j = 0; j < output_size; j++) {
        layer->bias[0][j] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    return layer;
}

void free_layer(Layer* layer, int input_size) {
    for (int i = 0; i < input_size; i++) {
        free(layer->weights[i]);
    }
    free(layer->weights);
    free(layer->bias);
    free(layer);
}

double** forward(Layer* layer, double** x, int batch_size, int input_size, int output_size) {
    double** z = (double**)malloc(batch_size * sizeof(double*));
    for (int i = 0; i < batch_size; i++) {
        z[i] = (double*)malloc(output_size * sizeof(double));
        for (int j = 0; j < output_size; j++) {
            z[i][j] = 0;
            for (int k = 0; k < input_size; k++) {
                z[i][j] += x[i][k] * layer->weights[k][j];
            }
            z[i][j] += layer->bias[0][j];
        }
    }
    return z;
}

double relu(double x) {
    return x > 0 ? x : 0;
}

double** relu_activation(double** z, int batch_size, int output_size) {
    for (int i = 0; i < batch_size; i++) {
        for (int j = 0; j < output_size; j++) {
            z[i][j] = relu(z[i][j]);
        }
    }
    return z;
}

double** softmax(double** z, int batch_size, int output_size) {
    double** exp_z = (double**)malloc(batch_size * sizeof(double*));
    double** sum_exp_z = (double**)malloc(batch_size * sizeof(double*));
    for (int i = 0; i < batch_size; i++) {
        exp_z[i] = (double*)malloc(output_size * sizeof(double));
        sum_exp_z[i] = (double*)malloc(1 * sizeof(double));
        double max_z = z[i][0];
        for (int j = 1; j < output_size; j++) {
            if (z[i][j] > max_z) {
                max_z = z[i][j];
            }
        }
        sum_exp_z[i][0] = 0;
        for (int j = 0; j < output_size; j++) {
            exp_z[i][j] = exp(z[i][j] - max_z);
            sum_exp_z[i][0] += exp_z[i][j];
        }
        for (int j = 0; j < output_size; j++) {
            exp_z[i][j] /= sum_exp_z[i][0];
        }
    }
    free(sum_exp_z);
    return exp_z;
}

double** neural_network_forward_pass(double** input_data, Layer** layers, int batch_size, int input_size, int hidden_size, int output_size) {
    double** a = input_data;
    a = forward(layers[0], a, batch_size, input_size, hidden_size);
    a = relu_activation(a, batch_size, hidden_size);
    a = forward(layers[1], a, batch_size, hidden_size, output_size);
    a = relu_activation(a, batch_size, output_size);
    a = softmax(a, batch_size, output_size);
    return a;
}

double** generate_data(int batch_size, int input_size) {
    double** data = (double**)malloc(batch_size * sizeof(double*));
    for (int i = 0; i < batch_size; i++) {
        data[i] = (double*)malloc(input_size * sizeof(double));
        for (int j = 0; j < input_size; j++) {
            data[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    return data;
}

void free_data(double** data, int batch_size) {
    for (int i = 0; i < batch_size; i++) {
        free(data[i]);
    }
    free(data);
}

void print_output(double** output, int batch_size, int output_size) {
    for (int i = 0; i < batch_size; i++) {
        for (int j = 0; j < output_size; j++) {
            printf("%f ", output[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int input_size = 784;
    int hidden_size = 256;
    int output_size = 10;
    int batch_size = 64;
    Layer** layers = (Layer**)malloc(2 * sizeof(Layer*));
    layers[0] = create_layer(input_size, hidden_size);
    layers[1] = create_layer(hidden_size, output_size);
    double** input_data = generate_data(batch_size, input_size);
    double** output = neural_network_forward_pass(input_data, layers, batch_size, input_size, hidden_size, output_size);
    print_output(output, batch_size, output_size);
    free_data(input_data, batch_size);
    free_data(output, batch_size);
    free_layer(layers[0], input_size);
    free_layer(layers[1], hidden_size);
    free(layers);
    return 0;
}