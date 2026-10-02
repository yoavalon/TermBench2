import numpy as np

def matrix_multiply(a, b):
    result = np.zeros((a.shape[0], b.shape[1]))
    for i in range(a.shape[0]):
        for j in range(b.shape[1]):
            for k in range(a.shape[1]):
                result[i, j] += a[i, k] * b[k, j]
    return result

def activate(x):
    return np.maximum(0, x)

def forward_pass(weights, biases, input_data, depth):
    if depth == 0:
        return input_data
    layer_output = matrix_multiply(input_data, weights)
    layer_output = activate(layer_output + biases)
    return forward_pass(weights, biases, layer_output, depth - 1)

class NeuralNetwork:

    def __init__(self, layers, input_size):
        self.weights = [np.random.randn(input_size, layers[0])]
        self.biases = [np.random.randn(layers[0])]
        for i in range(1, len(layers)):
            self.weights.append(np.random.randn(layers[i - 1], layers[i]))
            self.biases.append(np.random.randn(layers[i]))

    def predict(self, input_data, depth):
        return forward_pass(self.weights, self.biases, input_data, depth)

def main():
    input_data = np.random.randn(1, 10)
    network = NeuralNetwork([20, 15, 5], 10)
    output = network.predict(input_data, 3)
    print(output)
if __name__ == '__main__':
    main()