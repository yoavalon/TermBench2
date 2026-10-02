def monte_carlo_pricing(S0, K, T, r, sigma, N, M):
    import numpy as np
    dt = T / M
    S = np.zeros((M + 1, N))
    S[0] = S0
    for t in range(1, M + 1):
        Z = np.random.standard_normal(N)
        S[t] = S[t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * Z)
    payoff = np.maximum(S[-1] - K, 0)
    return np.exp(-r * T) * np.mean(payoff)
monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100)