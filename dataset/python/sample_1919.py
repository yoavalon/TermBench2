import numpy as np

def generate_paths(S0, r, sigma, T, M, N):
    dt = T / M
    paths = np.zeros((M + 1, N))
    paths[0] = S0
    for t in range(1, M + 1):
        z = np.random.standard_normal(N)
        paths[t] = paths[t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    return paths

def price_option(paths, strike, T, r):
    payoff = np.maximum(paths[-1] - strike, 0)
    return np.exp(-r * T) * np.mean(payoff)

def main():
    S0, r, sigma, T, M, N, K = (100, 0.05, 0.2, 1, 100, 1000, 100)
    paths = generate_paths(S0, r, sigma, T, M, N)
    option_price = price_option(paths, K, T, r)
    print(f'Option Price: {option_price}')
main()