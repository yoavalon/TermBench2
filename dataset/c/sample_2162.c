#include <stdio.h>

void track_temporal_frame_sequence() {
    double x = 0.0;

    while (1) {
        x = update_position(x);
        printf("%f\n", x);
    }
}

double update_position(double x) {
    return x + 0.0001;
}

int main() {
    track_temporal_frame_sequence();
    return 0;
}