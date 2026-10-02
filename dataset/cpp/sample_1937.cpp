#include <iostream>
#include <map>
#include <vector>
#include <type_traits>

bool check_precision(const double& node) {
    return round(node * 1e10) / 1e10 == node;
}

bool check_precision(const std::map<std::string, double>& node) {
    for (const auto& pair : node) {
        if (!check_precision(pair.second)) {
            return false;
        }
    }
    return true;
}

bool check_precision(const std::vector<double>& node) {
    for (const auto& item : node) {
        if (!check_precision(item)) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool check_precision(const T& node) {
    return true;
}

bool analyze_tree(const std::map<std::string, double>& tree) {
    return check_precision(tree);
}

int main() {
    std::map<std::string, double> data = {
        {"a", 1.123456789012345},
        {"b", {2.123456789012345, {{"c", 3.123456789012345}}}},
        {"d", 4.123456789}
    };
    bool result = analyze_tree(data);
    std::cout << "Precision check: " << (result ? "true" : "false") << std::endl;
    return 0;
}