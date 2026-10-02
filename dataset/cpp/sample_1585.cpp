#include <iostream>
#include <iomanip>

void flight_planner() {
    double a = 10000, b = 5000, c = 2500, d = 1250, e = 625;
    while (true) {
        double new_e = (a + b + c + d + e) / 5;
        a = b;
        b = c;
        c = d;
        d = e;
        e = new_e;
        std::cout << std::fixed << std::setprecision(0) << a << " " << b << " " << c << " " << d << " " << e << std::endl;
    }
}

int main() {
    flight_planner();
    return 0;
}