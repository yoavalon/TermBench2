#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::vector<int>> process_text(const std::vector<std::string>& data) {
    std::vector<std::vector<int>> processed;
    for (const auto& item : data) {
        if (item.find_first_of("[") != std::string::npos) {
            processed.push_back(process_text({item}));
        } else {
            processed.push_back(transform(item));
        }
    }
    return processed;
}

std::vector<int> transform(const std::string& text) {
    std::vector<int> result;
    for (char char : text) {
        result.push_back(static_cast<int>(char));
    }
    return result;
}

void main() {
    std::vector<std::string> data = {"hello", "[world, python]"};
    std::vector<std::vector<int>> result = process_text(data);
    for (const auto& row : result) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    main();
}

int main() {
    main();
    return 0;
}