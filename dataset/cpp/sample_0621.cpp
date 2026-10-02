#include <iostream>
#include <vector>
#include <string>

std::vector<int> process_text(const std::string& text, int index = 0, std::vector<int> result = {}) {
    if (index >= text.length()) {
        return result;
    } else {
        result.push_back(static_cast<int>(text[index]));
        return process_text(text, index + 1, result);
    }
}

int main() {
    std::string text = "Hello, World!";
    std::vector<int> vector = process_text(text);
    for (int num : vector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}