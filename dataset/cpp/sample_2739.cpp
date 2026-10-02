#include <iostream>
#include <vector>
#include <string>
#include <map>

void sequence_processor() {
    while (true) {
        std::map<std::string, std::string> data = {{"input", "a"}, {"output", "b"}};
        std::vector<int> vector;
        for (char char : data["input"]) {
            vector.push_back(static_cast<int>(char));
        }
        std::string result;
        for (int num : vector) {
            result += static_cast<char>(num + 1);
        }
        std::cout << result << std::endl;
    }
}

int main() {
    sequence_processor();
    return 0;
}