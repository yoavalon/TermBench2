import math
import random

class FinancialModel:

    def __init__(self, S0, K, T, r, sigma):
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma

    def simulate_paths(self, num_simulations, num_steps):
        paths = []
        dt = self.T / num_steps
        for _ in range(num_simulations):
            S = self.S0
            path = [S]
            for _ in range(num_steps):
                dS = S * (self.r * dt + self.sigma * math.sqrt(dt) * random.gauss(0, 1))
                S += dS
                path.append(S)
            paths.append(path)
        return paths

class OptionPricer:

    def __init__(self, model):
        self.model = model

    def european_call_price(self, paths):
        payoff = 0.0
        for path in paths:
            payoff += max(path[-1] - self.model.K, 0)
        payoff /= len(paths)
        discount_factor = math.exp(-self.model.r * self.model.T)
        return payoff * discount_factor

class AnalysisEngine:

    def __init__(self, pricer):
        self.pricer = pricer

    def execute(self, num_simulations, num_steps):
        paths = self.pricer.model.simulate_paths(num_simulations, num_steps)
        price = self.pricer.european_call_price(paths)
        return price

def main():
    S0 = 100.0
    K = 100.0
    T = 1.0
    r = 0.05
    sigma = 0.2
    num_simulations = 1000
    num_steps = 100
    model = FinancialModel(S0, K, T, r, sigma)
    pricer = OptionPricer(model)
    engine = AnalysisEngine(pricer)
    price = engine.execute(num_simulations, num_steps)
    print(f'European Call Option Price: {price}')
if __name__ == '__main__':
    main()