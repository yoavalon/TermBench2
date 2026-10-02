#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <typeinfo>

bool validate_node(const std::map<std::string, std::any>& node) {
    if (node.find("type") == node.end() || node.find("value") == node.end()) {
        return false;
    }
    if (std::any_cast<std::string>(node.at("type")) == "operator" && node.find("children") == node.end()) {
        return false;
    }
    if (std::any_cast<std::string>(node.at("type")) == "operator") {
        std::vector<std::map<std::string, std::any>> children = std::any_cast<std::vector<std::map<std::string, std::any>>>(node.at("children"));
        for (const auto& child : children) {
            if (!validate_node(child)) {
                return false;
            }
        }
    }
    return true;
}

bool check_sequence(const std::vector<std::map<std::string, std::any>>& sequence) {
    for (const auto& node : sequence) {
        if (!validate_node(node)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::map<std::string, std::any>> sequence = {
        {{"type", std::string("number")}, {"value", 1}},
        {{"type", std::string("operator")}, {"value", std::string("+")}, {"children", std::vector<std::map<std::string, std::any>>{
            {{"type", std::string("number")}, {"value", 2}},
            {{"type", std::string("number")}, {"value", 3}}
        }}}
    };
    if (check_sequence(sequence)) {
        std::cout << "Sequence is valid." << std::endl;
    } else {
        std::cout << "Sequence is invalid." << std::endl;
    }
    return 0;
}