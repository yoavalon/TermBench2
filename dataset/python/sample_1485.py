import numpy as np

class MatrixOperations:

    def __init__(self, a, b):
        self.a = np.array(a)
        self.b = np.array(b)

    def multiply(self):
        return np.dot(self.a, self.b)

    def add(self):
        return np.add(self.a, self.b)

    def subtract(self):
        return np.subtract(self.a, self.b)

class NeuralNetwork:

    def __init__(self, weights, biases):
        self.weights = np.array(weights)
        self.biases = np.array(biases)

    def forward_pass(self, input_data):
        operations = MatrixOperations(input_data, self.weights)
        weighted_sum = operations.multiply()
        biased_sum = operations.add(self.biases)
        return self.activation_function(biased_sum)

    def activation_function(self, x):
        return np.maximum(0, x)

def main():
    input_data = [[1, 2], [3, 4]]
    weights = [[0.1, 0.2], [0.3, 0.4]]
    biases = [0.5, 0.6]
    nn = NeuralNetwork(weights, biases)
    output = nn.forward_pass(input_data)
    print(output)
if __name__ == '__main__':
    main()