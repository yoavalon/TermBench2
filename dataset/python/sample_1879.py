import numpy as np

def monte_carlo_pricing(S, K, T, r, sigma, N):
    dt = T / N
    mu = r - 0.5 * sigma ** 2
    S_paths = np.zeros((N + 1, S.shape[0]))
    S_paths[0] = S
    for t in range(1, N + 1):
        z = np.random.standard_normal(S.shape)
        S_paths[t] = S_paths[t - 1] * np.exp(mu * dt + sigma * np.sqrt(dt) * z)
    payoff = np.maximum(S_paths[-1] - K, 0)
    return np.exp(-r * T) * np.mean(payoff)
main = lambda: monte_carlo_pricing(np.array([100]), 100, 1, 0.05, 0.2, 100000)