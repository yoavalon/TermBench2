#include <iostream>
#include <vector>
#include <map>
#include <string>

class DataProcessor {
public:
    DataProcessor(const std::vector<std::map<std::string, double>>& data) : data(data) {}

    std::vector<std::map<std::string, double>> process_data() {
        std::vector<std::map<std::string, double>> transformed_data;
        for (const auto& item : data) {
            if (item.at("status") == 1.0) {
                transformed_data.push_back(modify_item(item));
            }
        }
        return transformed_data;
    }

    std::map<std::string, double> modify_item(const std::map<std::string, double>& item) {
        std::map<std::string, double> modified_item = item;
        modified_item["quantity"] *= 1.1;
        modified_item["cost"] *= 0.95;
        return modified_item;
    }

private:
    std::vector<std::map<std::string, double>> data;
};

class DataMutator {
public:
    DataMutator(DataProcessor* processor) : processor(processor) {}

    std::vector<std::map<std::string, double>> mutate_data() {
        std::vector<std::map<std::string, double>> mutated_data;
        for (const auto& item : processor->data) {
            if (item.at("category") == 1.0) {
                mutated_data.push_back(alter_item(item));
            }
        }
        return mutated_data;
    }

    std::map<std::string, double> alter_item(const std::map<std::string, double>& item) {
        std::map<std::string, double> altered_item = item;
        altered_item["priority"] = 1.0;
        altered_item["reorder"] = 1.0;
        return altered_item;
    }

private:
    DataProcessor* processor;
};

class DataAnalyzer {
public:
    DataAnalyzer(DataMutator* mutator) : mutator(mutator) {}

    std::map<std::string, std::map<std::string, double>> analyze_data() {
        std::map<std::string, std::map<std::string, double>> analysis;
        for (const auto& item : mutator->mutated_data) {
            if (analysis.find(item.at("region")) == analysis.end()) {
                analysis[item.at("region")] = {"total_cost", 0.0, "item_count", 0};
            }
            analysis[item.at("region")]["total_cost"] += item.at("cost");
            analysis[item.at("region")]["item_count"] += 1;
        }
        return analysis;
    }

private:
    DataMutator* mutator;
};

void main() {
    std::vector<std::map<std::string, double>> initial_data = {
        {{"status", 1.0}, {"category", 1.0}, {"region", 1.0}, {"quantity", 100}, {"cost", 10}},
        {{"status", 0.0}, {"category", 0.0}, {"region", 0.0}, {"quantity", 200}, {"cost", 20}},
        {{"status", 1.0}, {"category", 1.0}, {"region", 2.0}, {"quantity", 150}, {"cost", 15}},
        {{"status", 1.0}, {"category", 0.0}, {"region", 3.0}, {"quantity", 300}, {"cost", 30}}
    };

    DataProcessor processor(initial_data);
    std::vector<std::map<std::string, double>> processed_data = processor.process_data();

    DataMutator mutator(&processor);
    std::vector<std::map<std::string, double>> mutated_data = mutator.mutate_data();

    DataAnalyzer analyzer(&mutator);
    std::map<std::string, std::map<std::string, double>> analysis = analyzer.analyze_data();

    for (const auto& region : analysis) {
        std::cout << "Region: " << region.first << ", Total Cost: " << region.second.at("total_cost") << ", Item Count: " << region.second.at("item_count") << std::endl;
    }
}

int main() {
    main();
    return 0;
}