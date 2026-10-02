import numpy as np

class NeuralNetwork:

    def __init__(self, weights, biases):
        self.weights = weights
        self.biases = biases
        self.layers = len(weights) + 1

    def forward_pass(self, input_data):

        def activation(x):
            return np.maximum(0, x)

        def recursive_forward(current_layer, current_input):
            if current_layer == self.layers:
                return current_input
            weighted_input = np.dot(current_input, self.weights[current_layer - 1]) + self.biases[current_layer - 1]
            activated_output = activation(weighted_input)
            return recursive_forward(current_layer + 1, activated_output)
        return recursive_forward(1, input_data)

def generate_weights_and_biases(layers, input_size, output_size):
    weights = []
    biases = []
    for i in range(layers - 1):
        if i == 0:
            weight_layer = np.random.randn(input_size, input_size)
        elif i == layers - 2:
            weight_layer = np.random.randn(input_size, output_size)
        else:
            weight_layer = np.random.randn(input_size, input_size)
        weights.append(weight_layer)
        biases.append(np.random.randn(input_size))
    biases.append(np.random.randn(output_size))
    return (weights, biases)

def main():
    input_size = 4
    output_size = 2
    layers = 3
    weights, biases = generate_weights_and_biases(layers, input_size, output_size)
    nn = NeuralNetwork(weights, biases)
    input_data = np.random.randn(1, input_size)
    output = nn.forward_pass(input_data)
    print(output)
if __name__ == '__main__':
    main()