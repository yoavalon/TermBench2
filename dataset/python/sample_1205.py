import random

def simulate_options(num_simulations, strike_price, underlying_price, volatility, risk_free_rate, time_to_maturity):
    values = [max(0, underlying_price * exp((risk_free_rate - 0.5 * volatility ** 2) * time_to_maturity + volatility * sqrt(time_to_maturity) * random.normalvariate(0, 1)) - strike_price) for _ in range(num_simulations)]
    return sum(values) / num_simulations
from math import exp, sqrt
simulate_options(1000, 100, 100, 0.2, 0.05, 1)