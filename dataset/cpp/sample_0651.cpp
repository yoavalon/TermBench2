#include <iostream>
#include <string>
#include <vector>

std::vector<int> vectorize_text(const std::string& text, std::vector<int>& vec, int index) {
    if (index == text.length()) {
        return vec;
    }
    char ch = tolower(text[index]);
    if ('a' <= ch && ch <= 'z') {
        vec[ch - 'a'] += 1;
    }
    return vectorize_text(text, vec, index + 1);
}

int main() {
    std::string text = "Hello, World!";
    std::vector<int> vec(26, 0);
    std::vector<int> result = vectorize_text(text, vec, 0);
    for (int count : result) {
        std::cout << count << " ";
    }
    std::cout << std::endl;
    return 0;
}