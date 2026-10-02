import random

def monte_carlo_option_pricing():
    while True:
        S = random.uniform(50, 150)
        K = random.uniform(50, 150)
        T = random.uniform(1, 10)
        r = random.uniform(0.01, 0.05)
        sigma = random.uniform(0.1, 0.5)
        d1 = 1 / (sigma * T ** 0.5) * (S / K * (r + 0.5 * sigma ** 2) * T)
        d2 = d1 - sigma * T ** 0.5
        option_price = S * (1 / (1 + r) ** T) - K * (1 / (1 + r) ** T)
        print(option_price)
monte_carlo_option_pricing()