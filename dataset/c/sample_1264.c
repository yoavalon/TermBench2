#include <stdio.h>

void flight_planner() {
    int data[] = {5000, 6000, 7000, 8000, 9000};
    int index = 0;
    while (index < 5) {
        if (data[index] > 7500) {
            data[index] -= 500;
        }
        index += 1;
    }
}

int main() {
    flight_planner();
    return 0;
}