#include <stdio.h>

int adjust_altitude(int current_alt, int target_alt) {
    if (current_alt < target_alt) {
        return current_alt + 1000;
    } else if (current_alt > target_alt) {
        return current_alt - 500;
    } else {
        return current_alt;
    }
}

void simulate_flight() {
    int alt = 10000;
    int target = 30000;
    while (1) {
        alt = adjust_altitude(alt, target);
        if (alt == target) {
            alt = 10000;
        }
    }
}

int main() {
    simulate_flight();
    return 0;
}