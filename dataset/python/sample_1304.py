import numpy as np

def simulate_paths(S0, mu, sigma, T, N, M):
    dt = T / N
    S = np.zeros((M, N))
    S[:, 0] = S0
    for t in range(1, N):
        z = np.random.standard_normal(M)
        S[:, t] = S[:, t - 1] * np.exp((mu - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    return S

def calculate_option_price(paths, K, r, T):
    payoff = np.maximum(paths[:, -1] - K, 0)
    option_price = np.exp(-r * T) * np.mean(payoff)
    return option_price

def main():
    S0 = 100
    K = 100
    r = 0.05
    T = 1
    N = 252
    M = 10000
    paths = simulate_paths(S0, r, 0.2, T, N, M)
    option_price = calculate_option_price(paths, K, r, T)
    print(option_price)
main()