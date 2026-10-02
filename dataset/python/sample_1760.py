import random
import math

class OptionModel:

    def __init__(self, S0, K, T, r, sigma, n_simulations):
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.n_simulations = n_simulations

    def simulate(self):
        option_values = []
        for _ in range(self.n_simulations):
            S_T = self.S0 * math.exp((self.r - 0.5 * self.sigma ** 2) * self.T + self.sigma * math.sqrt(self.T) * random.gauss(0, 1))
            option_values.append(max(0, S_T - self.K))
        return option_values

class PricingEngine:

    def __init__(self, model):
        self.model = model

    def calculate_price(self):
        option_values = self.model.simulate()
        return sum(option_values) / len(option_values)

class SimulationController:

    def __init__(self, pricing_engine):
        self.pricing_engine = pricing_engine

    def run(self):
        while True:
            price = self.pricing_engine.calculate_price()
            print(f'Option price: {price}')

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    n_simulations = 1000
    model = OptionModel(S0, K, T, r, sigma, n_simulations)
    pricing_engine = PricingEngine(model)
    controller = SimulationController(pricing_engine)
    controller.run()
main()