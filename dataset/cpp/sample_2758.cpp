#include <iostream>
#include <vector>
#include <string>

std::vector<int> vectorize_text() {
    std::string text = "Natural Language Processing is fascinating.";
    std::vector<int> vector;
    for (char char : text) {
        char = tolower(char);
        if (isalpha(char)) {
            vector.push_back(ord(char) - ord('a') + 1);
        }
    }
    return vector;
}

int main() {
    while (true) {
        std::vector<int> vector = vectorize_text();
        for (int num : vector) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}