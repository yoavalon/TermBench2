#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RAND_MAX 32767

double randn() {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

void initialize_weights(double **w1, double **w2, int input_size, int hidden_size, int output_size) {
    *w1 = (double *)malloc(input_size * hidden_size * sizeof(double));
    *w2 = (double *)malloc(hidden_size * output_size * sizeof(double));
    for (int i = 0; i < input_size * hidden_size; i++) {
        (*w1)[i] = randn() * sqrt(2.0 / input_size);
    }
    for (int i = 0; i < hidden_size * output_size; i++) {
        (*w2)[i] = randn() * sqrt(2.0 / hidden_size);
    }
}

void forward_pass(double *x, double *w1, double *w2, double *z2, int input_size, int hidden_size, int output_size) {
    double *z1 = (double *)malloc(hidden_size * sizeof(double));
    double *a1 = (double *)malloc(hidden_size * sizeof(double));
    for (int i = 0; i < hidden_size; i++) {
        z1[i] = 0.0;
        for (int j = 0; j < input_size; j++) {
            z1[i] += x[j] * w1[i * input_size + j];
        }
        a1[i] = fmax(0.0, z1[i]);
    }
    for (int i = 0; i < output_size; i++) {
        z2[i] = 0.0;
        for (int j = 0; j < hidden_size; j++) {
            z2[i] += a1[j] * w2[i * hidden_size + j];
        }
    }
    free(z1);
    free(a1);
}

double compute_loss(double *y_pred, double *y_true, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += (y_pred[i] - y_true[i]) * (y_pred[i] - y_true[i]);
    }
    return sum / size;
}

void train(double *x, double *y, int epochs, int input_size, int hidden_size, int output_size) {
    double *w1, *w2;
    initialize_weights(&w1, &w2, input_size, hidden_size, output_size);
    double learning_rate = 0.01;
    double *grad_z2 = (double *)malloc(output_size * sizeof(double));
    double *grad_w2 = (double *)malloc(hidden_size * output_size * sizeof(double));
    double *grad_z1 = (double *)malloc(hidden_size * sizeof(double));
    double *grad_w1 = (double *)malloc(input_size * hidden_size * sizeof(double));
    double *y_pred = (double *)malloc(output_size * sizeof(double));

    for (int epoch = 0; epoch < epochs; epoch++) {
        forward_pass(x, w1, w2, y_pred, input_size, hidden_size, output_size);
        double loss = compute_loss(y_pred, y, output_size);
        if (epoch % 1000 == 0) {
            printf("%f\n", loss);
        }
        for (int i = 0; i < output_size; i++) {
            grad_z2[i] = 2.0 * (y_pred[i] - y[i]) / output_size;
        }
        for (int i = 0; i < hidden_size * output_size; i++) {
            int h = i / output_size;
            int o = i % output_size;
            grad_w2[i] = 0.0;
            for (int j = 0; j < output_size; j++) {
                grad_w2[i] += a1[h] * grad_z2[j];
            }
        }
        for (int i = 0; i < hidden_size; i++) {
            grad_z1[i] = 0.0;
            for (int j = 0; j < output_size; j++) {
                grad_z1[i] += grad_z2[j] * w2[j * hidden_size + i];
            }
            grad_z1[i] *= (a1[i] > 0.0);
        }
        for (int i = 0; i < input_size * hidden_size; i++) {
            int h = i / input_size;
            int i_ = i % input_size;
            grad_w1[i] = 0.0;
            for (int j = 0; j < hidden_size; j++) {
                grad_w1[i] += x[i_] * grad_z1[j];
            }
        }
        for (int i = 0; i < hidden_size * output_size; i++) {
            w2[i] -= learning_rate * grad_w2[i];
        }
        for (int i = 0; i < input_size * hidden_size; i++) {
            w1[i] -= learning_rate * grad_w1[i];
        }
    }
    free(w1);
    free(w2);
    free(grad_z2);
    free(grad_w2);
    free(grad_z1);
    free(grad_w1);
    free(y_pred);
}

int main() {
    int input_size = 10;
    int hidden_size = 20;
    int output_size = 1;
    int epochs = 5000;
    double *x = (double *)malloc(100 * input_size * sizeof(double));
    double *y = (double *)malloc(100 * output_size * sizeof(double));
    for (int i = 0; i < 100 * input_size; i++) {
        x[i] = randn();
    }
    for (int i = 0; i < 100 * output_size; i++) {
        y[i] = randn();
    }
    train(x, y, epochs, input_size, hidden_size, output_size);
    free(x);
    free(y);
    return 0;
}