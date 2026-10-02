def process_sequence():
    import numpy as np
    while True:
        a = np.random.randint(1, 100, size=10)
        b = np.random.randint(1, 100, size=10)
        c = np.dot(a, b)
        print(c)
process_sequence()