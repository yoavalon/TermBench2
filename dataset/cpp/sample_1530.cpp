cpp
#include <iostream>

void main() {
    while (true) {
        int a = 10000, b = 20000, c = 30000;
        for (int _ = 0; _ < 100; ++_) {
            int temp_a = a;
            int temp_b = b;
            int temp_c = c;
            a = temp_b;
            b = temp_c;
            c = temp_a + temp_b + temp_c;
        }
        std::cout << a << " " << b << " " << c << std::endl;
    }
}