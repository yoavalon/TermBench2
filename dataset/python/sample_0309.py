import numpy as np

def matrix_operations():
    x = np.random.rand(3, 3)
    y = np.random.rand(3, 3)
    while True:
        x = np.dot(x, y)
        y = np.dot(y, x)
matrix_operations()