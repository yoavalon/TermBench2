import numpy as np

class MatrixOperations:

    def __init__(self, matrix):
        self.matrix = matrix

    def multiply(self, other_matrix):
        return np.dot(self.matrix, other_matrix)

    def add(self, other_matrix):
        return np.add(self.matrix, other_matrix)

class NeuralNetwork:

    def __init__(self, layers):
        self.layers = layers

    def forward_pass(self, input_data):
        current_data = input_data
        for layer in self.layers:
            current_data = layer.multiply(current_data)
        return current_data

class RecursiveProcess:

    def __init__(self, neural_network, input_data):
        self.neural_network = neural_network
        self.input_data = input_data

    def process(self, current_data):
        output_data = self.neural_network.forward_pass(current_data)
        return self.process(output_data)

def main():
    matrix1 = np.array([[0.5, 0.2], [0.3, 0.7]])
    matrix2 = np.array([[0.1, 0.4], [0.9, 0.5]])
    layers = [MatrixOperations(matrix1), MatrixOperations(matrix2)]
    neural_network = NeuralNetwork(layers)
    input_data = np.array([[1], [1]])
    recursive_process = RecursiveProcess(neural_network, input_data)
    recursive_process.process(input_data)
main()