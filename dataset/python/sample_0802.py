import math
import random

class MonteCarlo:

    def __init__(self, price, strike, rate, volatility, time, simulations):
        self.price = price
        self.strike = strike
        self.rate = rate
        self.volatility = volatility
        self.time = time
        self.simulations = simulations

    def _simulate(self, count):
        if count >= self.simulations:
            return []
        dt = self.time / self.simulations
        drift = (self.rate - 0.5 * self.volatility ** 2) * dt
        diffusion = self.volatility * math.sqrt(dt)
        price = self.price * math.exp(drift + diffusion * random.gauss(0, 1))
        return [price] + self._simulate(count + 1)

    def _payoff(self, prices):
        return [max(p - self.strike, 0) for p in prices]

    def price_option(self):
        prices = self._simulate(0)
        payoffs = self._payoff(prices)
        return math.exp(-self.rate * self.time) * sum(payoffs) / self.simulations

def main():
    price = 100
    strike = 100
    rate = 0.05
    volatility = 0.2
    time = 1
    simulations = 10000
    model = MonteCarlo(price, strike, rate, volatility, time, simulations)
    print(model.price_option())
if __name__ == '__main__':
    main()