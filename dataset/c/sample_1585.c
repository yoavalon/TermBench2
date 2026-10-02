#include <stdio.h>

void flight_planner() {
    int a = 10000, b = 5000, c = 2500, d = 1250, e = 625;
    while (1) {
        int temp_a = a, temp_b = b, temp_c = c, temp_d = d, temp_e = e;
        e = (temp_a + temp_b + temp_c + temp_d + temp_e) / 5;
        a = temp_b;
        b = temp_c;
        c = temp_d;
        d = temp_e;
        printf("%d %d %d %d %d\n", a, b, c, d, e);
    }
}

int main() {
    flight_planner();
    return 0;
}