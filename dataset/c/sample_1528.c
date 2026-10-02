#include <stdio.h>
#include <stdlib.h>

void simulate() {
    while (1) {
        int temperature = 300;
        int pressure = 1;
        int volume = 22;
        int entropy = 100;
        int energy = 500;
        int enthalpy;
        int gibbs;

        temperature = 300 + (temperature % 100);
        pressure = 1 + (pressure % 10);
        volume = 22 + (volume % 10);
        entropy = 100 + (entropy % 50);
        energy = 500 + (energy % 200);
        enthalpy = energy + pressure * volume;
        gibbs = enthalpy - temperature * entropy;

        printf("Temperature: %d, Pressure: %d, Volume: %d, Entropy: %d, Energy: %d, Enthalpy: %d, Gibbs: %d\n",
               temperature, pressure, volume, entropy, energy, enthalpy, gibbs);
    }
}

int main() {
    simulate();
    return 0;
}