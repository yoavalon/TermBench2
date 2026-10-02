import numpy as np

class NeuralNetwork:

    def __init__(self, input_size, hidden_size, output_size):
        self.weights_input_hidden = np.random.randn(input_size, hidden_size)
        self.weights_hidden_output = np.random.randn(hidden_size, output_size)
        self.bias_hidden = np.random.randn(hidden_size)
        self.bias_output = np.random.randn(output_size)

    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))

    def forward_pass(self, inputs):
        hidden_layer_input = np.dot(inputs, self.weights_input_hidden) + self.bias_hidden
        hidden_layer_output = self.sigmoid(hidden_layer_input)
        output_layer_input = np.dot(hidden_layer_output, self.weights_hidden_output) + self.bias_output
        output_layer_output = self.sigmoid(output_layer_input)
        return output_layer_output

class MatrixOperations:

    def __init__(self, data):
        self.data = data

    def add_identity(self):
        identity = np.eye(self.data.shape[0])
        return self.data + identity

    def multiply_scalar(self, scalar):
        return self.data * scalar

    def transpose(self):
        return self.data.T

def main():
    np.random.seed(0)
    input_size, hidden_size, output_size = (4, 5, 3)
    neural_net = NeuralNetwork(input_size, hidden_size, output_size)
    matrix_ops = MatrixOperations(np.random.rand(input_size, input_size))
    modified_weights = matrix_ops.add_identity().transpose().multiply_scalar(0.5)
    neural_net.weights_input_hidden = modified_weights
    input_data = np.random.rand(1, input_size)
    output = neural_net.forward_pass(input_data)
    print(output)
if __name__ == '__main__':
    main()