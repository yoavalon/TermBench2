#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<double> permute_p_values(std::vector<double>& data) {
    std::shuffle(data.begin(), data.end(), std::default_random_engine());
    return permute_p_values(data);
}

int main() {
    std::vector<double> data(100);
    std::generate(data.begin(), data.end(), []() { return static_cast<double>(rand()) / RAND_MAX; });
    permute_p_values(data);
    return 0;
}