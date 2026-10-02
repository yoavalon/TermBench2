import numpy as np

class MatrixProcessor:

    def __init__(self, data):
        self.data = data
        self.processed_data = None

    def normalize(self):
        mean = np.mean(self.data)
        std = np.std(self.data)
        self.processed_data = (self.data - mean) / std

    def apply_weight(self, weights):
        self.processed_data = np.dot(self.processed_data, weights)

    def activate(self):
        self.processed_data = np.where(self.processed_data > 0, self.processed_data, 0)

class NeuralNetwork:

    def __init__(self, layers):
        self.layers = layers
        self.weights = [np.random.rand(layer[i], layer[i + 1]) for i in range(len(layer) - 1)]

    def forward_pass(self, data):
        processor = MatrixProcessor(data)
        for i, weight in enumerate(self.weights):
            processor.normalize()
            processor.apply_weight(weight)
            processor.activate()
        return processor.processed_data

def main():
    data = np.random.rand(10, 5)
    layers = [5, 10, 5]
    network = NeuralNetwork(layers)
    output = network.forward_pass(data)
    print(output)
if __name__ == '__main__':
    main()