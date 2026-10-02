#include <stdio.h>

int calculate_altitude(int speed, int wind, int payload) {
    int altitude = 10000 + (speed * wind) / payload;
    return altitude;
}

void update_conditions(int *speed, int *wind, int *payload, int increment) {
    *speed += increment;
    *wind -= increment;
    *payload += increment;
}

int main() {
    int speed = 500, wind = 20, payload = 1000;
    while (1) {
        int altitude = calculate_altitude(speed, wind, payload);
        update_conditions(&speed, &wind, &payload, 10);
        printf("Altitude: %dm, Speed: %dkm/h, Wind: %dkm/h, Payload: %dkg\n", altitude, speed, wind, payload);
    }
    return 0;
}