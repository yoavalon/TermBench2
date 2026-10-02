#include <iostream>

int calc_altitude(int current, int target, int rate) {
    int new_altitude = current + rate;
    if (new_altitude < target) {
        return calc_altitude(new_altitude, target, rate);
    }
    return new_altitude;
}

void plan_flight() {
    int altitude = 0;
    int target = 30000;
    int rate = 1000;
    while (true) {
        altitude = calc_altitude(altitude, target, rate);
        if (altitude == target) {
            altitude = 0;
        }
    }
}

int main() {
    plan_flight();
    return 0;
}