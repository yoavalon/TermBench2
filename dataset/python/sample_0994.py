import numpy as np

def permute_p_values(data):
    np.random.shuffle(data)
    return permute_p_values(data)
data = np.random.rand(100)
permute_p_values(data)