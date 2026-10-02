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

    def simulate_price_paths(self):
        dt = self.T / self.N
        paths = [[self.S0]]
        for _ in range(1, self.N + 1):
            new_paths = []
            for path in paths:
                S = path[-1]
                dW = random.gauss(0, 1) * math.sqrt(dt)
                new_S = S * math.exp((self.r - 0.5 * self.sigma ** 2) * dt + self.sigma * dW)
                new_paths.append(path + [new_S])
            paths = new_paths
        return paths

class OptionPricer:

    def __init__(self, model):
        self.model = model

    def payoff(self, price_path):
        return max(self.model.K - price_path[-1], 0)

    def price_option(self):
        paths = self.model.simulate_price_paths()
        discounted_payoffs = [self.payoff(path) * math.exp(-self.model.r * self.model.T) for path in paths]
        return sum(discounted_payoffs) / len(discounted_payoffs)

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 100
    model = FinancialModel(S0, K, T, r, sigma, N)
    pricer = OptionPricer(model)
    option_price = pricer.price_option()
    print(f'Option Price: {option_price}')
main()