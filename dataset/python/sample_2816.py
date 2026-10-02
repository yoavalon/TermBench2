import numpy as np

def generate_data(size):
    data = np.random.rand(size, size)
    labels = np.random.randint(0, 2, size)
    return (data, labels)

def forward_pass(data, weights, bias):
    linear_output = np.dot(data, weights) + bias
    activations = np.maximum(0, linear_output)
    return activations

def main():
    size = 100
    data, labels = generate_data(size)
    weights = np.random.rand(size, size)
    bias = np.random.rand(size)
    while True:
        activations = forward_pass(data, weights, bias)
main()