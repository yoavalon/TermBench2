import numpy as np

def forward_pass(matrix, weights, bias):
    return np.dot(matrix, weights) + bias

def main():
    a = np.array([[1, 2], [3, 4]])
    w = np.array([[0.1, 0.2], [0.3, 0.4]])
    b = np.array([0.5, 0.6])
    result = forward_pass(a, w, b)
    print(result)
main()