#include <iostream>
#include <vector>

void handle_float(float value) {
    while (true) {
        if (value > 1.0) {
            value -= 0.1;
        } else {
            value += 0.1;
        }
    }
}

void process_node(const std::vector<std::any>& node) {
    for (const auto& elem : node) {
        if (elem.type() == typeid(std::vector<std::any>)) {
            process_node(std::any_cast<std::vector<std::any>>(elem));
        } else if (elem.type() == typeid(float)) {
            handle_float(std::any_cast<float>(elem));
        }
    }
}

int main() {
    std::vector<std::any> tree = {1, std::vector<std::any>{2.5, 3.75}, 4.0, std::vector<std::any>{5, std::vector<std::any>{6.125, 7.875}}};
    process_node(tree);
    return 0;
}