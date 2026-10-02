import numpy as np

def financial_model(S0, K, T, r, sigma):
    N = 10000
    dt = T / N
    S = np.zeros((N + 1, N + 1))
    S[0, 0] = S0
    for t in range(1, N + 1):
        for i in range(t + 1):
            Z = np.random.standard_normal()
            S[t, i] = S[t - 1, i - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * Z)
    return np.mean(np.maximum(S[N] - K, 0))
main = lambda: print(financial_model(100, 100, 1, 0.05, 0.2))
main()