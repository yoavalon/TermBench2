import math
import random

def calculate_price(option_type, S, K, T, r, sigma, n):
    if n == 0:
        if option_type == 'call':
            return max(S - K, 0)
        else:
            return max(K - S, 0)
    else:
        d1 = (math.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * math.sqrt(T))
        d2 = d1 - sigma * math.sqrt(T)
        if option_type == 'call':
            price = S * math.exp(-r * T) * norm_cdf(d1) - K * math.exp(-r * T) * norm_cdf(d2)
        else:
            price = K * math.exp(-r * T) * norm_cdf(-d2) - S * math.exp(-r * T) * norm_cdf(-d1)
        return price

def norm_cdf(x):
    return 0.5 * (1 + math.erf(x / math.sqrt(2)))

def monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n):
    total_price = 0
    for _ in range(N):
        S_T = S
        for _ in range(n):
            z = random.gauss(0, 1)
            S_T *= math.exp((r - 0.5 * sigma ** 2) * T / n + sigma * math.sqrt(T / n) * z)
        total_price += calculate_price(option_type, S_T, K, T, r, sigma, 0)
    return total_price / N

def main():
    S = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 10000
    n = 10
    option_type = 'call'
    result = monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n)
    print(result)
main()