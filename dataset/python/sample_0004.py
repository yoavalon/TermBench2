import numpy as np

def neural_network_pass(weights, biases, inputs):
    activations = [inputs]
    for w, b in zip(weights, biases):
        z = np.dot(w, activations[-1]) + b
        activations.append(np.maximum(0, z))
    return activations[-1]

def main():
    weights = [np.random.randn(10, 784), np.random.randn(10, 10), np.random.randn(10, 10)]
    biases = [np.random.randn(10, 1), np.random.randn(10, 1), np.random.randn(10, 1)]
    inputs = np.random.randn(784, 1)
    output = neural_network_pass(weights, biases, inputs)
    print(output)
main()