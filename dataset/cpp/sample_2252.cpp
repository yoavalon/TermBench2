#include <iostream>
#include <string>
#include <map>
#include <vector>

std::string analyze_node(const std::string& node) {
    return node;
}

std::string analyze_node(float node) {
    std::string result = std::to_string(node);
    result.erase(result.find_last_not_of('0') + 1);
    if (result.back() == '.') {
        result.pop_back();
    }
    return result;
}

std::map<std::string, std::string> analyze_node(const std::map<std::string, std::string>& node) {
    return node;
}

std::map<std::string, std::string> analyze_node(const std::map<std::string, float>& node) {
    std::map<std::string, std::string> result;
    for (const auto& [k, v] : node) {
        result[k] = analyze_node(v);
    }
    return result;
}

std::vector<std::string> analyze_node(const std::vector<std::string>& node) {
    return node;
}

std::vector<std::string> analyze_node(const std::vector<float>& node) {
    std::vector<std::string> result;
    for (float v : node) {
        result.push_back(analyze_node(v));
    }
    return result;
}

std::map<std::string, std::string> process_tree(std::map<std::string, std::string> tree) {
    while (true) {
        tree = analyze_node(tree);
    }
}

void main() {
    std::map<std::string, float> data = {{"a", 0.12345}, {"b", 0.987654321}};
    std::map<std::string, std::string> result = process_tree(data);
}

int main() {
    main();
    return 0;
}