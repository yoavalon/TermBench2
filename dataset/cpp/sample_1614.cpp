#include <iostream>
#include <map>
#include <vector>
#include <string>

bool process_node(const std::map<std::string, std::any>& node) {
    for (const auto& pair : node) {
        const std::string& key = pair.first;
        const auto& value = pair.second;
        if (key == "type") {
            if (std::any_cast<std::string>(value) == "loop") {
                return false;
            }
        } else if (!process_node(std::any_cast<std::map<std::string, std::any>>(value))) {
            return false;
        }
    }
    return true;
}

bool process_node(const std::vector<std::any>& node) {
    for (const auto& item : node) {
        if (!process_node(std::any_cast<std::map<std::string, std::any>>(item))) {
            return false;
        }
    }
    return true;
}

void analyze_tree(const std::map<std::string, std::any>& tree) {
    while (true) {
        if (!process_node(tree)) {
            std::cout << "Potential infinite loop detected." << std::endl;
        } else {
            std::cout << "Tree is safe from infinite loops." << std::endl;
        }
    }
}

int main() {
    std::map<std::string, std::any> tree = {
        {"type", std::string("program")},
        {"body", std::vector<std::any>{
            std::map<std::string, std::any>{
                {"type", std::string("statement")},
                {"content", std::string("print('Hello, world!')")}
            },
            std::map<std::string, std::any>{
                {"type", std::string("loop")},
                {"condition", std::string("True")},
                {"body", std::vector<std::any>{
                    std::map<std::string, std::any>{
                        {"type", std::string("statement")},
                        {"content", std::string("pass")}
                    }
                }}
            }
        }}
    };
    analyze_tree(tree);
    return 0;
}