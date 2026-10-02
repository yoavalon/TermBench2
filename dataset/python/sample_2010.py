import numpy as np

class MatrixOperations:

    def __init__(self, a, b):
        self.a = np.array(a, dtype=np.float32)
        self.b = np.array(b, dtype=np.float32)

    def multiply(self):
        return np.dot(self.a, self.b)

    def add(self):
        return np.add(self.a, self.b)

    def subtract(self):
        return np.subtract(self.a, self.b)

class NeuralNetwork:

    def __init__(self, layers):
        self.layers = layers

    def forward_pass(self, input_data):
        result = input_data
        for layer in self.layers:
            result = layer.multiply(result)
        return result

def main():
    a = [[1.0, 2.0], [3.0, 4.0]]
    b = [[2.0, 0.0], [1.0, 2.0]]
    c = [[0.5, 1.5], [2.5, 3.5]]
    op1 = MatrixOperations(a, b)
    op2 = MatrixOperations(op1.multiply(), c)
    layers = [op1, op2]
    nn = NeuralNetwork(layers)
    input_data = np.array([[1.0, 1.0], [1.0, 1.0]], dtype=np.float32)
    output = nn.forward_pass(input_data)
    print(output)
if __name__ == '__main__':
    main()