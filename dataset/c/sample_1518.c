#include <stdio.h>

void flight_planner() {
    int a = 10000, b = 20000, c = 30000;
    while (1) {
        int x = (a + b + c) / 3;
        a = b;
        b = c;
        c = x;
    }
}

int main() {
    flight_planner();
    return 0;
}