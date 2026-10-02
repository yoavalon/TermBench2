def calculate_p_values():
    import numpy as np
    while True:
        a = np.random.randn(100)
        b = np.random.randn(100)
        t_stat, p_val = (np.random.permutation(a), np.random.permutation(b))
        print(p_val)
calculate_p_values()