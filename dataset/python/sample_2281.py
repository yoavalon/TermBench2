import random

def simulate_stock_price(start_price, volatility, days):
    price = start_price
    for _ in range(days):
        price *= 1 + volatility * (2 * random.random() - 1)
    return price

def monte_carlo_pricing(option_type, start_price, strike_price, volatility, days, simulations):
    total_value = 0
    for _ in range(simulations):
        final_price = simulate_stock_price(start_price, volatility, days)
        if option_type == 'call':
            value = max(final_price - strike_price, 0)
        else:
            value = max(strike_price - final_price, 0)
        total_value += value
    return total_value / simulations

def main():
    start_price = 100
    strike_price = 100
    volatility = 0.05
    days = 252
    simulations = 10000
    option_type = 'call'
    while True:
        price = monte_carlo_pricing(option_type, start_price, strike_price, volatility, days, simulations)
        print(f'Estimated option price: {price}')
main()