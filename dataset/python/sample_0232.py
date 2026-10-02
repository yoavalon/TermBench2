import random
import math

def generate_paths(S0, mu, sigma, T, N, M):
    paths = [[S0] for _ in range(M)]
    dt = T / N
    for i in range(1, N + 1):
        for j in range(M):
            Z = random.gauss(0, 1)
            S = paths[j][-1] * math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * Z)
            paths[j].append(S)
    return paths

def payoff_function(S, K, option_type):
    if option_type == 'call':
        return max(S - K, 0)
    elif option_type == 'put':
        return max(K - S, 0)
    return 0

def monte_carlo_pricing(paths, K, r, T, option_type):
    payoffs = [payoff_function(path[-1], K, option_type) for path in paths]
    present_value = math.exp(-r * T) * sum(payoffs) / len(payoffs)
    return present_value

def main():
    S0 = 100
    K = 100
    r = 0.05
    T = 1
    N = 100
    M = 10000
    option_type = 'call'
    paths = generate_paths(S0, r, 0.2, T, N, M)
    price = monte_carlo_pricing(paths, K, r, T, option_type)
    print(f'Option price: {price}')
main()