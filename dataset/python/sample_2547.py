import random

def simulate_stock_price(days, initial_price, volatility):
    price = initial_price
    prices = [price]
    for _ in range(days):
        price *= 1 + volatility * random.gauss(0, 1)
        prices.append(price)
    return prices

def calculate_option_value(prices, strike_price, days, risk_free_rate):
    final_price = prices[-1]
    payoff = max(final_price - strike_price, 0)
    discount_factor = 1 / (1 + risk_free_rate) ** days
    return payoff * discount_factor

def main():
    days = 30
    initial_price = 100
    volatility = 0.2
    strike_price = 105
    risk_free_rate = 0.05
    prices = simulate_stock_price(days, initial_price, volatility)
    option_value = calculate_option_value(prices, strike_price, days, risk_free_rate)
    print(f'Option value: {option_value}')
main()