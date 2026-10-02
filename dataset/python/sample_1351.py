import numpy as np

def simulate_prices(steps, mean, volatility):
    prices = np.zeros(steps)
    prices[0] = 100
    for i in range(1, steps):
        prices[i] = prices[i - 1] * (1 + np.random.normal(mean, volatility))
    return prices

def calculate_option_value(prices, strike, r, t):
    payoff = np.maximum(prices[-1] - strike, 0)
    value = payoff * np.exp(-r * t)
    return value

def main():
    steps = 100
    mean = 0.001
    volatility = 0.01
    strike = 105
    r = 0.05
    t = 1.0
    prices = simulate_prices(steps, mean, volatility)
    option_value = calculate_option_value(prices, strike, r, t)
    print(option_value)
main()