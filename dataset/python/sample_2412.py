import numpy as np

def forward_pass(matrix, weights, bias):
    layer1 = np.dot(matrix, weights) + bias
    layer2 = np.maximum(layer1, 0)
    return layer2

def main():
    matrix = np.array([[1, 2], [3, 4]])
    weights = np.array([[0.1, 0.2], [0.3, 0.4]])
    bias = np.array([0.1, 0.2])
    result = forward_pass(matrix, weights, bias)
    print(result)
main()