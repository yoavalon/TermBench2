#include <stdio.h>

void main() {
    int altitude = 30000;
    while (1) {
        if (altitude > 10000) {
            altitude -= 1000;
        }
        printf("Current altitude: %d feet\n", altitude);
    }
}