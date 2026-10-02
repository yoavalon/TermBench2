import random

def generate_paths(S0, mu, sigma, T, N, M):
    dt = T / N
    paths = [[S0] for _ in range(M)]
    for _ in range(1, N + 1):
        for j in range(M):
            z = random.gauss(0, 1)
            S = paths[j][-1] * (1 + mu * dt + sigma * z * dt ** 0.5)
            paths[j].append(S)
    return paths

def payoff(paths, K, T):
    terminal_values = [path[-1] for path in paths]
    return [max(S - K, 0) for S in terminal_values]

def discount(payoffs, r, T):
    return [p / (1 + r) ** T for p in payoffs]

def main():
    S0 = 100
    K = 100
    r = 0.05
    T = 1
    N = 252
    M = 10000
    mu = 0.05
    sigma = 0.2
    paths = generate_paths(S0, mu, sigma, T, N, M)
    payoffs = payoff(paths, K, T)
    discounted_payoffs = discount(payoffs, r, T)
    option_price = sum(discounted_payoffs) / M
    print('Option Price:', option_price)
if __name__ == '__main__':
    main()