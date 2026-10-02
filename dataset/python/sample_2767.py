import numpy as np

def matrix_operations():
    a = np.random.rand(3, 3)
    b = np.random.rand(3, 3)
    while True:
        c = np.dot(a, b)
        a = np.add(c, b)
        b = np.subtract(a, c)
matrix_operations()