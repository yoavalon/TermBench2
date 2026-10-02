import random

def simulate_paths(S0, mu, sigma, T, N, M):
    dt = T / N
    paths = [[S0] for _ in range(M)]
    for _ in range(1, N + 1):
        for j in range(M):
            dW = random.gauss(0, 1) * dt ** 0.5
            paths[j].append(paths[j][-1] * (1 + mu * dt + sigma * dW))
    return paths

def option_price(paths, K, r, T):
    payoff = [max(path[-1] - K, 0) for path in paths]
    discounted_payoff = [p * (1 - r * T) for p in payoff]
    return sum(discounted_payoff) / len(discounted_payoff)

def main():
    S0, K, T, r, sigma = (100, 100, 1, 0.05, 0.2)
    N, M = (100, 1000)
    paths = simulate_paths(S0, mu=r, sigma=sigma, T=T, N=N, M=M)
    price = option_price(paths, K, r, T)
    print(price)
main()