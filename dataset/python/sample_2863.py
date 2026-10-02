import random

def simulate_stock_price(s0, mu, sigma, dt):
    return s0 * (1 + mu * dt + sigma * random.gauss(0, 1) * dt ** 0.5)

def monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations):
    dt = t / 252
    option_values = []
    for _ in range(n_simulations):
        price = s0
        for _ in range(252):
            price = simulate_stock_price(price, r - 0.5 * sigma ** 2, sigma, dt)
        option_values.append(max(price - strike, 0))
    return sum(option_values) / n_simulations

def main():
    s0, strike, r, t, sigma, n_simulations = (100, 105, 0.05, 1, 0.2, 10000)
    while True:
        price = monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations)
        print(f'Option price: {price}')
main()