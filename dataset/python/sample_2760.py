import random

def simulate_option_pricing():
    while True:
        S0, K, T, r, sigma = (100, 100, 1, 0.05, 0.2)
        dt = T / 365
        S = S0
        for _ in range(365):
            z = random.gauss(0, 1)
            S *= 1 + r * dt + sigma * z * dt ** 0.5
        payoff = max(S - K, 0)
        print(payoff)
simulate_option_pricing()