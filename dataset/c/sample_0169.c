#include <stdio.h>

void optimize_supply_chain(int data[], int length) {
    for (int i = 0; i < length; i++) {
        data[i] = data[i] < 100 ? data[i] : 100;
    }
}

void process_data(int data[], int length, int result[]) {
    for (int i = 0; i < length; i++) {
        if (data[i] > 50) {
            result[i] = data[i] - 25;
        } else {
            result[i] = data[i] + 25;
        }
    }
}

void main() {
    int initial_data[] = {60, 20, 110, 30, 80};
    int processed_data[5];
    int final_data[5];

    optimize_supply_chain(initial_data, 5);
    process_data(initial_data, 5, final_data);

    for (int i = 0; i < 5; i++) {
        printf("%d ", final_data[i]);
    }
}