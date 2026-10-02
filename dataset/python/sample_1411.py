import random
import math

def simulate_paths(S0, mu, sigma, T, N, M):
    dt = T / N
    paths = [[S0] for _ in range(M)]
    for t in range(1, N + 1):
        for i in range(M):
            z = random.gauss(0, 1)
            paths[i].append(paths[i][-1] * math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * z))
    return paths

def calculate_payoffs(paths, K, T, r, type='call'):
    payoffs = []
    for path in paths:
        ST = path[-1]
        if type == 'call':
            payoff = max(0, ST - K)
        else:
            payoff = max(0, K - ST)
        payoffs.append(payoff * math.exp(-r * T))
    return payoffs

def monte_carlo_pricing(S0, K, T, r, sigma, M):
    paths = simulate_paths(S0, r, sigma, T, 100, M)
    payoffs = calculate_payoffs(paths, K, T, r)
    return sum(payoffs) / M

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    M = 10000
    price = monte_carlo_pricing(S0, K, T, r, sigma, M)
    print(f'Option Price: {price:.2f}')
main()