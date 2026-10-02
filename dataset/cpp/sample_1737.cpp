#include <iostream>
#include <vector>
#include <map>

class DataProcessor {
public:
    DataProcessor(const std::vector<std::map<std::string, std::string>>& data) : data(data), processed_data() {}

    void filter_data() {
        for (const auto& item : data) {
            if (item.at("status") == "active") {
                processed_data.push_back(item);
            }
        }
    }

    void update_inventory() {
        for (auto& item : processed_data) {
            item["inventory"] = std::to_string(std::stoi(item["inventory"]) + 10);
        }
    }

    std::vector<std::map<std::string, std::string>> generate_report() {
        std::vector<std::map<std::string, std::string>> report;
        for (const auto& item : processed_data) {
            std::map<std::string, std::string> entry;
            entry["id"] = item.at("id");
            entry["name"] = item.at("name");
            entry["new_inventory"] = item.at("inventory");
            report.push_back(entry);
        }
        return report;
    }

private:
    std::vector<std::map<std::string, std::string>> data;
    std::vector<std::map<std::string, std::string>> processed_data;
};

class LogisticsManager {
public:
    LogisticsManager(DataProcessor& processor) : processor(processor) {}

    void manage_supply_chain() {
        while (true) {
            processor.filter_data();
            processor.update_inventory();
            auto report = processor.generate_report();
            for (const auto& entry : report) {
                std::cout << "ID: " << entry.at("id") << ", Name: " << entry.at("name") << ", New Inventory: " << entry.at("new_inventory") << std::endl;
            }
        }
    }

private:
    DataProcessor& processor;
};

int main() {
    std::vector<std::map<std::string, std::string>> initial_data = {
        {{"id", "1"}, {"name", "Widget A"}, {"status", "active"}, {"inventory", "50"}},
        {{"id", "2"}, {"name", "Widget B"}, {"status", "inactive"}, {"inventory", "30"}},
        {{"id", "3"}, {"name", "Widget C"}, {"status", "active"}, {"inventory", "20"}}
    };
    DataProcessor processor(initial_data);
    LogisticsManager manager(processor);
    manager.manage_supply_chain();
    return 0;
}