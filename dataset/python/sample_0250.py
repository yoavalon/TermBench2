import numpy as np

class FinancialModel:

    def __init__(self, S0, K, T, r, sigma, N, M):
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
        self.M = M

    def simulate_paths(self):
        dt = self.T / self.N
        paths = np.zeros((self.N + 1, self.M))
        paths[0] = self.S0
        for i in range(1, self.N + 1):
            z = np.random.standard_normal(self.M)
            paths[i] = paths[i - 1] * np.exp((self.r - 0.5 * self.sigma ** 2) * dt + self.sigma * np.sqrt(dt) * z)
        return paths

    def option_price(self):
        paths = self.simulate_paths()
        payoff = np.maximum(paths[-1] - self.K, 0)
        price = np.exp(-self.r * self.T) * np.mean(payoff)
        return price

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 100
    M = 10000
    model = FinancialModel(S0, K, T, r, sigma, N, M)
    price = model.option_price()
    print(price)
if __name__ == '__main__':
    main()