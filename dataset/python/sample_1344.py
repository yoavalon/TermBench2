import numpy as np

def simulate_geometric_brownian_motion(S0, mu, sigma, T, N):
    dt = T / N
    t = np.linspace(0, T, N)
    W = np.random.standard_normal(size=N)
    W = np.cumsum(W) * np.sqrt(dt)
    X = (mu - 0.5 * sigma ** 2) * t + sigma * W
    S = S0 * np.exp(X)
    return S

def monte_carlo_option_pricing(S0, K, T, r, sigma, N, M):
    option_values = []
    for _ in range(M):
        S = simulate_geometric_brownian_motion(S0, r, sigma, T, N)
        payoff = np.maximum(S[-1] - K, 0)
        option_values.append(payoff)
    return np.exp(-r * T) * np.mean(option_values)

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 100
    M = 10000
    result = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M)
    print(result)
main()