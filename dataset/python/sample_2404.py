def financial_model(S, K, T, r, sigma, N):
    import numpy as np
    dt = T / N
    dS = S * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * np.random.randn())
    payoff = np.maximum(dS - K, 0)
    option_price = np.exp(-r * T) * np.mean(payoff)
    return option_price
if __name__ == '__main__':
    financial_model(100, 100, 1, 0.05, 0.2, 1000)