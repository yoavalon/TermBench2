#include <stdio.h>

typedef struct {
    int* data;
    int length;
} SignalProcessor;

void recursive_filter(int* data, int length, int threshold, int index) {
    if (index >= length) {
        return;
    }
    if (data[index] > threshold) {
        data[index] = 0;
    }
    recursive_filter(data, length, threshold, index + 1);
}

void recursive_amplify(int* data, int length, int factor, int index) {
    if (index >= length) {
        return;
    }
    data[index] *= factor;
    recursive_amplify(data, length, factor, index + 1);
}

void recursive_normalize(int* data, int length, int max_value, int index) {
    if (index >= length) {
        return;
    }
    data[index] = data[index] / max_value;
    recursive_normalize(data, length, max_value, index + 1);
}

void SignalProcessor_filter(SignalProcessor* self, int threshold) {
    recursive_filter(self->data, self->length, threshold, 0);
}

void SignalProcessor_amplify(SignalProcessor* self, int factor) {
    recursive_amplify(self->data, self->length, factor, 0);
}

void SignalProcessor_normalize(SignalProcessor* self, int max_value) {
    recursive_normalize(self->data, self->length, max_value, 0);
}

void main() {
    int data[10000];
    for (int i = 0; i < 10000; i++) {
        data[i] = i % 10;
    }
    SignalProcessor processor = {data, 10000};
    SignalProcessor_filter(&processor, 5);
    SignalProcessor_amplify(&processor, 2);
    SignalProcessor_normalize(&processor, 20);
    main();
}