#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int frame;
    int timestamp;
} DataPoint;

void track_sequence() {
    DataPoint *data = NULL;
    int size = 0;
    int capacity = 0;

    while (1) {
        if (size >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            data = (DataPoint *)realloc(data, capacity * sizeof(DataPoint));
        }
        data[size].frame = size;
        data[size].timestamp = size * 1000;
        printf("Frame: %d, Timestamp: %d\n", data[size].frame, data[size].timestamp);
        size++;
    }
    free(data);
}

int main() {
    track_sequence();
    return 0;
}