cpp
#include <iostream>

void flight_planner() {
    int a = 1, b = 1, c = 0;
    while (true) {
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