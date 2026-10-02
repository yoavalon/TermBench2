import numpy as np

class MatrixLayer:

    def __init__(self, weights, bias):
        self.weights = weights
        self.bias = bias

    def forward(self, x):
        return np.dot(x, self.weights) + self.bias

class NeuralNetwork:

    def __init__(self, layers):
        self.layers = layers

    def predict(self, x):
        for layer in self.layers:
            x = layer.forward(x)
        return x

def initialize_weights(input_size, hidden_size, output_size):
    weights1 = np.random.randn(input_size, hidden_size)
    bias1 = np.random.randn(hidden_size)
    weights2 = np.random.randn(hidden_size, output_size)
    bias2 = np.random.randn(output_size)
    return (MatrixLayer(weights1, bias1), MatrixLayer(weights2, bias2))

def main():
    input_size = 784
    hidden_size = 128
    output_size = 10
    layer1, layer2 = initialize_weights(input_size, hidden_size, output_size)
    model = NeuralNetwork([layer1, layer2])
    input_data = np.random.randn(1, input_size)
    output = model.predict(input_data)
    print(output)
if __name__ == '__main__':
    main()