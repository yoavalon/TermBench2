import random

def simulate_stock_price(steps, initial_price, drift, volatility):
    prices = [initial_price]
    for _ in range(steps):
        shock = random.gauss(0, 1)
        new_price = prices[-1] * (1 + drift + volatility * shock)
        prices.append(new_price)
    return prices

def option_pricing(prices, strike_price, is_call):
    payoff = 0
    for price in prices:
        if is_call:
            payoff += max(0, price - strike_price)
        else:
            payoff += max(0, strike_price - price)
    return payoff / len(prices)

def main():
    initial_price = 100
    strike_price = 105
    drift = 0.01
    volatility = 0.2
    steps = 100
    is_call = True
    prices = simulate_stock_price(steps, initial_price, drift, volatility)
    value = option_pricing(prices, strike_price, is_call)
    print(f'Option value: {value}')
main()