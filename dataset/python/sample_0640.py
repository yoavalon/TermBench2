def monte_carlo_price(s, k, r, t, v, n, simulations):
    import random

    def simulate():
        price = s
        for _ in range(n):
            price *= 1 + random.normalvariate(r - v ** 2 / 2, v)
        return max(price - k, 0)
    return sum((simulate() for _ in range(simulations))) / simulations
monte_carlo_price(100, 100, 0.05, 1, 0.2, 252, 10000)