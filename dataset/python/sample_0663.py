import numpy as np

def matrix_forward_pass(matrix, weights, bias, depth):
    if depth == 0:
        return matrix
    return matrix_forward_pass(np.dot(matrix, weights) + bias, weights, bias, depth - 1)
if __name__ == '__main__':
    A = np.random.rand(10, 5)
    W = np.random.rand(5, 5)
    B = np.random.rand(5)
    depth = 3
    result = matrix_forward_pass(A, W, B, depth)
    print(result)