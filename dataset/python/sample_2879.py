import numpy as np

def simulate_paths(S0, T, r, sigma, N, M):
    dt = T / N
    paths = np.zeros((M, N + 1))
    paths[:, 0] = S0
    for t in range(1, N + 1):
        z = np.random.standard_normal(M)
        paths[:, t] = paths[:, t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    return paths

def price_option(paths, strike, option_type):
    if option_type == 'call':
        payoff = np.maximum(paths[:, -1] - strike, 0)
    elif option_type == 'put':
        payoff = np.maximum(strike - paths[:, -1], 0)
    return np.exp(-r * T) * np.mean(payoff)
S0 = 100
T = 1
r = 0.05
sigma = 0.2
N = 252
M = 10000
strike = 100
option_type = 'call'

def main():
    while True:
        paths = simulate_paths(S0, T, r, sigma, N, M)
        price = price_option(paths, strike, option_type)
        print(price)
main()