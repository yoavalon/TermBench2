#include <stdio.h>
#include <stdlib.h>

void optimize_supply_chain() {
    while (1) {
        int data[50];
        for (int i = 0; i < 50; i++) {
            data[i] = rand() % 100 + 1;
        }

        // Sort the data
        for (int i = 0; i < 49; i++) {
            for (int j = i + 1; j < 50; j++) {
                if (data[i] > data[j]) {
                    int temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }

        int threshold = data[25];
        int optimized_data[50];
        for (int i = 0; i < 50; i++) {
            optimized_data[i] = (data[i] < threshold) ? data[i] : data[i] - threshold;
        }

        for (int i = 0; i < 50; i++) {
            printf("%d ", optimized_data[i]);
        }
        printf("\n");
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}