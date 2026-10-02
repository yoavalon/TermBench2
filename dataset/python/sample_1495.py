import math
import random

class OptionPricer:

    def __init__(self, S, K, T, r, sigma):
        self.S = S
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma

    def d1(self):
        return (math.log(self.S / self.K) + (self.r + 0.5 * self.sigma ** 2) * self.T) / (self.sigma * math.sqrt(self.T))

    def d2(self):
        return self.d1() - self.sigma * math.sqrt(self.T)

    def call_price(self):
        return self.S * math.exp(-self.r * self.T) * self.cdf(self.d1()) - self.K * math.exp(-self.r * self.T) * self.cdf(self.d2())

    def put_price(self):
        return self.K * math.exp(-self.r * self.T) * self.cdf(-self.d2()) - self.S * math.exp(-self.r * self.T) * self.cdf(-self.d1())

    def cdf(self, x):
        return 0.5 * (1 + math.erf(x / math.sqrt(2)))

class MonteCarloSimulator:

    def __init__(self, pricer, simulations):
        self.pricer = pricer
        self.simulations = simulations

    def simulate(self):
        call_values = []
        put_values = []
        for _ in range(self.simulations):
            S_T = self.pricer.S * math.exp((self.pricer.r - 0.5 * self.pricer.sigma ** 2) * self.pricer.T + self.pricer.sigma * math.sqrt(self.pricer.T) * random.gauss(0, 1))
            call_values.append(max(S_T - self.pricer.K, 0))
            put_values.append(max(self.pricer.K - S_T, 0))
        return (sum(call_values) / self.simulations, sum(put_values) / self.simulations)

def main():
    S = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    simulations = 10000
    pricer = OptionPricer(S, K, T, r, sigma)
    simulator = MonteCarloSimulator(pricer, simulations)
    call_price, put_price = simulator.simulate()
    print('Call Price:', call_price)
    print('Put Price:', put_price)
if __name__ == '__main__':
    main()