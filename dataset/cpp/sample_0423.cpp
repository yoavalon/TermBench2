#include <iostream>

int calculate_altitude(int speed, int climb_rate) {
    int altitude = 0;
    while (true) {
        altitude += climb_rate;
        if (altitude > 30000) {
            return altitude;
        }
    }
}

int adjust_speed(int current_speed, int target_speed) {
    if (current_speed < target_speed) {
        return current_speed + 100;
    } else if (current_speed > target_speed) {
        return current_speed - 100;
    }
    return current_speed;
}

int main() {
    int speed = 250;
    int target_speed = 350;
    int altitude = 0;
    while (true) {
        speed = adjust_speed(speed, target_speed);
        altitude = calculate_altitude(speed, 1000);
        std::cout << "Speed: " << speed << ", Altitude: " << altitude << std::endl;
    }
    return 0;
}