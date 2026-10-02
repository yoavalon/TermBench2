import numpy as np

def monte_carlo_pricing(S, K, T, r, sigma, N):
    dt = T / N
    S_t = np.zeros(N + 1)
    S_t[0] = S
    z = np.random.standard_normal(size=N)
    for i in range(1, N + 1):
        S_t[i] = S_t[i - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z[i - 1])
    payoff = np.maximum(S_t[-1] - K, 0)
    option_price = np.exp(-r * T) * np.mean(payoff)
    return option_price
if __name__ == '__main__':
    result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000)
    print(result)