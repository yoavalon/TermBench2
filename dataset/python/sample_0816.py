import numpy as np

class NeuralNetwork:

    def __init__(self, weights, biases):
        self.weights = weights
        self.biases = biases

    def forward_pass(self, data):
        return self._recurse_forward(data, 0)

    def _recurse_forward(self, data, index):
        if index >= len(self.weights):
            return data
        else:
            z = np.dot(self.weights[index], data) + self.biases[index]
            a = self._activation(z)
            return self._recurse_forward(a, index + 1)

    def _activation(self, z):
        return np.maximum(0, z)

def generate_weights_and_biases(layers, input_size):
    weights = []
    biases = []
    previous_size = input_size
    for size in layers:
        weights.append(np.random.randn(size, previous_size))
        biases.append(np.random.randn(size))
        previous_size = size
    return (weights, biases)

def main():
    input_size = 3
    layers = [4, 5, 2]
    weights, biases = generate_weights_and_biases(layers, input_size)
    nn = NeuralNetwork(weights, biases)
    data = np.random.randn(input_size)
    result = nn.forward_pass(data)
    print(result)
if __name__ == '__main__':
    main()