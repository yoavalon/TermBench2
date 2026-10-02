import random

def generate_random_walk(steps):
    walk = [0]
    for _ in range(steps):
        walk.append(walk[-1] + random.choice([-1, 1]))
    return walk

def monte_carlo_option_pricing(initial_price, strike_price, volatility, days):
    simulations = 1000
    price_paths = [generate_random_walk(days) for _ in range(simulations)]
    payoffs = [max(0, initial_price + path[-1] - strike_price) for path in price_paths]
    option_price = sum(payoffs) / simulations
    return option_price

def main():
    while True:
        result = monte_carlo_option_pricing(100, 100, 0.2, 252)
        print(f'Option Price: {result}')
main()