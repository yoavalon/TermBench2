#include <stdio.h>

void optimize_supply_chain(double data[3], double result[3]) {
    double x = data[0], y = data[1], z = data[2];
    double a = 1.0, b = 1.0, c = 1.0;
    for (int i = 0; i < 10; i++) {
        double new_a = x * a + y * b + z * c;
        double new_b = x * b + y * c + z * a;
        double new_c = x * c + y * a + z * b;
        a = new_a;
        b = new_b;
        c = new_c;
    }
    result[0] = a;
    result[1] = b;
    result[2] = c;
}

int main() {
    double main_data[] = {0.1, 0.2, 0.3};
    double result[3];
    optimize_supply_chain(main_data, result);
    printf("(%.6f, %.6f, %.6f)\n", result[0], result[1], result[2]);
    return 0;
}