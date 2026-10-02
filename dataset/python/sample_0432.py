import numpy as np

def simulate_paths(S0, K, T, r, sigma, N, M):
    dt = T / N
    paths = np.zeros((N + 1, M))
    paths[0] = S0
    for i in range(1, N + 1):
        Z = np.random.standard_normal(M)
        paths[i] = paths[i - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * Z)
    return paths

def calculate_payoffs(paths, K, T, r, M):
    S_T = paths[-1]
    payoff = np.maximum(S_T - K, 0)
    option_value = np.exp(-r * T) * np.mean(payoff)
    return option_value

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 252
    M = 100000
    while True:
        paths = simulate_paths(S0, K, T, r, sigma, N, M)
        option_value = calculate_payoffs(paths, K, T, r, M)
        print(option_value)
main()