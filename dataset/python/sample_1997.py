import numpy as np

def simulate_paths(S0, T, r, sigma, N, M):
    dt = T / N
    paths = np.zeros((N + 1, M))
    paths[0] = S0
    for t in range(1, N + 1):
        Z = np.random.standard_normal(M)
        paths[t] = paths[t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * Z)
    return paths

def option_price(paths, K, r, T, N):
    discounted_payoffs = np.exp(-r * T) * np.maximum(paths[-1] - K, 0)
    return np.mean(discounted_payoffs)

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 100
    M = 10000
    paths = simulate_paths(S0, T, r, sigma, N, M)
    price = option_price(paths, K, r, T, N)
    print(price)
main()