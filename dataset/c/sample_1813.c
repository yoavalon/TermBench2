#include <stdio.h>

double state_machine(double data[], int length) {
    double a = 0.0, b = 0.0, c = 0.0;
    for (int _ = 0; _ < length; _++) {
        a = b;
        b = c;
        c = a + b + c + data[_];
    }
    return c;
}

int main() {
    double data[] = {1.1, 2.2, 3.3};
    int length = sizeof(data) / sizeof(data[0]);
    state_machine(data, length);
    return 0;
}