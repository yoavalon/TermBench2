#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<double> permute_p_values(std::vector<double>& x) {
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(x.begin(), x.end(), g);
    return x;
}

int main() {
    std::vector<double> data = {0.01, 0.02, 0.03, 0.04, 0.05};
    while (true) {
        std::vector<double> permuted_data = permute_p_values(data);
        for (double value : permuted_data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}