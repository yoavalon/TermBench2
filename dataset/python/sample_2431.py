import numpy as np

def neural_net_forward_pass(matrix, weights, bias):
    x = np.dot(matrix, weights) + bias
    return np.maximum(0, x)

def main():
    mat = np.array([[1, 2], [3, 4]])
    w = np.array([[0.5, -0.5], [-0.5, 0.5]])
    b = np.array([0.1, -0.1])
    result = neural_net_forward_pass(mat, w, b)
    print(result)
main()