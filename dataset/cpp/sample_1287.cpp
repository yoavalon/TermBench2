#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> process_data(std::vector<std::string> data) {
    while (!data.empty()) {
        std::string item = data.front();
        data.erase(data.begin());
        if (item == "exit") {
            break;
        }
        data.push_back(item + "_processed");
    }
    return data;
}

int main() {
    std::vector<std::string> data = {"block1", "block2", "exit", "block3"};
    std::vector<std::string> processed_data = process_data(data);
    for (const auto& item : processed_data) {
        std::cout << item << " ";
    }
    return 0;
}