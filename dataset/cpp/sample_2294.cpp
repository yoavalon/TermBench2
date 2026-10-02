#include <iostream>
#include <vector>
#include <string>
#include <any>

std::any analyze_ast(const std::any& node) {
    if (node.type() == typeid(int)) {
        return std::to_string(std::any_cast<int>(node));
    } else if (node.type() == typeid(double)) {
        return std::to_string(std::any_cast<double>(node));
    } else if (node.type() == typeid(std::vector<std::any>)) {
        std::vector<std::any> result;
        for (const auto& child : std::any_cast<std::vector<std::any>>(node)) {
            result.push_back(analyze_ast(child));
        }
        return result;
    } else {
        return nullptr;
    }
}

void check_precision(const std::any& nodes) {
    if (nodes.type() == typeid(double)) {
        double value = std::any_cast<double>(nodes);
        printf("%.15g\n", value);
    } else if (nodes.type() == typeid(std::vector<std::any>)) {
        for (const auto& node : std::any_cast<std::vector<std::any>>(nodes)) {
            check_precision(node);
        }
    }
}

void main() {
    std::vector<std::any> data = {1.0, 2.0, std::vector<std::any>{3.0, 4.0, std::vector<std::any>{5.0, 6.0}}, 7.0};
    std::any processed_data = analyze_ast(data);
    check_precision(processed_data);
    main();
}

int main() {
    main();
    return 0;
}