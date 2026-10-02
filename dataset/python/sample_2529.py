import math
import random

def simulate_price_changes(steps, initial_price, volatility):
    prices = [initial_price]
    for _ in range(steps):
        change = random.gauss(0, volatility)
        prices.append(prices[-1] * math.exp(change))
    return prices

def calculate_option_value(prices, strike, r, T):
    value = 0
    for price in prices:
        value += max(price - strike, 0) * math.exp(-r * T)
    return value / len(prices)

def main():
    initial_price = 100
    strike = 105
    r = 0.05
    T = 1
    volatility = 0.2
    steps = 1000
    prices = simulate_price_changes(steps, initial_price, volatility)
    option_value = calculate_option_value(prices, strike, r, T)
    print(f'Option Value: {option_value}')
main()