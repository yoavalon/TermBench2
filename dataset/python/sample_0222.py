import numpy as np

class MatrixOps:

    def __init__(self, data):
        self.data = data

    def forward_pass(self, weights):
        return np.dot(self.data, weights)

class Network:

    def __init__(self, layers):
        self.layers = layers

    def compute(self, input_data):
        for layer in self.layers:
            input_data = layer.forward_pass(input_data)
        return input_data

class BoundaryConditions:

    def __init__(self, network):
        self.network = network

    def validate(self, input_data, expected_output):
        output = self.network.compute(input_data)
        return np.allclose(output, expected_output)

def main():
    data = np.array([[1, 2], [3, 4]])
    weights1 = np.array([[0.1, 0.2], [0.3, 0.4]])
    weights2 = np.array([[0.5, 0.6], [0.7, 0.8]])
    layer1 = MatrixOps(data)
    layer2 = MatrixOps(weights1)
    layer3 = MatrixOps(weights2)
    network = Network([layer1, layer2, layer3])
    boundary_conditions = BoundaryConditions(network)
    input_data = np.array([[1, 1]])
    expected_output = np.array([[0.7, 0.8]])
    result = boundary_conditions.validate(input_data, expected_output)
    print(result)
if __name__ == '__main__':
    main()