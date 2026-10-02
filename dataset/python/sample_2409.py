import numpy as np

def forward_pass(matrix, weights):
    return np.dot(matrix, weights)

def main():
    matrix = np.array([[1, 2], [3, 4]])
    weights = np.array([[0.5, 0.5], [0.5, 0.5]])
    result = forward_pass(matrix, weights)
    print(result)
main()