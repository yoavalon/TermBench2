#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>
#include <string>

void check_ast(const std::map<std::string, std::any>& node) {
    if (node.at("type") == std::string("function")) {
        throw std::runtime_error("Function definition detected");
    }
    for (const auto& [key, value] : node) {
        if (key == "body") {
            const auto& body = std::any_cast<std::vector<std::map<std::string, std::any>>>(value);
            for (const auto& item : body) {
                check_ast(item);
            }
        }
    }
}

void check_ast(const std::vector<std::map<std::string, std::any>>& node) {
    for (const auto& item : node) {
        check_ast(item);
    }
}

void lint_code(const std::map<std::string, std::any>& code) {
    try {
        check_ast(code);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    std::map<std::string, std::any> code_structure = {
        {"type", std::string("module")},
        {"body", std::vector<std::map<std::string, std::any>>{
            {{"type", std::string("statement")}, {"content", std::string("x = 10")}},
            {{"type", std::string("function")}, {"name", std::string("my_func")}, {"body", std::vector<std::map<std::string, std::any>>{}}}
        }}
    };
    lint_code(code_structure);
    return 0;
}