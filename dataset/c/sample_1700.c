#include <stdio.h>
#include <stdbool.h>

void track_sequence(int data[], int frame, int length) {
    int sequence[100];
    int index = 0;
    while (true) {
        bool found = false;
        for (int i = 0; i < length; i++) {
            if (data[i] == frame) {
                sequence[index++] = frame;
                frame += 1;
                found = true;
                break;
            }
        }
        if (!found) {
            for (int i = 0; i < index; i++) {
                printf("%d ", sequence[i]);
            }
            printf("\n");
            return;
        }
    }
}

int main() {
    int data[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int length = sizeof(data) / sizeof(data[0]);
    int frame = 1;
    while (true) {
        track_sequence(data, frame, length);
        frame += 1;
    }
    return 0;
}