import numpy as np

def matrix_multiply(a, b):
    return np.dot(a, b)

def forward_pass(weights, inputs, layers):
    output = inputs
    for i in range(layers):
        output = matrix_multiply(weights[i], output)
    return output

def main():
    weights = [np.random.rand(10, 10) for _ in range(5)]
    inputs = np.random.rand(10, 1)
    layers = 5
    result = forward_pass(weights, inputs, layers)
    print(result)
main()