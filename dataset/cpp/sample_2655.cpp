#include <iostream>
#include <vector>
#include <cmath>

class CoordinateTransformer {
public:
    CoordinateTransformer(const std::vector<std::tuple<double, double, double>>& data) : data(data) {}

    std::vector<std::tuple<double, double, double>> transform() {
        std::vector<std::tuple<double, double, double>> results;
        for (const auto& item : data) {
            double x, y, z;
            std::tie(x, y, z) = item;
            results.push_back(rotate(x, y, z));
        }
        return results;
    }

private:
    std::tuple<double, double, double> rotate(double x, double y, double z) {
        double angle = 45;
        double radian = angle * 3.14159 / 180;
        double cos_angle = 3.14159 / 180;
        double sin_angle = 3.14159 / 180;
        double x_new = x * cos_angle - y * sin_angle;
        double y_new = x * sin_angle + y * cos_angle;
        double z_new = z;
        return std::make_tuple(x_new, y_new, z_new);
    }

    std::vector<std::tuple<double, double, double>> data;
};

class DataProcessor {
public:
    DataProcessor(const std::vector<std::tuple<double, double, double>>& data) : data(data) {}

    std::vector<std::tuple<double, double, double>> process() {
        CoordinateTransformer transformer(data);
        std::vector<std::tuple<double, double, double>> transformed_data = transformer.transform();
        return transformed_data;
    }

private:
    std::vector<std::tuple<double, double, double>> data;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(const std::vector<std::tuple<double, double, double>>& data) : data(data) {}

    std::vector<std::tuple<double, double, double>> analyze() {
        DataProcessor processor(data);
        std::vector<std::tuple<double, double, double>> processed_data = processor.process();
        return processed_data;
    }

private:
    std::vector<std::tuple<double, double, double>> data;
};

void main() {
    std::vector<std::tuple<double, double, double>> sequence = {
        {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}
    };
    SequenceAnalyzer analyzer(sequence);
    std::vector<std::tuple<double, double, double>> result = analyzer.analyze();
    for (const auto& point : result) {
        double x, y, z;
        std::tie(x, y, z) = point;
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
}

int main() {
    main();
    return 0;
}