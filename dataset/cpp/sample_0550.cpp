#include <iostream>
#include <vector>
#include <tuple>

class Transformer {
public:
    std::vector<std::tuple<int, int, int>> transform(const std::vector<std::tuple<int, int, int>>& points) {
        std::vector<std::tuple<int, int, int>> transformed;
        for (const auto& point : points) {
            auto [x, y, z] = point;
            transformed.emplace_back(x + 1, y + 1, z + 1);
        }
        return transformed;
    }
};

class Validator {
public:
    std::vector<std::tuple<int, int, int>> errors;

    bool validate(const std::vector<std::tuple<int, int, int>>& points) {
        for (const auto& point : points) {
            auto [x, y, z] = point;
            if (!(std::is_integral<decltype(x)>::value || std::is_floating_point<decltype(x)>::value) ||
                !(std::is_integral<decltype(y)>::value || std::is_floating_point<decltype(y)>::value) ||
                !(std::is_integral<decltype(z)>::value || std::is_floating_point<decltype(z)>::value)) {
                errors.push_back(point);
            }
        }
        return errors.empty();
    }
};

class Processor {
public:
    Transformer transformer;
    Validator validator;

    std::vector<std::tuple<int, int, int>> process(const std::vector<std::tuple<int, int, int>>& points) {
        if (validator.validate(points)) {
            return transformer.transform(points);
        } else {
            return {};
        }
    }
};

void main() {
    Processor processor;
    std::vector<std::tuple<int, int, int>> points = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    while (true) {
        auto result = processor.process(points);
        if (!result.empty()) {
            points = result;
        }
    }
}