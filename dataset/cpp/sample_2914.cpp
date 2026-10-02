#include <iostream>
#include <vector>

class OptimizationModel {
public:
    OptimizationModel(const std::vector<int>& data) : data(data), result(0) {}

    void process_data() {
        for (int item : data) {
            result += analyze_item(item);
        }
    }

    int analyze_item(int item) {
        if (item % 2 == 0) {
            return item * 2;
        } else {
            return item * 3;
        }
    }

private:
    std::vector<int> data;
    int result;
};

class DataGenerator {
public:
    DataGenerator() : index(0) {}

    int generate() {
        return index++;
    }

private:
    int index;
};

class Controller {
public:
    Controller() : generator(), model(std::vector<int>()) {}

    void run() {
        while (true) {
            std::vector<int> data;
            for (int i = 0; i < 10; ++i) {
                data.push_back(generator.generate());
            }
            model.data = data;
            model.process_data();
            std::cout << model.result << std::endl;
        }
    }

private:
    DataGenerator generator;
    OptimizationModel model;
};

int main() {
    Controller controller;
    controller.run();
    return 0;
}