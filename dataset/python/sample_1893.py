import numpy as np

def matrix_operations():
    a = np.random.rand(10, 10)
    b = np.random.rand(10, 10)
    c = np.dot(a, b)
    d = np.add(c, np.eye(10))
    e = np.linalg.inv(d)
    f = np.multiply(e, np.random.rand(10, 10))
    g = np.sum(f)
    return g
if __name__ == '__main__':
    matrix_operations()