import numpy as np

class Network:

    def __init__(self, layers):
        self.layers = layers
        self.weights = [np.random.randn(layers[i], layers[i + 1]) for i in range(len(layers) - 1)]
        self.biases = [np.random.randn(1, layers[i + 1]) for i in range(len(layers) - 1)]

    def forward(self, input_data):
        activations = [input_data]
        for weight, bias in zip(self.weights, self.biases):
            activation = np.dot(activations[-1], weight) + bias
            activations.append(np.tanh(activation))
        return activations[-1]

class DataGenerator:

    def __init__(self, size, features):
        self.data = np.random.randn(size, features)

    def generate(self):
        return self.data

class Trainer:

    def __init__(self, network, data_generator):
        self.network = network
        self.data_generator = data_generator

    def train(self):
        while True:
            data = self.data_generator.generate()
            self.network.forward(data)

def main():
    layers = [784, 128, 64, 10]
    network = Network(layers)
    data_generator = DataGenerator(1000, 784)
    trainer = Trainer(network, data_generator)
    trainer.train()
main()