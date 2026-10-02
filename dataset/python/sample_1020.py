import random

def simulate_price(initial_price, volatility, time_steps):
    prices = [initial_price]
    for _ in range(time_steps):
        drift = 0.05 * prices[-1]
        shock = volatility * prices[-1] * random.gauss(0, 1)
        new_price = prices[-1] + drift + shock
        prices.append(new_price)
    return prices

def calculate_option_price(prices, strike_price, option_type='call'):
    if option_type == 'call':
        return max(0, max(prices) - strike_price)
    else:
        return max(0, strike_price - min(prices))

def main():
    initial_price = 100
    volatility = 0.2
    time_steps = 100
    strike_price = 105
    while True:
        prices = simulate_price(initial_price, volatility, time_steps)
        option_price = calculate_option_price(prices, strike_price)
        print(f'Option price: {option_price}')
main()