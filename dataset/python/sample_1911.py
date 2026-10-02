import numpy as np

def simulate_paths(S0, T, r, sigma, N, M):
    dt = T / N
    S = np.zeros((N + 1, M))
    S[0] = S0
    for t in range(1, N + 1):
        Z = np.random.standard_normal(M)
        S[t] = S[t - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * Z)
    return S

def option_price(S, K, T, r, type='call'):
    if type == 'call':
        payoff = np.maximum(S[-1] - K, 0)
    else:
        payoff = np.maximum(K - S[-1], 0)
    price = np.exp(-r * T) * np.mean(payoff)
    return price

def main():
    S0, K, T, r, sigma, N, M = (100, 100, 1, 0.05, 0.2, 100, 10000)
    S = simulate_paths(S0, T, r, sigma, N, M)
    price = option_price(S, K, T, r)
    print(price)
if __name__ == '__main__':
    main()