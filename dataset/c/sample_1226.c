#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mutate_data(int *data, int len, int n) {
    for (int i = 0; i < n; i++) {
        int temp[len];
        for (int j = 0; j < len; j++) {
            int sum = 0;
            int count = 0;
            for (int k = -1; k <= 1; k++) {
                int index = j + k;
                if (index >= 0 && index < len) {
                    sum += data[index];
                    count++;
                }
            }
            temp[j] = sum / count;
        }
        for (int j = 0; j < len; j++) {
            data[j] = temp[j];
        }
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int len = sizeof(data) / sizeof(data[0]);
    mutate_data(data, len, 5);
    for (int i = 0; i < len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}