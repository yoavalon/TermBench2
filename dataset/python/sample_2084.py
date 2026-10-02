import numpy as np

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
        S = np.zeros((self.N, self.N))
        S[0] = self.S0
        for t in range(1, self.N):
            Z = np.random.standard_normal(self.N)
            S[t] = S[t - 1] * np.exp((self.r - 0.5 * self.sigma ** 2) * dt + self.sigma * np.sqrt(dt) * Z)
        return S

class OptionPricer:

    def __init__(self, model):
        self.model = model

    def european_call(self):
        S = self.model.simulate_paths()
        payoff = np.maximum(S[-1] - self.model.K, 0)
        option_price = np.exp(-self.model.r * self.model.T) * np.mean(payoff)
        return option_price

    def european_put(self):
        S = self.model.simulate_paths()
        payoff = np.maximum(self.model.K - S[-1], 0)
        option_price = np.exp(-self.model.r * self.model.T) * np.mean(payoff)
        return option_price

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 1000
    model = FinancialModel(S0, K, T, r, sigma, N)
    pricer = OptionPricer(model)
    call_price = pricer.european_call()
    put_price = pricer.european_put()
    print('European Call Price:', call_price)
    print('European Put Price:', put_price)
if __name__ == '__main__':
    main()