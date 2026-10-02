import math
import random

class FinancialModel:

    def __init__(self, S0, K, T, r, sigma, N):
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N

    def simulate_paths(self):
        dt = self.T / self.N
        paths = [[self.S0]]
        for _ in range(self.N):
            new_paths = []
            for path in paths:
                S = path[-1]
                Z = random.gauss(0, 1)
                S_new = S * math.exp((self.r - 0.5 * self.sigma ** 2) * dt + self.sigma * Z * math.sqrt(dt))
                new_paths.append(path + [S_new])
            paths = new_paths
        return paths

    def calculate_payoff(self, paths):
        payoffs = []
        for path in paths:
            ST = path[-1]
            payoff = max(0, ST - self.K)
            payoffs.append(payoff)
        return payoffs

class PricingEngine:

    def __init__(self, model):
        self.model = model

    def price_option(self):
        paths = self.model.simulate_paths()
        payoffs = self.model.calculate_payoff(paths)
        discounted_payoffs = [payoff * math.exp(-self.model.r * self.model.T) for payoff in payoffs]
        option_price = sum(discounted_payoffs) / len(discounted_payoffs)
        return option_price

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 100
    model = FinancialModel(S0, K, T, r, sigma, N)
    engine = PricingEngine(model)
    price = engine.price_option()
    print(price)
main()