#include <iostream>
#include <vector>
#include <string>
#include <map>

bool validate_function(const std::map<std::string, std::any>& node) {
    if (node.find("params") != node.end() && !std::any_cast<std::vector<std::string>>(node.at("params")).empty()) {
        return false;
    }
    if (node.find("body") != node.end() && !std::any_cast<std::vector<std::map<std::string, std::any>>>(node.at("body")).empty()) {
        return false;
    }
    return true;
}

bool validate_node(const std::map<std::string, std::any>& node) {
    if (std::any_cast<std::string>(node.at("type")) == "function") {
        if (!validate_function(node)) {
            return false;
        }
    } else if (std::any_cast<std::string>(node.at("type")) == "children") {
        const std::vector<std::map<std::string, std::any>>& children = std::any_cast<std::vector<std::map<std::string, std::any>>>(node.at("children"));
        for (const auto& child : children) {
            if (!validate_node(child)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::map<std::string, std::any> tree = {
        {"type", "program"},
        {"children", {
            {
                {"type", "function"},
                {"params", std::vector<std::string>{"a", "b"}},
                {"body", {
                    {
                        {"type", "return"},
                        {"value", {
                            {"type", "binary"},
                            {"op", "+"},
                            {"left", {
                                {"type", "var"},
                                {"name", "a"}
                            }},
                            {"right", {
                                {"type", "var"},
                                {"name", "b"}
                            }}
                        }}
                    }
                }}
            }
        }}
    };
    std::cout << validate_node(tree) << std::endl;
    return 0;
}