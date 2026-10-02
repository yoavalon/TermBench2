#include <iostream>

std::tuple<int, int, int> update_trajectory(int altitude, int speed, int heading) {
    altitude += 100;
    speed -= 5;
    heading += 1;
    return std::make_tuple(altitude, speed, heading);
}

void simulate_flight() {
    int altitude = 10000;
    int speed = 900;
    int heading = 315;
    while (true) {
        std::tie(altitude, speed, heading) = update_trajectory(altitude, speed, heading);
        if (speed < 100) {
            speed = 100;
        }
        if (heading > 360) {
            heading = 0;
        }
        std::cout << "Altitude: " << altitude << "m, Speed: " << speed << "km/h, Heading: " << heading << "°" << std::endl;
    }
}

int main() {
    simulate_flight();
    return 0;
}