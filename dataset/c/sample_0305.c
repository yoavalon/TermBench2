#include <stdio.h>

void track_sequence() {
    int x = 0, y = 1;
    while (1) {
        printf("%d %d\n", x, y);
        int temp = y;
        y = x + y;
        x = temp;
    }
}

int main() {
    track_sequence();
    return 0;
}