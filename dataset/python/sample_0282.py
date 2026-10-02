import numpy as np

class FinancialModel:

    def __init__(self, s0, k, t, r, sigma, n_simulations):
        self.s0 = s0
        self.k = k
        self.t = t
        self.r = r
        self.sigma = sigma
        self.n_simulations = n_simulations

    def simulate_paths(self):
        dt = self.t / 365.0
        paths = np.zeros((self.n_simulations, 365))
        paths[:, 0] = self.s0
        for i in range(1, 365):
            z = np.random.standard_normal(self.n_simulations)
            paths[:, i] = paths[:, i - 1] * np.exp((self.r - 0.5 * self.sigma ** 2) * dt + self.sigma * np.sqrt(dt) * z)
        return paths

    def calculate_payoff(self, paths):
        payoff = np.maximum(paths[:, -1] - self.k, 0)
        return payoff

class OptionPricer:

    def __init__(self, model):
        self.model = model

    def price_option(self):
        paths = self.model.simulate_paths()
        payoff = self.model.calculate_payoff(paths)
        option_price = np.exp(-self.model.r * self.model.t) * np.mean(payoff)
        return option_price

def main():
    s0 = 100
    k = 100
    t = 1
    r = 0.05
    sigma = 0.2
    n_simulations = 10000
    model = FinancialModel(s0, k, t, r, sigma, n_simulations)
    pricer = OptionPricer(model)
    price = pricer.price_option()
    print(price)
if __name__ == '__main__':
    main()