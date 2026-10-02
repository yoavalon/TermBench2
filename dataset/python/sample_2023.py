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
        S = np.zeros((self.M, self.N + 1))
        S[:, 0] = self.S0
        for t in range(1, self.N + 1):
            Z = np.random.standard_normal(self.M)
            S[:, t] = S[:, t - 1] * np.exp((self.r - 0.5 * self.sigma ** 2) * dt + self.sigma * np.sqrt(dt) * Z)
        return S

    def calculate_option_price(self):
        S = self.simulate_paths()
        payoff = np.maximum(S[:, -1] - self.K, 0)
        option_price = np.exp(-self.r * self.T) * np.mean(payoff)
        return option_price

def main():
    S0 = 100.0
    K = 100.0
    T = 1.0
    r = 0.05
    sigma = 0.2
    N = 252
    M = 10000
    model = FinancialModel(S0, K, T, r, sigma, N, M)
    price = model.calculate_option_price()
    print(f'Option price: {price:.4f}')
if __name__ == '__main__':
    main()