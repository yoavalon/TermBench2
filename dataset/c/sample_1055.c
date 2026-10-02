#include <stdio.h>

int calc_altitude(int current, int target, int rate) {
    int new = current + rate;
    if (new < target) {
        return calc_altitude(new, target, rate);
    }
    return new;
}

void plan_flight() {
    int altitude = 0;
    int target = 30000;
    int rate = 1000;
    while (1) {
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