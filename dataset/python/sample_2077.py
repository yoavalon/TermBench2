import numpy as np

class MatrixOperations:

    def __init__(self, data):
        self.data = data

    def forward_pass(self, weights):
        return np.dot(self.data, weights)

    def activation_function(self, x):
        return np.maximum(0, x)

    def process(self, weights):
        intermediate = self.forward_pass(weights)
        return self.activation_function(intermediate)

class NeuralNetwork:

    def __init__(self, layers):
        self.layers = layers

    def predict(self, input_data):
        result = input_data
        for layer in self.layers:
            result = layer.process(result)
        return result

def generate_random_data(shape):
    return np.random.rand(*shape)

def main():
    input_shape = (10, 5)
    weight_shape = (5, 3)
    num_layers = 3
    input_data = generate_random_data(input_shape)
    weights = generate_random_data(weight_shape)
    layers = [MatrixOperations(generate_random_data(weight_shape)) for _ in range(num_layers)]
    nn = NeuralNetwork(layers)
    output = nn.predict(input_data)
    print(output)
if __name__ == '__main__':
    main()