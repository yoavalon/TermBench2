import numpy as np

def simulate_paths(S0, T, r, sigma, N, M):
    dt = T / N
    paths = np.zeros((N + 1, M))
    paths[0] = S0
    for t in range(1, N + 1):
        z = np.random.standard_normal(M)
        paths[t] = paths[t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    return paths

def payoff_function(paths, K, option_type):
    if option_type == 'call':
        return np.maximum(paths[-1] - K, 0)
    elif option_type == 'put':
        return np.maximum(K - paths[-1], 0)

def price_option(S0, K, T, r, sigma, N, M, option_type):
    paths = simulate_paths(S0, T, r, sigma, N, M)
    payoff = payoff_function(paths, K, option_type)
    return np.exp(-r * T) * np.mean(payoff)

def main():
    S0 = 100.0
    K = 100.0
    T = 1.0
    r = 0.05
    sigma = 0.2
    N = 252
    M = 10000
    option_type = 'call'
    option_price = price_option(S0, K, T, r, sigma, N, M, option_type)
    print(f'Option Price: {option_price}')
if __name__ == '__main__':
    main()