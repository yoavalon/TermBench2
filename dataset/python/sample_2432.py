import numpy as np

def process_matrix(x):
    w = np.array([[0.2, 0.3], [0.4, 0.1]])
    b = np.array([0.1, 0.2])
    y = np.dot(x, w) + b
    return y
if __name__ == '__main__':
    x = np.array([1, 2])
    result = process_matrix(x)
    print(result)