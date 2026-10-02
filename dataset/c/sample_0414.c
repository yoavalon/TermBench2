#include <stdio.h>

int calculate_cruise_altitude(int speed, int weight, int temperature) {
    int base_altitude = 30000;
    float speed_factor = (float)speed / 900;
    float weight_factor = (float)weight / 100000;
    float temp_factor = (20 - temperature) / 10;
    return base_altitude + (int)(speed_factor * 5000) - (int)(weight_factor * 3000) + (int)(temp_factor * 2000);
}

void simulate_flight(int speed, int weight, int temperature) {
    while (1) {
        int altitude = calculate_cruise_altitude(speed, weight, temperature);
        printf("Current Altitude: %d feet\n", altitude);
        speed += 10;
        weight -= 500;
    }
}

int main() {
    simulate_flight(850, 200000, 15);
    return 0;
}