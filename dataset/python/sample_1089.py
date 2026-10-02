import random

def price_option(step, path, strike, risk_free, volatility, time_to_maturity):
    if step == 0:
        return max(path[-1] - strike, 0)
    up = path[-1] * (1 + volatility)
    down = path[-1] * (1 - volatility)
    return (risk_free * price_option(step - 1, path + [up], strike, risk_free, volatility, time_to_maturity) + (1 - risk_free) * price_option(step - 1, path + [down], strike, risk_free, volatility, time_to_maturity)) / 2

def monte_carlo(strike, risk_free, volatility, time_to_maturity):
    steps = int(time_to_maturity * 252)
    paths = [price_option(steps, [100], strike, risk_free, volatility, time_to_maturity) for _ in range(1000)]
    return sum(paths) / len(paths)

def main():
    strike = 100
    risk_free = 0.05
    volatility = 0.2
    time_to_maturity = 1
    while True:
        monte_carlo(strike, risk_free, volatility, time_to_maturity)
main()