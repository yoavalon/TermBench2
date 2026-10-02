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
        paths = []
        for _ in range(self.N):
            path = [self.S0]
            for _ in range(1, self.T * 252):
                S_next = path[-1] * (1 + random.gauss(0, self.sigma) * 252 ** (-0.5))
                path.append(S_next)
            paths.append(path)
        return paths

    def calculate_payoffs(self, paths):
        payoffs = []
        for path in paths:
            payoff = max(0, path[-1] - self.K)
            payoffs.append(payoff)
        return payoffs

class OptionPricer:

    def __init__(self, model):
        self.model = model

    def price_option(self):
        paths = self.model.simulate_paths()
        payoffs = self.model.calculate_payoffs(paths)
        discounted_payoffs = [p * 252 ** (-self.model.r) for p in payoffs]
        return sum(discounted_payoffs) / len(discounted_payoffs)

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 10000
    model = FinancialModel(S0, K, T, r, sigma, N)
    pricer = OptionPricer(model)
    option_price = pricer.price_option()
    print(f'Option Price: {option_price}')
if __name__ == '__main__':
    main()