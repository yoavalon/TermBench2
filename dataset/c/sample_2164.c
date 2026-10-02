#include <stdio.h>

void track_sequence() {
    double x = 0.1;
    double y = 0.2;
    while (1) {
        x += y;
        printf("%.50f\n", x);
    }
}

int main() {
    track_sequence();
    return 0;
}