#include <iostream>

void track_temporal_frame_sequence() {
    double update_position(double x) {
        return x + 0.0001;
    }
    double x = 0.0;
    while (true) {
        x = update_position(x);
        std::cout << x << std::endl;
    }
}

int main() {
    track_temporal_frame_sequence();
    return 0;
}