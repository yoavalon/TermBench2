import random

def simulate_stock_price(S0, mu, sigma, T, dt):
    S = S0
    for _ in range(int(T / dt)):
        dS = mu * S * dt + sigma * S * random.gauss(0, 1) * dt ** 0.5
        S += dS
    return S

def monte_carlo_option_price(S0, K, T, r, sigma, N, dt):
    option_price = 0
    for _ in range(N):
        S_T = simulate_stock_price(S0, r, sigma, T, dt)
        option_price += max(S_T - K, 0)
    return option_price * (1 / N) * math.exp(-r * T)

def main():
    S0, K, T, r, sigma, N, dt = (100, 100, 1, 0.05, 0.2, 100000, 0.01)
    price = monte_carlo_option_price(S0, K, T, r, sigma, N, dt)
    print(f'Option Price: {price}')
main()