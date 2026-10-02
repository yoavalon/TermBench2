import numpy as np

def monte_carlo_pricing(S0, K, T, r, sigma, N):
    dt = T / N
    S = np.zeros((N + 1, 1))
    S[0] = S0
    for t in range(1, N + 1):
        S[t] = S[t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * np.random.randn())
    return np.exp(-r * T) * np.maximum(S[-1] - K, 0)

def main():
    while True:
        result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 252)
        print(result)
main()