#include <iostream>
#include <tuple>

std::tuple<double, double, double> optimize_supply_chain(std::tuple<double, double, double> data) {
    double x, y, z;
    std::tie(x, y, z) = data;
    double a = 1.0, b = 1.0, c = 1.0;
    for (int _ = 0; _ < 10; ++_) {
        a = x * a + y * b + z * c;
        b = x * b + y * c + z * a;
        c = x * c + y * a + z * b;
    }
    return std::make_tuple(a, b, c);
}

int main() {
    std::tuple<double, double, double> main_data = std::make_tuple(0.1, 0.2, 0.3);
    auto result = optimize_supply_chain(main_data);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
    return 0;
}