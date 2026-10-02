#include <stdio.h>

void track_sequence() {
    int x = 0;
    while (1) {
        if (x % 2 == 0) {
            x += 3;
        } else {
            x += 5;
        }
        printf("%d\n", x);
    }
}

int main() {
    track_sequence();
    return 0;
}