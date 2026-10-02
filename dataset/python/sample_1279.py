import numpy as np

def monte_carlo_pricing(S, K, T, r, sigma, N, M):
    dt = T / M
    S_t = np.zeros((N, M + 1))
    S_t[:, 0] = S
    for t in range(1, M + 1):
        z = np.random.standard_normal(N)
        S_t[:, t] = S_t[:, t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    payoff = np.maximum(S_t[:, -1] - K, 0)
    option_price = np.exp(-r * T) * np.mean(payoff)
    return option_price
monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100)