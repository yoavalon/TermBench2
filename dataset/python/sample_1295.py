import numpy as np

def financial_model(T, N, S0, K, r, sigma):
    dt = T / N
    S = np.zeros((N + 1, N + 1))
    S[0, 0] = S0
    for i in range(1, N + 1):
        for j in range(i + 1):
            S[i, j] = S[i - 1, j - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * np.random.randn()) if j > 0 else 0
    payoff = np.maximum(S[-1, :] - K, 0)
    option_price = np.exp(-r * T) * np.mean(payoff)
    return option_price
result = financial_model(1, 100, 100, 100, 0.05, 0.2)
print(result)