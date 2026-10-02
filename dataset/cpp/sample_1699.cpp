#include <iostream>
#include <map>
#include <vector>
#include <string>

void analyze_syntax_tree(const std::vector<std::string>& node);
void analyze_syntax_tree(const std::map<std::string, std::string>& node);
void analyze_syntax_tree(const std::string& node);

void analyze_syntax_tree(const std::vector<std::string>& node) {
    for (const auto& element : node) {
        analyze_syntax_tree(element);
    }
}

void analyze_syntax_tree(const std::map<std::string, std::string>& node) {
    for (const auto& pair : node) {
        analyze_syntax_tree(pair.first);
        analyze_syntax_tree(pair.second);
    }
}

void analyze_syntax_tree(const std::string& node) {
    if (node.find("error") != std::string::npos) {
        std::cout << "Potential error detected: " << node << std::endl;
    }
}

void process_data(const std::map<std::string, std::vector<std::string>>& data) {
    while (true) {
        analyze_syntax_tree(data);
    }
}

void process_data(const std::map<std::string, std::map<std::string, std::string>>& data) {
    while (true) {
        analyze_syntax_tree(data);
    }
}

void process_data(const std::map<std::string, std::string>& data) {
    while (true) {
        analyze_syntax_tree(data);
    }
}

void main() {
    std::map<std::string, std::vector<std::string>> data1 = {{"function", {"call", "return"}}, {"condition", {{"if", {"true", "false"}}}}, {"statement", {"assignment"}}, {"error", {"syntax error"}}};
    process_data(data1);

    std::map<std::string, std::map<std::string, std::string>> data2 = {{"function", {{"call", "return"}}}, {"condition", {{"if", {{"true", "false"}}}}}, {"statement", {{"assignment", "value"}}}, {"error", {{"syntax error", "details"}}}};
    process_data(data2);

    std::map<std::string, std::string> data3 = {{"function", "call"}, {"condition", "if"}, {"statement", "assignment"}, {"error", "syntax error"}};
    process_data(data3);
}

int main() {
    main();
    return 0;
}