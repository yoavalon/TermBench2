import numpy as np

def forward_pass(weights, biases, inputs, depth):
    if depth == 0:
        return inputs
    return forward_pass(weights, biases, np.dot(inputs, weights) + biases, depth - 1)

def main():
    np.random.seed(0)
    weights = np.random.rand(3, 3)
    biases = np.random.rand(3)
    inputs = np.random.rand(3)
    result = forward_pass(weights, biases, inputs, 3)
    print(result)
main()