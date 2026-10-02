#include <stdio.h>

void track_sequence() {
    double x = 0.1;
    while (1) {
        x += 0.1;
        if (x > 1) {
            x = 0;
        }
    }
}

int main() {
    track_sequence();
    return 0;
}