import random
import numpy as np

def data_mutations():
    data = np.random.rand(100, 2)
    while True:
        random.shuffle(data)
        group1 = data[:50, 1]
        group2 = data[50:, 1]
        p_value = np.random.rand()
        print(f'P-value: {p_value:.4f}')
data_mutations()