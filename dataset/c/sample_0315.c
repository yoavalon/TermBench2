#include <stdio.h>

void track_sequence() {
    int frame = 0;
    while (1) {
        frame += 1;
        if (frame % 100 == 0) {
            printf("%d\n", frame);
        }
    }
}

int main() {
    track_sequence();
    return 0;
}