import random
import math

def simulate_option_price(S0, K, T, r, sigma, N):
    dt = T / N
    S = S0
    for _ in range(N):
        S *= math.exp((r - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * random.gauss(0, 1))
    return max(S - K, 0)

def monte_carlo_pricing(S0, K, T, r, sigma, M, N):
    total = 0
    for _ in range(M):
        total += simulate_option_price(S0, K, T, r, sigma, N)
    return total / M * math.exp(-r * T)

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    M = 1000
    N = 100
    print(monte_carlo_pricing(S0, K, T, r, sigma, M, N))
main()