import numpy as np

def simulate_paths(S0, mu, sigma, T, N, M):
    dt = T / N
    paths = np.zeros((N + 1, M))
    paths[0] = S0
    for t in range(1, N + 1):
        rand = np.random.standard_normal(M)
        paths[t] = paths[t - 1] * np.exp((mu - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * rand)
    return paths

def option_price(paths, K, r, T):
    payoff = np.maximum(paths[-1] - K, 0)
    return np.exp(-r * T) * np.mean(payoff)

def main():
    S0 = 100
    K = 100
    r = 0.05
    T = 1
    N = 252
    M = 10000
    paths = simulate_paths(S0, r, 0.2, T, N, M)
    price = option_price(paths, K, r, T)
    print(f'Option Price: {price:.4f}')
main()