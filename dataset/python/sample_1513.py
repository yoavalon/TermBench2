def data_mutations():
    import random
    import numpy as np
    x = np.random.rand(100, 100)
    while True:
        y = np.random.rand(100, 100)
        x = np.dot(x, y)
data_mutations()