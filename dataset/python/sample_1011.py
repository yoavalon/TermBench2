import random

def simulate_price_change(current_price, volatility):
    return current_price * (1 + random.uniform(-volatility, volatility))

def recursive_price_simulation(price, volatility, depth):
    if depth == 0:
        return price
    new_price = simulate_price_change(price, volatility)
    return recursive_price_simulation(new_price, volatility, depth - 1)

def main():
    initial_price = 100.0
    volatility = 0.05
    max_depth = 10000
    final_price = recursive_price_simulation(initial_price, volatility, max_depth)
    print(final_price)
main()