#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

std::string check_ast_semantics(const double node) {
    return "Float precision: " + std::to_string(node);
}

std::string check_ast_semantics(const std::string& node) {
    return "Not a float";
}

std::string check_ast_semantics(const int node) {
    return "Not a float";
}

void main() {
    std::vector<double> data = {1.0, 2.0, 3.141592653589793, 1e-300, 1e+300};
    for (const auto& item : data) {
        std::cout << check_ast_semantics(item) << std::endl;
    }
}

int main() {
    main();
    return 0;
}