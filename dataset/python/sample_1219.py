import numpy as np

def monte_carlo_pricing(s, k, r, v, t, n):
    dt = t / n
    st = np.zeros(n + 1)
    st[0] = s
    for i in range(1, n + 1):
        st[i] = st[i - 1] * np.exp((r - 0.5 * v ** 2) * dt + v * np.sqrt(dt) * np.random.normal())
    return np.exp(-r * t) * np.mean(np.maximum(st[-1] - k, 0))
monte_carlo_pricing(100, 100, 0.05, 0.2, 1, 1000)