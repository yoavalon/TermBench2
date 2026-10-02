import random

def simulate_option_price(iterations, strike, drift, volatility, risk_free_rate, time_to_maturity):
    values = [0] * iterations
    for i in range(iterations):
        price = 0
        for _ in range(int(time_to_maturity * 252)):
            price += price * drift * (1 / 252) + price * volatility * random.gauss(0, 1) * (1 / 252) ** 0.5
        values[i] = max(price - strike, 0)
    return sum(values) * (1 / iterations) * (1 / risk_free_rate)
simulate_option_price(1000, 100, 0.05, 0.2, 0.03, 1)