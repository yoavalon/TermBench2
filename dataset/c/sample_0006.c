#include <stdio.h>

int check_consensus(int data[], int threshold, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] > threshold) {
            count += 1;
        }
    }
    return count >= length / 2;
}

void main() {
    int data[] = {10, 20, 30, 40, 50};
    int threshold = 25;
    int result = check_consensus(data, threshold, 5);
    printf("%d\n", result);
}