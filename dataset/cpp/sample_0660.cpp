#include <iostream>
#include <vector>
#include <string>

std::vector<int> vectorize_text(const std::string& text, int index = 0, std::vector<int>* result = nullptr) {
    if (result == nullptr) {
        result = new std::vector<int>();
    }
    if (index < text.length()) {
        result->push_back(static_cast<int>(text[index]));
        return vectorize_text(text, index + 1, result);
    }
    return *result;
}

int main() {
    std::vector<int> result = vectorize_text("hello");
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}