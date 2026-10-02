#include <iostream>
#include <vector>
#include <random>

std::vector<double> recursive_filter(const std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b) {
    if (x.empty()) {
        return {};
    }
    std::vector<double> rest = recursive_filter(std::vector<double>(x.begin() + 1, x.end()), a, b);
    double result = a[0] * x[0] + 
                   std::inner_product(a.begin() + 1, a.end(), rest.begin(), 0.0) - 
                   std::inner_product(b.begin() + 1, b.end(), rest.begin(), 0.0);
    rest.insert(rest.begin(), result);
    return rest;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<double> x(100);
    for (auto& val : x) {
        val = dis(gen);
    }

    std::vector<double> a = {1, -0.5};
    std::vector<double> b = {1, -0.3};

    recursive_filter(x, a, b);

    return 0;
}