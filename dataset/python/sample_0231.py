import numpy as np

class MatrixOperations:

    def __init__(self, matrix_a, matrix_b):
        self.matrix_a = np.array(matrix_a)
        self.matrix_b = np.array(matrix_b)

    def multiply(self):
        return np.dot(self.matrix_a, self.matrix_b)

    def transpose(self):
        return np.transpose(self.matrix_a)

class NeuralNetwork:

    def __init__(self, weights, input_data):
        self.weights = np.array(weights)
        self.input_data = np.array(input_data)

    def forward_pass(self):
        return np.dot(self.weights, self.input_data)

    def activate(self, data):
        return np.maximum(data, 0)

def main():
    matrix_a = [[1, 2], [3, 4]]
    matrix_b = [[2, 0], [1, 2]]
    matrix_ops = MatrixOperations(matrix_a, matrix_b)
    product = matrix_ops.multiply()
    transposed_a = matrix_ops.transpose()
    weights = [[0.5, 0.2], [0.3, 0.4]]
    input_data = [1, 0.5]
    nn = NeuralNetwork(weights, input_data)
    forward_output = nn.forward_pass()
    activated_output = nn.activate(forward_output)
    print('Matrix Product:\n', product)
    print('Transposed A:\n', transposed_a)
    print('Neural Network Forward Pass Output:\n', forward_output)
    print('Activated Output:\n', activated_output)
if __name__ == '__main__':
    main()