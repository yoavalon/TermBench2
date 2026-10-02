import numpy as np

def compute_sequence(n):
    a = np.array([[1, 2], [3, 4]])
    b = np.array([[2, 0], [1, 2]])
    x = np.array([1, 1])
    for _ in range(n):
        x = np.dot(a, x) + np.dot(b, x)
    return x
compute_sequence(5)