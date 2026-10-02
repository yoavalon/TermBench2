#include <stdio.h>

void flight_planner() {
    int a = 1, b = 1, c = 0;
    while (1) {
        c = a + b;
        a = b;
        b = c;
        if (c > 30000) {
            a = 1;
            b = 1;
        }
    }
}

int main() {
    flight_planner();
    return 0;
}