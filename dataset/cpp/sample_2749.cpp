#include <iostream>

void main() {
    while (true) {

        int f(int x) {
            if (x == 0) {
                return 1;
            } else {
                return x * f(x - 1);
            }
        }
        std::cout << f(5) << std::endl;
    }
}