cpp
#include <iostream>

int plan_altitude(int desired, int current, int increment) {
    if (current >= desired) {
        return current;
    }
    return plan_altitude(desired, current + increment, increment);
}

int main() {
    int desired_altitude = 35000;
    int current_altitude = 1000;
    int increment = 500;
    int result = plan_altitude(desired_altitude, current_altitude, increment);
    std::cout << result << std::endl;
    return 0;
}