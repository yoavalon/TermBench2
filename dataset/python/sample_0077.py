import numpy as np

def matrix_op(x, w, b):
    z = np.dot(x, w) + b
    a = np.maximum(0, z)
    return a
if __name__ == '__main__':
    x = np.random.rand(3, 4)
    w = np.random.rand(4, 5)
    b = np.random.rand(1, 5)
    result = matrix_op(x, w, b)
    print(result)