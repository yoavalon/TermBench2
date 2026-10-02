def calculate_option_price(S, K, r, T, sigma, N):
    import numpy as np
    dt = T / N
    dS = S * sigma * np.sqrt(dt)
    paths = S * np.exp((r - 0.5 * sigma ** 2) * dt + dS * np.random.randn(N))
    payoff = np.maximum(paths[-1] - K, 0)
    return np.exp(-r * T) * np.mean(payoff)
if __name__ == '__main__':
    result = calculate_option_price(100, 100, 0.05, 1, 0.2, 1000)
    print(result)