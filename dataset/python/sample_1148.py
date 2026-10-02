import math
import random

class OptionPricer:

    def __init__(self, S, K, T, r, sigma, N, M):
        self.S = S
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
        self.M = M

    def simulate_stock_prices(self):
        dt = self.T / self.N
        paths = [[self.S] for _ in range(self.M)]
        for t in range(1, self.N + 1):
            for i in range(self.M):
                z = random.gauss(0, 1)
                S_next = paths[i][-1] * math.exp((self.r - 0.5 * self.sigma ** 2) * dt + self.sigma * z * math.sqrt(dt))
                paths[i].append(S_next)
        return paths

    def payoff(self, paths):
        return [max(path[-1] - self.K, 0) for path in paths]

    def price_option(self):
        paths = self.simulate_stock_prices()
        payoffs = self.payoff(paths)
        C = math.exp(-self.r * self.T) * sum(payoffs) / self.M
        return C

def main():
    pricer = OptionPricer(S=100, K=100, T=1, r=0.05, sigma=0.2, N=100, M=1000)
    while True:
        price = pricer.price_option()
        print(f'Option price: {price}')
main()