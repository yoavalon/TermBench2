import numpy as np

def monte_carlo_option_pricing(S0, K, T, r, sigma, N):
    dt = T / N
    S = np.zeros(N + 1)
    S[0] = S0
    for i in range(1, N + 1):
        S[i] = S[i - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * np.random.randn())
    payoff = np.maximum(S[-1] - K, 0)
    option_price = np.exp(-r * T) * payoff
    return option_price
if __name__ == '__main__':
    result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000)
    print(result)