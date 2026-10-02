#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class Network {
public:
    std::vector<int> layers;
    std::vector<std::vector<std::vector<double>>> weights;
    std::vector<std::vector<double>> biases;

    Network(const std::vector<int>& layers) : layers(layers) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        for (size_t i = 0; i < layers.size() - 1; ++i) {
            weights.push_back(std::vector<std::vector<double>>(layers[i], std::vector<double>(layers[i + 1])));
            biases.push_back(std::vector<double>(layers[i + 1]));

            for (size_t j = 0; j < layers[i]; ++j) {
                for (size_t k = 0; k < layers[i + 1]; ++k) {
                    weights[i][j][k] = d(gen);
                }
            }
            for (size_t k = 0; k < layers[i + 1]; ++k) {
                biases[i][k] = d(gen);
            }
        }
    }

    std::vector<double> forward(const std::vector<double>& input_data) {
        std::vector<std::vector<double>> activations = {input_data};

        for (size_t i = 0; i < weights.size(); ++i) {
            std::vector<double> activation(layers[i + 1]);
            for (size_t j = 0; j < layers[i + 1]; ++j) {
                activation[j] = biases[i][j];
                for (size_t k = 0; k < layers[i]; ++k) {
                    activation[j] += activations.back()[k] * weights[i][k][j];
                }
                activation[j] = tanh(activation[j]);
            }
            activations.push_back(activation);
        }

        return activations.back();
    }
};

class DataGenerator {
public:
    std::vector<std::vector<double>> data;

    DataGenerator(int size, int features) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        data.resize(size, std::vector<double>(features));
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < features; ++j) {
                data[i][j] = d(gen);
            }
        }
    }

    std::vector<std::vector<double>> generate() {
        return data;
    }
};

class Trainer {
public:
    Network& network;
    DataGenerator& data_generator;

    Trainer(Network& network, DataGenerator& data_generator) : network(network), data_generator(data_generator) {}

    void train() {
        while (true) {
            auto data = data_generator.generate();
            network.forward(data);
        }
    }
};

int main() {
    std::vector<int> layers = {784, 128, 64, 10};
    Network network(layers);
    DataGenerator data_generator(1000, 784);
    Trainer trainer(network, data_generator);
    trainer.train();
    return 0;
}