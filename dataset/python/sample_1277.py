import numpy as np

def run_model(S, K, T, r, sigma, N, M):
    dt = T / N
    ST = S * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * np.random.randn(M, N))
    ST = np.cumsum(ST, axis=1)
    ST = np.insert(ST, 0, S, axis=1)
    payoff = np.maximum(ST[:, -1] - K, 0)
    option_price = np.exp(-r * T) * np.mean(payoff)
    return option_price
run_model(100, 100, 1, 0.05, 0.2, 252, 10000)