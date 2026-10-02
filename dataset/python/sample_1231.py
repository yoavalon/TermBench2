import numpy as np

def data_mutations(matrix, weights, bias):
    x = np.dot(matrix, weights) + bias
    y = np.tanh(x)
    return y
if __name__ == '__main__':
    a = np.array([[1, 2], [3, 4]])
    b = np.array([[0.1, 0.2], [0.3, 0.4]])
    c = np.array([0.1, 0.2])
    result = data_mutations(a, b, c)
    print(result)