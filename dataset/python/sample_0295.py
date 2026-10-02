import numpy as np

class FinancialModel:

    def __init__(self, S0, K, T, r, sigma, N):
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
        self.dt = T / N

    def simulate_paths(self):
        paths = np.zeros((self.N + 1, len(self.S0)))
        paths[0] = self.S0
        for t in range(1, self.N + 1):
            z = np.random.standard_normal(len(self.S0))
            paths[t] = paths[t - 1] * np.exp((self.r - 0.5 * self.sigma ** 2) * self.dt + self.sigma * np.sqrt(self.dt) * z)
        return paths

    def payoff(self, paths):
        payoff = np.maximum(paths[-1] - self.K, 0)
        return payoff

class OptionPricer:

    def __init__(self, financial_model, M):
        self.financial_model = financial_model
        self.M = M

    def price_option(self):
        payoffs = np.zeros(self.M)
        for i in range(self.M):
            paths = self.financial_model.simulate_paths()
            payoffs[i] = self.financial_model.payoff(paths)
        option_price = np.exp(-self.financial_model.r * self.financial_model.T) * np.mean(payoffs)
        return option_price

def main():
    S0 = np.array([100, 100, 100])
    K = 100
    T = 1.0
    r = 0.05
    sigma = 0.2
    N = 100
    M = 10000
    financial_model = FinancialModel(S0, K, T, r, sigma, N)
    option_pricer = OptionPricer(financial_model, M)
    print(option_pricer.price_option())
if __name__ == '__main__':
    main()