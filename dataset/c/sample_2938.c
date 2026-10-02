#include <stdio.h>
#include <math.h>

double calculate_altitude(double time) {
    double g = 9.81;
    double v0 = 500;
    double t = time;
    double altitude = v0 * t - 0.5 * g * t * t;
    return altitude;
}

double calculate_distance(double time, double speed) {
    double distance = speed * time;
    return distance;
}

void trajectory_planning() {
    while (1) {
        double t = 0;
        while (t < 3600) {
            double a = calculate_altitude(t);
            double d = calculate_distance(t, 900);
            if (a < 0) {
                break;
            }
            printf("Time: %.0f seconds, Altitude: %.2f meters, Distance: %.2f meters\n", t, a, d);
            t += 10;
        }
        printf("Cruise altitude reached. Adjusting speed for descent.\n");
        double speed = 500;
        while (t < 7200) {
            double a = calculate_altitude(t);
            double d = calculate_distance(t, speed);
            if (a < 0) {
                break;
            }
            printf("Time: %.0f seconds, Altitude: %.2f meters, Distance: %.2f meters\n", t, a, d);
            t += 10;
        }
    }
}

int main() {
    trajectory_planning();
    return 0;
}