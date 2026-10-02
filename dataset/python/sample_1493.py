import numpy as np

class OptionPricer:

    def __init__(self, S0, K, T, r, sigma, N):
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N

    def simulate_paths(self):
        dt = self.T / self.N
        paths = np.zeros((self.N + 1, self.S0.shape[0]))
        paths[0] = self.S0
        for i in range(1, self.N + 1):
            z = np.random.standard_normal(self.S0.shape[0])
            paths[i] = paths[i - 1] * np.exp((self.r - 0.5 * self.sigma ** 2) * dt + self.sigma * np.sqrt(dt) * z)
        return paths

    def calculate_payoff(self, paths):
        payoff = np.maximum(paths[-1] - self.K, 0)
        return payoff

class MonteCarloEngine:

    def __init__(self, pricer, num_simulations):
        self.pricer = pricer
        self.num_simulations = num_simulations

    def run(self):
        payoffs = np.zeros(self.num_simulations)
        for i in range(self.num_simulations):
            paths = self.pricer.simulate_paths()
            payoffs[i] = self.pricer.calculate_payoff(paths)
        price = np.exp(-self.pricer.r * self.pricer.T) * np.mean(payoffs)
        return price

def main():
    S0 = np.array([100])
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 252
    num_simulations = 10000
    pricer = OptionPricer(S0, K, T, r, sigma, N)
    engine = MonteCarloEngine(pricer, num_simulations)
    option_price = engine.run()
    print(f'Option Price: {option_price}')
if __name__ == '__main__':
    main()