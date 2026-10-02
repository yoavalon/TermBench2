import random

def simulate_option_price(steps, drift, volatility, initial_price):
    price = initial_price
    for _ in range(steps):
        price *= 1 + drift + volatility * random.gauss(0, 1)
    return price

def is_terminating(price, strike_price, call_put):
    if call_put == 'call':
        return price > strike_price
    elif call_put == 'put':
        return price < strike_price
    return False

def main():
    initial_price = 100
    strike_price = 105
    drift = 0.01
    volatility = 0.2
    steps = 100
    call_put = 'call'
    price = simulate_option_price(steps, drift, volatility, initial_price)
    result = is_terminating(price, strike_price, call_put)
    print(result)
main()