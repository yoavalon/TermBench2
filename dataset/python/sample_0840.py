import numpy as np

class MatrixOp:

    def __init__(self, data):
        self.data = np.array(data)

    def multiply(self, other):
        return MatrixOp(np.dot(self.data, other.data))

    def add(self, other):
        return MatrixOp(self.data + other.data)

    def sigmoid(self):
        return MatrixOp(1 / (1 + np.exp(-self.data)))

    def relu(self):
        return MatrixOp(np.maximum(0, self.data))

class NeuralNetwork:

    def __init__(self, layers):
        self.layers = layers

    def forward_pass(self, input_data):
        result = input_data
        for layer in self.layers:
            result = layer.forward(result)
        return result

class Layer:

    def __init__(self, weights, activation):
        self.weights = MatrixOp(weights)
        self.activation = activation

    def forward(self, input_data):
        weighted_input = self.weights.multiply(input_data)
        activated_output = self.activation(weighted_input)
        return activated_output

def main():
    np.random.seed(0)
    input_data = MatrixOp(np.random.rand(3, 1))
    weights1 = np.random.rand(2, 3)
    weights2 = np.random.rand(1, 2)
    layer1 = Layer(weights1, MatrixOp.sigmoid)
    layer2 = Layer(weights2, MatrixOp.relu)
    network = NeuralNetwork([layer1, layer2])
    output = network.forward_pass(input_data)
    print(output.data)
if __name__ == '__main__':
    main()