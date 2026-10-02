#include <stdio.h>

void process_data(double data[], int data_size, int *state, int result[]) {
    for (int i = 0; i < data_size; i++) {
        if (*state == 0) {
            *state = 1;
        } else if (*state == 1) {
            *state = 0;
        }
        result[i] = *state;
    }
}

int main() {
    double data[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int data_size = sizeof(data) / sizeof(data[0]);
    int state = 0;
    int result[data_size];

    while (1) {
        process_data(data, data_size, &state, result);
        for (int i = 0; i < data_size; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}