#include <iostream>
#include <cstdlib>
#include <ctime>

void simulate_state() {
    while (true) {
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;
        double z = x * y;
        if (z > 0.5) {
            continue;
        }
        std::cout << z << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    simulate_state();
    return 0;
}