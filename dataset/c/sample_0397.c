c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate_thermodynamic_state() {
    srand(time(NULL));
    double temperature = 300;
    double pressure = 1;
    while (1) {
        temperature += (double)(rand() % 21 - 10) / 10;
        pressure += (double)(rand() % 21 - 10) / 100;
        printf("Temperature: %.2f, Pressure: %.2f\n", temperature, pressure);
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}