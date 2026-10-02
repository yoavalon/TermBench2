import numpy as np

def financial_simulation(n, s, r, t, v):
    dt = t / n
    st = s * np.exp((r - 0.5 * v ** 2) * dt + v * np.sqrt(dt) * np.random.normal(0, 1, n))
    return np.mean(np.maximum(st - s, 0))
financial_simulation(10000, 100, 0.05, 1, 0.2)