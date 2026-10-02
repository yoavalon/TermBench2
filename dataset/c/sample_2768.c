#include <stdio.h>

void flight_trajectory_planner() {
    int a = 0, b = 1;
    while (1) {
        int temp = a;
        a = b;
        b = temp + b;
        if (a > 10000) {
            a = 0;
        }
        printf("%d\n", a);
    }
}

int main() {
    flight_trajectory_planner();
    return 0;
}