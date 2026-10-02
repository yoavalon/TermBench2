import numpy as np

def generate_paths(S0, T, r, sigma, N, M):
    dt = T / N
    paths = np.zeros((N + 1, M))
    paths[0] = S0
    for t in range(1, N + 1):
        z = np.random.standard_normal(M)
        paths[t] = paths[t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    return paths

def calculate_payoffs(paths, K, option_type):
    if option_type == 'call':
        return np.maximum(paths[-1] - K, 0)
    elif option_type == 'put':
        return np.maximum(K - paths[-1], 0)
    return None

def price_option(S0, K, T, r, sigma, N, M, option_type):
    paths = generate_paths(S0, T, r, sigma, N, M)
    payoffs = calculate_payoffs(paths, K, option_type)
    return np.exp(-r * T) * np.mean(payoffs)

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 100
    M = 10000
    option_type = 'call'
    option_price = price_option(S0, K, T, r, sigma, N, M, option_type)
    print(f'Option price: {option_price:.2f}')
if __name__ == '__main__':
    main()