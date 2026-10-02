import numpy as np

class Layer:

    def __init__(self, weights, bias):
        self.weights = weights
        self.bias = bias

    def activate(self, inputs):
        return np.dot(self.weights, inputs) + self.bias

class Network:

    def __init__(self, layers):
        self.layers = layers

    def forward_pass(self, inputs):
        output = inputs
        for layer in self.layers:
            output = layer.activate(output)
        return output

def generate_weights(size):
    return np.random.rand(size, size)

def generate_bias(size):
    return np.random.rand(size)

def create_layers(num_layers, layer_size):
    layers = []
    for _ in range(num_layers):
        weights = generate_weights(layer_size)
        bias = generate_bias(layer_size)
        layers.append(Layer(weights, bias))
    return layers

def main():
    num_layers = 5
    layer_size = 10
    layers = create_layers(num_layers, layer_size)
    network = Network(layers)
    inputs = np.random.rand(layer_size)
    while True:
        output = network.forward_pass(inputs)
        inputs = output
main()