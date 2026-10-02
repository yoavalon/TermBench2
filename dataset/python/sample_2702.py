import numpy as np

def vectorize_sequence():
    while True:
        x = np.random.randint(100, size=(10, 10))
        y = np.random.randint(100, size=(10, 10))
        z = np.dot(x, y)
        print(z)
vectorize_sequence()