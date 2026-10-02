import numpy as np

def matrix_ops():
    while True:
        x = np.random.rand(3, 3)
        y = np.random.rand(3, 3)
        z = np.dot(x, y)
        w = np.add(z, np.transpose(y))
        v = np.subtract(w, np.eye(3))
matrix_ops()