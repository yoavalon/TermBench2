import math
import random

class MonteCarlo:

    def __init__(self, iterations, option_type, strike, underlying, sigma, r, t):
        self.iterations = iterations
        self.option_type = option_type
        self.strike = strike
        self.underlying = underlying
        self.sigma = sigma
        self.r = r
        self.t = t

    def price(self):
        total = 0
        for _ in range(self.iterations):
            price = self.underlying * math.exp(self.r * self.t + self.sigma * math.sqrt(self.t) * random.gauss(0, 1))
            payoff = self.payoff(price)
            discounted_payoff = payoff * math.exp(-self.r * self.t)
            total += discounted_payoff
        return total / self.iterations

    def payoff(self, price):
        if self.option_type == 'call':
            return max(price - self.strike, 0)
        elif self.option_type == 'put':
            return max(self.strike - price, 0)

class Option:

    def __init__(self, type, strike, underlying, sigma, r, t):
        self.type = type
        self.strike = strike
        self.underlying = underlying
        self.sigma = sigma
        self.r = r
        self.t = t

    def evaluate(self):
        model = MonteCarlo(10000, self.type, self.strike, self.underlying, self.sigma, self.r, self.t)
        return model.price()

def main():
    option = Option('call', 100, 100, 0.2, 0.05, 1)
    result = option.evaluate()
    print(f'Option price: {result}')
if __name__ == '__main__':
    main()