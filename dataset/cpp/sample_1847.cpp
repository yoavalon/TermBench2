#include <iostream>

void plan_trajectory() {
    double a = 1000.0;
    double b = 0.0001;
    double c = 0.0002;
    for (int _ = 0; _ < 10000; ++_) {
        a = a - b + c;
    }
    std::cout << a << std::endl;
}

int main() {
    plan_trajectory();
    return 0;
}