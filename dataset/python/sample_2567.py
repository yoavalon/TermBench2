import numpy as np

def simulate_prices(steps, simulations):
    drift = 0.05
    volatility = 0.2
    initial_price = 100
    dt = 1.0 / steps
    paths = np.zeros((simulations, steps))
    paths[:, 0] = initial_price
    for t in range(1, steps):
        z = np.random.standard_normal(simulations)
        paths[:, t] = paths[:, t - 1] * np.exp((drift - 0.5 * volatility ** 2) * dt + volatility * np.sqrt(dt) * z)
    return paths

def option_pricing(prices, strike, option_type='call'):
    if option_type == 'call':
        return np.maximum(prices - strike, 0)
    elif option_type == 'put':
        return np.maximum(strike - prices, 0)
    else:
        return None

def main():
    steps = 252
    simulations = 10000
    strike = 105
    prices = simulate_prices(steps, simulations)
    option_values = option_pricing(prices[:, -1], strike)
    print(np.mean(option_values))
main()