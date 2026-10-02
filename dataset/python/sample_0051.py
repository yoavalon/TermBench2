import random

def simulate_price(option_type, S0, K, T, r, sigma, N, M):
    dt = T / N
    dS = S0 * (r * dt + sigma * dt ** 0.5)
    prices = [S0]
    for _ in range(1, N + 1):
        S = prices[-1] + dS * random.gauss(0, 1)
        prices.append(S)
    payoff = max(0, prices[-1] - K) if option_type == 'call' else max(0, K - prices[-1])
    return payoff
S0, K, T, r, sigma, N, M = (100, 100, 1, 0.05, 0.2, 252, 1000)
results = [simulate_price('call', S0, K, T, r, sigma, N, M) for _ in range(M)]
average_price = sum(results) / M
print(average_price)