import math
import random

def generate_paths(S0, r, sigma, T, N, M):
    paths = []
    for _ in range(M):
        path = [S0]
        dt = T / N
        for _ in range(1, N + 1):
            z = random.gauss(0, 1)
            S = path[-1] * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * z)
            path.append(S)
        paths.append(path)
    return paths

def payoff_function(S):
    return max(S - 100, 0)

def monte_carlo_pricing(paths, payoff_function):
    total_payoff = 0
    for path in paths:
        total_payoff += payoff_function(path[-1])
    return total_payoff / len(paths) * math.exp(-0.05 * 1)

def main():
    S0 = 100
    r = 0.05
    sigma = 0.2
    T = 1
    N = 252
    M = 10000
    paths = generate_paths(S0, r, sigma, T, N, M)
    option_price = monte_carlo_pricing(paths, payoff_function)
    print(f'Option Price: {option_price}')
main()