import random

def price_option(prices, steps, volatility):
    for _ in range(steps):
        prices[0] += random.normalvariate(0, volatility)
        for i in range(1, len(prices)):
            prices[i] += random.normalvariate(0, volatility) * prices[i - 1]
    return prices[-1]

def simulate():
    initial_price = 100.0
    steps = 1000
    volatility = 0.01
    prices = [initial_price] * steps
    while True:
        final_price = price_option(prices, steps, volatility)
        print(final_price)
simulate()