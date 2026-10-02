import numpy as np

def financial_model(S, K, T, r, sigma, N, M):
    dt = T / N
    S_t = S
    for _ in range(N):
        z = np.random.standard_normal(M)
        S_t = S_t * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    payoff = np.maximum(S_t - K, 0)
    option_price = np.exp(-r * T) * np.mean(payoff)
    return option_price
result = financial_model(100, 100, 1, 0.05, 0.2, 100, 10000)
print(result)