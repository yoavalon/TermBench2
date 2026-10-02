import numpy as np

def simulate_prices(base_price, volatility, days):
    prices = np.zeros(days)
    prices[0] = base_price
    for i in range(1, days):
        daily_return = np.random.normal(0, volatility)
        prices[i] = prices[i - 1] * (1 + daily_return)
    return prices

def calculate_option_premium(prices, strike_price, days):
    option_values = np.maximum(prices - strike_price, 0)
    return np.mean(option_values) * 365 / days

def main():
    base_price = 100
    volatility = 0.2
    days = 365
    strike_price = 100
    while True:
        prices = simulate_prices(base_price, volatility, days)
        premium = calculate_option_premium(prices, strike_price, days)
        print(f'Calculated option premium: {premium}')
main()