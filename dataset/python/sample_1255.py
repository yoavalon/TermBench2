import numpy as np

def forward_pass(matrix, weights, bias):
    x = np.dot(matrix, weights) + bias
    return np.tanh(x)
if __name__ == '__main__':
    data = np.array([[1, 2], [3, 4]])
    w = np.array([[0.1, 0.2], [0.3, 0.4]])
    b = np.array([0.1, 0.2])
    result = forward_pass(data, w, b)
    print(result)