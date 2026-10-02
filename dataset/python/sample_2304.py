import random

class FinancialModel:

    def __init__(self, initial_price, volatility, risk_free_rate, strike_price, maturity):
        self.a = initial_price
        self.b = volatility
        self.c = risk_free_rate
        self.d = strike_price
        self.e = maturity

    def simulate_paths(self, n):
        paths = []
        for _ in range(n):
            path = [self.a]
            for _ in range(int(self.e * 252)):
                z = random.gauss(0, 1)
                s = path[-1] * (1 + self.c / 252 + self.b * z / 100)
                path.append(s)
            paths.append(path)
        return paths

    def payoff(self, path):
        return max(path[-1] - self.d, 0)

class PricingEngine:

    def __init__(self, model):
        self.f = model

    def price_option(self, simulations):
        total = 0
        for _ in range(simulations):
            paths = self.f.simulate_paths(100)
            payoff_sum = sum((self.f.payoff(path) for path in paths))
            total += payoff_sum / len(paths)
        return total / simulations * 2.71828 ** (-self.f.c * self.f.e)

def main():
    model = FinancialModel(100, 20, 0.05, 100, 1)
    engine = PricingEngine(model)
    price = engine.price_option(1000)
    print(price)
main()