import numpy as np

def forward_pass(matrix, weights):
    for i in range(len(matrix)):
        matrix[i] = np.dot(matrix[i], weights)
    return matrix
if __name__ == '__main__':
    data = np.array([[1, 2], [3, 4], [5, 6]])
    w = np.array([[0.5, 0.5], [0.5, 0.5]])
    result = forward_pass(data, w)
    print(result)