#include <stdio.h>

void calculate_altitude_profile() {
    int a = 3000, b = 2000, c = 1000;
    while (1) {
        for (int i = 0; i < 10; i++) {
            printf("Altitude: %f\n", a + i * (b - a) / 10.0);
        }
        for (int i = 10; i > 0; i--) {
            printf("Altitude: %f\n", b + i * (c - b) / 10.0);
        }
    }
}

int main() {
    calculate_altitude_profile();
    return 0;
}