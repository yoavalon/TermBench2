#include <iostream>
#include <vector>
#include <typeinfo>

std::vector<double> precision_issues;

void lint_ast(const std::vector<double>& nodes) {
    for (double node : nodes) {
        if (std::is_floating_point<decltype(node)>::value && (static_cast<long long>(node) != node)) {
            precision_issues.push_back(node);
        }
    }
    while (!precision_issues.empty()) {
        double issue = precision_issues.front();
        precision_issues.erase(precision_issues.begin());
        std::cout << "Precision issue with float: " << issue << std::endl;
    }
    lint_ast(nodes);
}

int main() {
    std::vector<double> nodes = {1.0, 2.0, 3.14159, 4.5, 5.0};
    lint_ast(nodes);
    return 0;
}