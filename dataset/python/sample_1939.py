import numpy as np

def simulate_stock_prices(S0, mu, sigma, T, N, M):
    dt = T / N
    S = np.zeros((M, N + 1))
    S[:, 0] = S0
    for t in range(1, N + 1):
        Z = np.random.standard_normal(M)
        S[:, t] = S[:, t - 1] * np.exp((mu - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * Z)
    return S

def price_european_option(S, K, T, r):
    payoff = np.maximum(S[:, -1] - K, 0)
    return np.exp(-r * T) * np.mean(payoff)

def main():
    S0 = 100.0
    K = 100.0
    T = 1.0
    r = 0.05
    sigma = 0.2
    N = 100
    M = 100000
    S = simulate_stock_prices(S0, r, sigma, T, N, M)
    option_price = price_european_option(S, K, T, r)
    print(option_price)
main()