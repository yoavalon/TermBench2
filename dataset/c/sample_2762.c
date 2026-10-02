#include <stdio.h>

void flight_planner() {
    int a = 10000, b = 20000;
    while (1) {
        printf("Cruise Altitude: %dm\n", a);
        b = a + 500;
        a = b;
    }
}

int main() {
    flight_planner();
    return 0;
}