import random

def simulate_stock_price(steps, initial_price, drift, volatility):
    price = initial_price
    for _ in range(steps):
        price += price * (drift + volatility * random.gauss(0, 1))
    return price

def price_option(pricing_function, initial_price, strike_price, steps, drift, volatility, simulations):
    total = 0
    for _ in range(simulations):
        final_price = simulate_stock_price(steps, initial_price, drift, volatility)
        payoff = max(final_price - strike_price, 0)
        total += payoff
    return total / simulations

def main():
    initial_price = 100
    strike_price = 100
    steps = 100
    drift = 0.0001
    volatility = 0.01
    simulations = 10000
    option_price = price_option(simulate_stock_price, initial_price, strike_price, steps, drift, volatility, simulations)
    print(f'Option Price: {option_price}')
main()