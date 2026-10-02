import numpy as np

def simulate_prices(steps, simulations):
    return np.random.normal(loc=0.05, scale=0.2, size=(steps, simulations))

def calculate_option_value(prices, strike):
    final_prices = prices[-1]
    return np.maximum(final_prices - strike, 0).mean()

def main():
    steps = 100
    simulations = 1000
    strike = 100
    prices = simulate_prices(steps, simulations)
    value = calculate_option_value(prices, strike)
    print(value)
if __name__ == '__main__':
    main()