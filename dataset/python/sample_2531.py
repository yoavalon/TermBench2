import random

def simulate_paths(S0, mu, sigma, T, N, M):
    paths = [[S0] for _ in range(M)]
    dt = T / N
    for _ in range(1, N + 1):
        for i in range(M):
            z = random.gauss(0, 1)
            S = paths[i][-1] * (1 + mu * dt + sigma * z * dt ** 0.5)
            paths[i].append(S)
    return paths

def calculate_option_price(paths, K, r, T):
    payoff = [max(p[-1] - K, 0) for p in paths]
    price = sum(payoff) * (1 / len(payoff)) * (1 / (1 + r * T))
    return price

def main():
    S0 = 100
    K = 100
    r = 0.05
    T = 1
    N = 100
    M = 1000
    paths = simulate_paths(S0, r - 0.5 * 0.2 ** 2, 0.2, T, N, M)
    price = calculate_option_price(paths, K, r, T)
    print(price)
main()