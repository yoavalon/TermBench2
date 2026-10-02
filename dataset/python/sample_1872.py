import numpy as np

def simulate_monte_carlo(S0, K, T, r, sigma, N):
    dt = T / N
    S = np.zeros(N + 1)
    S[0] = S0
    for i in range(1, N + 1):
        z = np.random.standard_normal()
        S[i] = S[i - 1] * np.exp((r - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    return np.exp(-r * T) * np.maximum(S[-1] - K, 0)

def main():
    S0, K, T, r, sigma, N = (100, 100, 1, 0.05, 0.2, 1000)
    option_price = simulate_monte_carlo(S0, K, T, r, sigma, N)
    print(option_price)
main()