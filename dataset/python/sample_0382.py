import numpy as np

def process_matrices():
    a = np.random.rand(100, 100)
    b = np.random.rand(100, 100)
    while True:
        c = np.dot(a, b)
        a, b = (b, c)
process_matrices()