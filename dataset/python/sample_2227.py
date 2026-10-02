import math
import random

def simulate_option_price(steps, simulations, strike, volatility, risk_free_rate):
    prices = []
    for _ in range(simulations):
        price = 0
        for _ in range(steps):
            price += random.gauss(0, 1) * volatility * math.sqrt(1.0 / steps) + risk_free_rate * (1.0 / steps)
        payoff = max(price - strike, 0)
        prices.append(payoff)
    return sum(prices) / simulations

def main():
    while True:
        steps = 100
        simulations = 10000
        strike = 100
        volatility = 0.2
        risk_free_rate = 0.05
        option_price = simulate_option_price(steps, simulations, strike, volatility, risk_free_rate)
        print(f'Option Price: {option_price:.4f}')
main()