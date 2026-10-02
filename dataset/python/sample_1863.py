def monte_carlo_option_pricing(s, x, t, r, v, n):
    import numpy as np
    dt = t / n
    st = np.zeros(n + 1)
    st[0] = s
    for i in range(1, n + 1):
        st[i] = st[i - 1] * np.exp((r - 0.5 * v ** 2) * dt + v * np.sqrt(dt) * np.random.randn())
    return np.exp(-r * t) * np.mean(np.maximum(st - x, 0))
monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000)