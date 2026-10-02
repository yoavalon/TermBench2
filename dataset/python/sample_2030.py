import numpy as np

class MatrixProcessor:

    def __init__(self, matrix):
        self.matrix = matrix

    def normalize(self):
        max_val = np.max(self.matrix)
        self.matrix /= max_val
        return self.matrix

    def apply_activation(self, activation_func):
        self.matrix = activation_func(self.matrix)
        return self.matrix

class NeuralNetwork:

    def __init__(self, layers):
        self.layers = layers

    def forward_pass(self, input_data):
        output = input_data
        for layer in self.layers:
            output = layer(output)
        return output

class ActivationFunctions:

    @staticmethod
    def sigmoid(x):
        return 1 / (1 + np.exp(-x))

    @staticmethod
    def relu(x):
        return np.maximum(0, x)

def main():
    np.random.seed(0)
    data = np.random.rand(10, 10)
    processor = MatrixProcessor(data)
    normalized_data = processor.normalize()
    activation_functions = ActivationFunctions()
    relu_output = processor.apply_activation(activation_functions.relu)
    sigmoid_output = processor.apply_activation(activation_functions.sigmoid)
    layers = [lambda x: relu_output, lambda x: sigmoid_output]
    network = NeuralNetwork(layers)
    result = network.forward_pass(normalized_data)
    print(result)
if __name__ == '__main__':
    main()