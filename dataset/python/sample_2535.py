import numpy as np

def simulate_paths(S0, T, r, sigma, N, M):
    dt = T / N
    paths = np.zeros((N + 1, M))
    paths[0] = S0
    for i in range(1, N + 1):
        z = np.random.standard_normal(M)
        paths[i] = paths[i - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    return paths

def calculate_payoff(paths, K, T):
    ST = paths[-1]
    payoff = np.maximum(ST - K, 0)
    return payoff

def monte_carlo_pricing(S0, K, T, r, sigma, N, M):
    paths = simulate_paths(S0, T, r, sigma, N, M)
    payoff = calculate_payoff(paths, K, T)
    option_price = np.exp(-r * T) * np.mean(payoff)
    return option_price

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 100
    M = 10000
    price = monte_carlo_pricing(S0, K, T, r, sigma, N, M)
    print(f'Option Price: {price}')
main()