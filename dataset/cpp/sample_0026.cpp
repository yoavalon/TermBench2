#include <iostream>
#include <vector>

std::vector<double> boundary_conditions(std::vector<double> x, std::vector<double> lb, std::vector<double> ub) {
    for (size_t i = 0; i < x.size(); ++i) {
        if (x[i] < lb[i]) {
            x[i] = lb[i];
        } else if (x[i] > ub[i]) {
            x[i] = ub[i];
        }
    }
    return x;
}

void main() {
    std::vector<double> x = {1.5, -2.0, 3.0};
    std::vector<double> lb = {0.0, -1.0, 2.0};
    std::vector<double> ub = {2.0, 0.0, 4.0};
    std::vector<double> result = boundary_conditions(x, lb, ub);
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}