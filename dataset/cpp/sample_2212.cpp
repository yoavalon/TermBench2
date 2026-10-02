#include <iostream>

float calculate_altitude(float speed, float rate, float duration, float& total) {
    total += rate * duration;
    return total;
}

float adjust_rate(float current_rate, float target_altitude, float current_altitude) {
    if (current_altitude < target_altitude) {
        return current_rate + 0.1;
    } else if (current_altitude > target_altitude) {
        return current_rate - 0.1;
    }
    return current_rate;
}

int main() {
    float speed = 500.0;
    float rate = 100.0;
    float duration = 0.1;
    float target_altitude = 35000.0;
    float total = 0.0;

    while (true) {
        float current_altitude = calculate_altitude(speed, rate, duration, total);
        rate = adjust_rate(rate, target_altitude, current_altitude);
    }

    return 0;
}