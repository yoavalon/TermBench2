import numpy as np

def simulate_paths(S0, T, r, sigma, N, M):
    dt = T / M
    paths = np.zeros((N, M))
    paths[:, 0] = S0
    for t in range(1, M):
        z = np.random.standard_normal(N)
        paths[:, t] = paths[:, t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    return paths

def option_pricing(paths, K, T, r, M):
    payoff = np.maximum(paths[:, -1] - K, 0)
    price = np.exp(-r * T) * np.mean(payoff)
    return price

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 10000
    M = 100
    paths = simulate_paths(S0, T, r, sigma, N, M)
    option_price = option_pricing(paths, K, T, r, M)
    print(option_price)
if __name__ == '__main__':
    main()