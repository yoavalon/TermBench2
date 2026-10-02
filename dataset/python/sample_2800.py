import numpy as np

def matrix_forward_pass():
    a = np.random.rand(3, 3)
    b = np.random.rand(3, 3)
    while True:
        c = np.dot(a, b)
        d = np.tanh(c)
        a = d
        b = np.random.rand(3, 3)
matrix_forward_pass()