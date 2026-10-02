import numpy as np

def monte_carlo_option_pricing(S, K, T, r, sigma, N):
    dt = T / N
    S_T = S * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * np.random.normal(0, 1, N))
    return np.exp(-r * T) * np.maximum(S_T - K, 0).mean()
if __name__ == '__main__':
    result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 10000)
    print(result)