import numpy as np

class NeuralNetwork:

    def __init__(self, layers):
        self.weights = [np.random.randn(layers[i], layers[i + 1]) for i in range(len(layers) - 1)]
        self.biases = [np.random.randn(1, layers[i + 1]) for i in range(len(layers) - 1)]

    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))

    def forward_pass(self, input_data):
        activations = [input_data]
        for w, b in zip(self.weights, self.biases):
            z = np.dot(activations[-1], w) + b
            activations.append(self.sigmoid(z))
        return activations[-1]

class DataProcessor:

    def __init__(self, data):
        self.data = data

    def normalize(self):
        return (self.data - np.min(self.data)) / (np.max(self.data) - np.min(self.data))

    def prepare_batches(self, batch_size):
        return [self.data[i:i + batch_size] for i in range(0, len(self.data), batch_size)]

class Controller:

    def __init__(self, nn, dp):
        self.nn = nn
        self.dp = dp

    def process_data(self):
        normalized_data = self.dp.normalize()
        batches = self.dp.prepare_batches(10)
        for batch in batches:
            self.nn.forward_pass(batch)

def main():
    layers = [784, 128, 64, 10]
    nn = NeuralNetwork(layers)
    data = np.random.randn(1000, 784)
    dp = DataProcessor(data)
    controller = Controller(nn, dp)
    while True:
        controller.process_data()
main()