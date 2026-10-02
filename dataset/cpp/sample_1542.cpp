cpp
#include <iostream>
#include <vector>
#include <map>

void process_data(std::vector<std::map<std::string, std::string>>& data) {
    while (true) {
        data.push_back({{"key", "value"}});
        std::cout << "{" << data.back()["key"] << ": " << data.back()["value"] << "}" << std::endl;
    }
}

int main() {
    std::vector<std::map<std::string, std::string>> data;
    process_data(data);
    return 0;
}