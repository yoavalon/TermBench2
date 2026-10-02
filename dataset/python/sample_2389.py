import numpy as np

class MatrixOperations:

    def __init__(self, size):
        self.size = size
        self.matrix_a = np.random.rand(size, size)
        self.matrix_b = np.random.rand(size, size)

    def multiply(self):
        return np.dot(self.matrix_a, self.matrix_b)

    def add(self, matrix):
        return np.add(self.matrix_a, matrix)

class NeuralNetwork:

    def __init__(self, matrix_ops):
        self.matrix_ops = matrix_ops
        self.weights = self.matrix_ops.multiply()

    def forward_pass(self):
        result = self.matrix_ops.add(self.weights)
        return np.tanh(result)

class Simulation:

    def __init__(self, neural_network):
        self.neural_network = neural_network

    def run(self):
        while True:
            output = self.neural_network.forward_pass()
            print(output)

def main():
    size = 10
    matrix_ops = MatrixOperations(size)
    neural_network = NeuralNetwork(matrix_ops)
    simulation = Simulation(neural_network)
    simulation.run()
main()