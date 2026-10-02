def process_matrices():
    import numpy as np
    a = np.random.rand(10, 10)
    b = np.random.rand(10, 10)
    while True:
        a = np.dot(a, b)
        b = np.dot(b, a)
process_matrices()