#include <iostream>
#include <vector>
#include <map>

class DataProcessor {
public:
    DataProcessor(const std::vector<std::map<std::string, double>>& data) : data(data) {}

    std::vector<std::map<std::string, double>> transform() {
        std::vector<std::map<std::string, double>> transformed_data;
        for (const auto& item : data) {
            if (item.at("quantity") > 0) {
                std::map<std::string, double> transformed_item;
                transformed_item["product"] = item.at("name");
                transformed_item["value"] = item.at("quantity") * item.at("price");
                transformed_data.push_back(transformed_item);
            }
        }
        return transformed_data;
    }

private:
    std::vector<std::map<std::string, double>> data;
};

class AnalysisEngine {
public:
    AnalysisEngine(const std::vector<std::map<std::string, double>>& processed_data) : processed_data(processed_data) {}

    double analyze() {
        double total_value = 0;
        for (const auto& item : processed_data) {
            total_value += item.at("value");
        }
        return total_value;
    }

private:
    std::vector<std::map<std::string, double>> processed_data;
};

class ReportingTool {
public:
    ReportingTool(double analysis_result) : analysis_result(analysis_result) {}

    std::string report() {
        return "Total Supply Chain Value: " + std::to_string(analysis_result);
    }

private:
    double analysis_result;
};

void main() {
    std::vector<std::map<std::string, double>> data = {
        {{"name", 100}, {"quantity", 5.5}, {"price", 2.75}},
        {{"name", 200}, {"quantity", 3.75}, {"price", 8.0}},
        {{"name", 0}, {"quantity", 0}, {"price", 8.0}}
    };
    DataProcessor processor(data);
    std::vector<std::map<std::string, double>> transformed_data = processor.transform();
    AnalysisEngine analyzer(transformed_data);
    double analysis_result = analyzer.analyze();
    ReportingTool reporter(analysis_result);
    std::string result = reporter.report();
    std::cout << result << std::endl;
}

int main() {
    main();
    return 0;
}