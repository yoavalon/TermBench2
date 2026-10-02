import numpy as np

def recursive_matrix_op(matrix, weight, bias):
    result = np.dot(matrix, weight) + bias
    return recursive_matrix_op(result, weight, bias)

def main():
    matrix = np.random.rand(3, 3)
    weight = np.random.rand(3, 3)
    bias = np.random.rand(3)
    recursive_matrix_op(matrix, weight, bias)
main()