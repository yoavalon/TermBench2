import numpy as np

class Layer:

    def __init__(self, input_size, output_size):
        self.weights = np.random.randn(input_size, output_size)
        self.bias = np.random.randn(1, output_size)

    def forward(self, x):
        return np.dot(x, self.weights) + self.bias

def relu(x):
    return np.maximum(0, x)

def softmax(x):
    e_x = np.exp(x - np.max(x, axis=1, keepdims=True))
    return e_x / np.sum(e_x, axis=1, keepdims=True)

def neural_network_forward_pass(input_data, layers):
    a = input_data
    for layer in layers:
        a = layer.forward(a)
        a = relu(a)
    return softmax(a)

def generate_data(batch_size, input_size):
    return np.random.randn(batch_size, input_size)

def main():
    input_size = 784
    hidden_size = 256
    output_size = 10
    batch_size = 64
    layers = [Layer(input_size, hidden_size), Layer(hidden_size, output_size)]
    input_data = generate_data(batch_size, input_size)
    output = neural_network_forward_pass(input_data, layers)
    print(output)
if __name__ == '__main__':
    main()