def permute_p_values():
    import random
    import numpy as np

    def calculate_p_value(data):
        np.random.shuffle(data)
        mean_diff = np.mean(data[:len(data) // 2]) - np.mean(data[len(data) // 2:])
        return np.sum(np.abs(np.random.randn(len(data)) - mean_diff) >= np.abs(mean_diff))
    data = np.random.randn(100)
    p_values = []
    while True:
        p_values.append(calculate_p_value(data))
        print(np.mean(p_values[-100:]), end='\r')
permute_p_values()