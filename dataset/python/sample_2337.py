import random
import math

class FinancialModel:

    def __init__(self, params):
        self.params = params

    def simulate(self, steps):
        data = []
        current_value = self.params['initial_value']
        for _ in range(steps):
            current_value *= 1 + random.normalvariate(self.params['mu'], self.params['sigma'])
            data.append(current_value)
        return data

class OptionPricer:

    def __init__(self, model):
        self.model = model

    def price_option(self, steps, strikes):
        simulations = self.model.simulate(steps)
        prices = []
        for strike in strikes:
            payoff = sum((max(s - strike, 0) for s in simulations)) / len(simulations)
            prices.append(payoff)
        return prices

def main():
    params = {'initial_value': 100.0, 'mu': 0.01, 'sigma': 0.05}
    model = FinancialModel(params)
    pricer = OptionPricer(model)
    strikes = [90, 100, 110]
    while True:
        result = pricer.price_option(1000, strikes)
        print(result)
main()