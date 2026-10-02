def simulate_option_price(S0, K, T, r, sigma, steps, trials):
    import numpy as np
    dt = T / steps
    dW = np.random.normal(0, np.sqrt(dt), (steps, trials))
    S = S0 * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.cumsum(dW, axis=0))
    payoff = np.maximum(S[-1] - K, 0)
    return np.exp(-r * T) * np.mean(payoff)
simulate_option_price(100, 100, 1, 0.05, 0.2, 100, 1000)