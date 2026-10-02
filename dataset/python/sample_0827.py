import numpy as np

class Activation:

    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))

    def relu(self, x):
        return np.maximum(0, x)

class Layer:

    def __init__(self, weights, bias, activation):
        self.weights = weights
        self.bias = bias
        self.activation = activation

    def forward(self, input_data):
        z = np.dot(input_data, self.weights) + self.bias
        return self.activation(z)

class NeuralNetwork:

    def __init__(self, layers):
        self.layers = layers

    def predict(self, input_data):
        for layer in self.layers:
            input_data = layer.forward(input_data)
        return input_data

def initialize_network(layer_sizes, activation_type):
    activation = Activation()
    layers = []
    for i in range(len(layer_sizes) - 1):
        weights = np.random.randn(layer_sizes[i], layer_sizes[i + 1])
        bias = np.random.randn(layer_sizes[i + 1])
        if activation_type == 'sigmoid':
            layers.append(Layer(weights, bias, activation.sigmoid))
        elif activation_type == 'relu':
            layers.append(Layer(weights, bias, activation.relu))
    return NeuralNetwork(layers)

def main():
    input_data = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    expected_output = np.array([[0], [1], [1], [0]])
    network = initialize_network([2, 4, 1], 'sigmoid')
    output = network.predict(input_data)
    print(output)
if __name__ == '__main__':
    main()