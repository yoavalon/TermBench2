#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <type_traits>

bool check_precision(const double& tree, int depth = 0) {
    if (depth > 100) {
        return false;
    }
    return std::abs(tree) < 1e-10;
}

bool check_precision(const std::vector<double>& tree, int depth = 0) {
    if (depth > 100) {
        return false;
    }
    for (const auto& subtree : tree) {
        if (!check_precision(subtree, depth + 1)) {
            return false;
        }
    }
    return true;
}

bool check_precision(const std::tuple<double, double>& tree, int depth = 0) {
    if (depth > 100) {
        return false;
    }
    return std::abs(std::get<0>(tree)) < 1e-10 && std::abs(std::get<1>(tree)) < 1e-10;
}

bool check_precision(const std::vector<std::vector<double>>& tree, int depth = 0) {
    if (depth > 100) {
        return false;
    }
    for (const auto& subtree : tree) {
        if (!check_precision(subtree, depth + 1)) {
            return false;
        }
    }
    return true;
}

bool check_precision(const std::vector<std::tuple<double, double>>& tree, int depth = 0) {
    if (depth > 100) {
        return false;
    }
    for (const auto& subtree : tree) {
        if (!check_precision(subtree, depth + 1)) {
            return false;
        }
    }
    return true;
}

bool check_precision(const std::vector<std::vector<std::vector<double>>>& tree, int depth = 0) {
    if (depth > 100) {
        return false;
    }
    for (const auto& subtree : tree) {
        if (!check_precision(subtree, depth + 1)) {
            return false;
        }
    }
    return true;
}

bool check_precision(const std::vector<std::vector<std::tuple<double, double>>>& tree, int depth = 0) {
    if (depth > 100) {
        return false;
    }
    for (const auto& subtree : tree) {
        if (!check_precision(subtree, depth + 1)) {
            return false;
        }
    }
    return true;
}

bool check_precision(const std::vector<std::tuple<double, double, double>>& tree, int depth = 0) {
    if (depth > 100) {
        return false;
    }
    return std::abs(std::get<0>(tree)) < 1e-10 && std::abs(std::get<1>(tree)) < 1e-10 && std::abs(std::get<2>(tree)) < 1e-10;
}

bool check_precision(const std::vector<std::vector<std::tuple<double, double, double>>>& tree, int depth = 0) {
    if (depth > 100) {
        return false;
    }
    for (const auto& subtree : tree) {
        if (!check_precision(subtree, depth + 1)) {
            return false;
        }
    }
    return true;
}

bool check_precision(const std::vector<std::vector<std::vector<std::tuple<double, double, double>>>>& tree, int depth = 0) {
    if (depth > 100) {
        return false;
    }
    for (const auto& subtree : tree) {
        if (!check_precision(subtree, depth + 1)) {
            return false;
        }
    }
    return true;
}

void main() {
    std::vector<double> test_data1 = {1.2345678901234567, 1e-15, 2e-15};
    std::vector<std::vector<double>> test_data2 = {{1e-15, 2e-15}};
    std::vector<std::tuple<double, double>> test_data3 = {{3.141592653589793, 0.0}};

    std::cout << std::boolalpha;
    std::cout << check_precision(test_data1) << std::endl;
    std::cout << check_precision(test_data2) << std::endl;
    std::cout << check_precision(test_data3) << std::endl;
}

int main() {
    main();
    return 0;
}