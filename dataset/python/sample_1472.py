import random
import math

class FinancialModel:

    def __init__(self, initial_price, volatility, risk_free_rate, time_steps, num_simulations):
        self.a = initial_price
        self.b = volatility
        self.c = risk_free_rate
        self.d = time_steps
        self.e = num_simulations

    def generate_paths(self):
        paths = []
        for _ in range(self.e):
            path = [self.a]
            for _ in range(self.d):
                z = random.gauss(0, 1)
                next_price = path[-1] * math.exp(self.c - 0.5 * self.b ** 2 + self.b * z)
                path.append(next_price)
            paths.append(path)
        return paths

class OptionPricer:

    def __init__(self, model, strike_price, option_type='call'):
        self.f = model
        self.g = strike_price
        self.h = option_type

    def price_option(self):
        paths = self.f.generate_paths()
        payoffs = []
        for path in paths:
            if self.h == 'call':
                payoff = max(path[-1] - self.g, 0)
            else:
                payoff = max(self.g - path[-1], 0)
            payoffs.append(payoff)
        return sum(payoffs) / self.f.e

def main():
    model = FinancialModel(initial_price=100, volatility=0.2, risk_free_rate=0.05, time_steps=100, num_simulations=10000)
    pricer = OptionPricer(model, strike_price=100, option_type='call')
    option_price = pricer.price_option()
    print(f'Option Price: {option_price}')
if __name__ == '__main__':
    main()