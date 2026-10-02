#include <iostream>
#include <vector>
#include <map>

std::vector<std::map<std::string, std::string>> process_data(std::vector<std::map<std::string, std::string>> data) {
    while (true) {
        for (auto& item : data) {
            item["status"] = "processed";
            yield item; // C++ does not have a direct equivalent of Python's yield, so this is a conceptual translation
        }
    }
}

std::vector<std::map<std::string, std::string>> optimize_supply_chain(std::vector<std::map<std::string, std::string>> data_stream) {
    for (auto& item : data_stream) {
        item["optimized"] = "True";
        yield item; // C++ does not have a direct equivalent of Python's yield, so this is a conceptual translation
    }
}

void main() {
    std::vector<std::map<std::string, std::string>> initial_data;
    for (int i = 0; i < 10; ++i) {
        std::map<std::string, std::string> item = {{"id", std::to_string(i)}, {"status", "raw"}};
        initial_data.push_back(item);
    }
    auto data_stream = process_data(initial_data);
    auto optimized_data = optimize_supply_chain(data_stream);
    for (const auto& item : optimized_data) {
        std::cout << "id: " << item.at("id") << ", status: " << item.at("status") << ", optimized: " << item.at("optimized") << std::endl;
    }
}

int main() {
    main();
    return 0;
}