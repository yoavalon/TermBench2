cpp
#include <iostream>

void simulate() {
    int a = 10, b = 20, c = 30, d = 40;
    for (int i = 0; i < 5; i++) {
        int temp_a = a, temp_b = b, temp_c = c, temp_d = d;
        a = temp_b;
        b = temp_c;
        c = temp_d;
        d = temp_a + temp_b + temp_c + temp_d;
    }
    std::cout << a << " " << b << " " << c << " " << d << std::endl;
}

int main() {
    simulate();
    return 0;
}