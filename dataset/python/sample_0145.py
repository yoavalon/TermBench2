import numpy as np

def simulate_paths(S0, K, T, r, sigma, N, M):
    dt = T / N
    S = np.zeros((N + 1, M))
    S[0] = S0
    for i in range(1, N + 1):
        Z = np.random.standard_normal(M)
        S[i] = S[i - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * Z)
    return S

def option_price(paths, K, r, T):
    payoff = np.maximum(paths[-1] - K, 0)
    price = np.exp(-r * T) * np.mean(payoff)
    return price

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 100
    M = 10000
    paths = simulate_paths(S0, K, T, r, sigma, N, M)
    price = option_price(paths, K, r, T)
    print(price)
main()