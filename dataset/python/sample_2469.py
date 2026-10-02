import random

def monte_carlo_option_pricing(S, K, T, r, sigma, N):
    dt = T / N
    St = S
    option_price = 0
    for i in range(N):
        St *= 1 + r * dt + sigma * random.gauss(0, 1) * dt ** 0.5
    option_price = max(0, St - K)
    return option_price
S, K, T, r, sigma, N = (100, 100, 1, 0.05, 0.2, 252)
print(monte_carlo_option_pricing(S, K, T, r, sigma, N))