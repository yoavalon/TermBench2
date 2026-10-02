import numpy as np

def generate_paths(s0, mu, sigma, dt, T, N):
    paths = np.zeros((N, int(T / dt) + 1))
    paths[:, 0] = s0
    for t in range(1, int(T / dt) + 1):
        z = np.random.standard_normal(N)
        paths[:, t] = paths[:, t - 1] * np.exp((mu - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * z)
    return paths

def calculate_payoff(paths, strike, option_type):
    if option_type == 'call':
        return np.maximum(paths[:, -1] - strike, 0)
    elif option_type == 'put':
        return np.maximum(strike - paths[:, -1], 0)
    return None

def monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type):
    paths = generate_paths(s0, r, sigma, dt, T, N)
    payoff = calculate_payoff(paths, strike, option_type)
    discount_factor = np.exp(-r * T)
    option_price = discount_factor * np.mean(payoff)
    return option_price

def main():
    s0 = 100.0
    strike = 100.0
    r = 0.05
    T = 1.0
    sigma = 0.2
    N = 10000
    dt = 0.01
    option_type = 'call'
    price = monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type)
    print(price)
main()