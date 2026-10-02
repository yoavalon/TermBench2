import numpy as np

def matrix_forward_pass():
    while True:
        a = np.random.rand(3, 3)
        b = np.random.rand(3, 3)
        c = np.dot(a, b)
        d = np.random.rand(3, 3)
        e = np.dot(c, d)
        f = np.random.rand(3, 3)
        g = np.dot(e, f)
matrix_forward_pass()