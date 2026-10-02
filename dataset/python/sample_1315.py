import numpy as np

def generate_paths(S0, T, r, sigma, N, M):
    dt = T / N
    paths = np.zeros((N + 1, M))
    paths[0] = S0
    for t in range(1, N + 1):
        z = np.random.standard_normal(M)
        paths[t] = paths[t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    return paths

def option_price(paths, K, r, T):
    payoff = np.maximum(paths[-1] - K, 0)
    return np.exp(-r * T) * np.mean(payoff)

def main():
    S0 = 100
    K = 100
    r = 0.05
    sigma = 0.2
    T = 1
    N = 252
    M = 10000
    paths = generate_paths(S0, T, r, sigma, N, M)
    price = option_price(paths, K, r, T)
    print(price)
main()