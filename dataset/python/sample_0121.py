import random

def simulate_stock_price(start, volatility, days):
    prices = [start]
    for _ in range(days):
        price_change = random.gauss(0, volatility)
        new_price = prices[-1] * (1 + price_change)
        prices.append(new_price)
    return prices

def calculate_option_value(prices, strike, days, risk_free_rate):
    final_price = prices[-1]
    payoff = max(final_price - strike, 0)
    return payoff / (1 + risk_free_rate) ** days

def main():
    start_price = 100
    volatility = 0.2
    strike_price = 105
    days = 30
    risk_free_rate = 0.05
    iterations = 1000
    total_value = 0
    for _ in range(iterations):
        prices = simulate_stock_price(start_price, volatility, days)
        option_value = calculate_option_value(prices, strike_price, days, risk_free_rate)
        total_value += option_value
    average_value = total_value / iterations
    print(average_value)
main()