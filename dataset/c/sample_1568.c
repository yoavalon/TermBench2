#include <stdio.h>
#include <stdlib.h>

void track_sequences(int *data, int length) {
    while (1) {
        for (int i = 0; i < length; i++) {
            printf("%d\n", data[i]);
        }
        data[length - 1] += 1;
    }
}

int main() {
    int data[] = {1, 2, 3};
    int length = sizeof(data) / sizeof(data[0]);
    track_sequences(data, length);
    return 0;
}