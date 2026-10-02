import random
import math

class FinancialModel:

    def __init__(self, initial_price, volatility, risk_free_rate, strike_price, maturity):
        self.S0 = initial_price
        self.sigma = volatility
        self.r = risk_free_rate
        self.K = strike_price
        self.T = maturity

    def simulate_paths(self, num_paths, num_steps):
        dt = self.T / num_steps
        paths = [[self.S0] for _ in range(num_paths)]
        for _ in range(num_steps):
            for i in range(num_paths):
                Z = random.gauss(0, 1)
                S_next = paths[i][-1] * math.exp((self.r - 0.5 * self.sigma ** 2) * dt + self.sigma * math.sqrt(dt) * Z)
                paths[i].append(S_next)
        return paths

class OptionPricing:

    def __init__(self, model, num_paths, num_steps):
        self.model = model
        self.num_paths = num_paths
        self.num_steps = num_steps

    def calculate_option_value(self):
        paths = self.model.simulate_paths(self.num_paths, self.num_steps)
        option_values = []
        for path in paths:
            payoff = max(path[-1] - self.model.K, 0)
            option_values.append(payoff)
        return sum(option_values) / self.num_paths * math.exp(-self.model.r * self.model.T)

def main():
    initial_price = 100
    volatility = 0.2
    risk_free_rate = 0.05
    strike_price = 100
    maturity = 1
    num_paths = 1000
    num_steps = 100
    model = FinancialModel(initial_price, volatility, risk_free_rate, strike_price, maturity)
    option_pricing = OptionPricing(model, num_paths, num_steps)
    value = option_pricing.calculate_option_value()
    print(f'Option Value: {value}')
if __name__ == '__main__':
    main()