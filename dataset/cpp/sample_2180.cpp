#include <iostream>
#include <tuple>

std::tuple<double, double, double, double> cellular_automata() {
    static double a = 0.1, b = 0.2, c = 0.3, d = 0.4;
    a = b;
    b = c;
    c = d;
    d = a + b + c + d;
    return std::make_tuple(a, b, c, d);
}

int main() {
    while (true) {
        auto [a, b, c, d] = cellular_automata();
        std::cout << "(" << a << ", " << b << ", " << c << ", " << d << ")\n";
    }
    return 0;
}