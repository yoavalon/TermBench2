import numpy as np

def initialize_weights(size):
    return np.random.randn(size, size)

def apply_activation(matrix):
    return np.tanh(matrix)

def forward_pass(input_matrix, weights):
    return apply_activation(np.dot(input_matrix, weights))

def calculate_error(output, target):
    return np.mean((output - target) ** 2)

def update_weights(weights, input_matrix, output, target, learning_rate):
    error = output - target
    gradient = np.dot(input_matrix.T, error * (1 - output ** 2))
    return weights - learning_rate * gradient

class NeuralNetwork:

    def __init__(self, size, learning_rate):
        self.weights = initialize_weights(size)
        self.learning_rate = learning_rate

    def train(self, input_data, target_data, epochs):
        for _ in range(epochs):
            output = forward_pass(input_data, self.weights)
            error = calculate_error(output, target_data)
            self.weights = update_weights(self.weights, input_data, output, target_data, self.learning_rate)
        return (output, error)

def main():
    size = 4
    learning_rate = 0.1
    epochs = 100
    input_data = np.random.randn(1, size)
    target_data = np.random.randn(1, size)
    network = NeuralNetwork(size, learning_rate)
    final_output, final_error = network.train(input_data, target_data, epochs)
    print('Final Output:', final_output)
    print('Final Error:', final_error)
if __name__ == '__main__':
    main()