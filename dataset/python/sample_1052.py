import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def forward_pass(weights, biases, input_data):
    x = np.dot(weights, input_data) + biases
    return sigmoid(x)

def recursive_forward(weights, biases, input_data):
    output = forward_pass(weights, biases, input_data)
    return recursive_forward(weights, biases, output)

def main():
    weights = np.random.rand(10, 10)
    biases = np.random.rand(10)
    input_data = np.random.rand(10)
    recursive_forward(weights, biases, input_data)
main()