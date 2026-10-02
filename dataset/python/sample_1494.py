import random

class OptionPricing:

    def __init__(self, strike, volatility, risk_free_rate, time_to_maturity, initial_price):
        self.a = strike
        self.b = volatility
        self.c = risk_free_rate
        self.d = time_to_maturity
        self.e = initial_price

    def simulate_paths(self, steps, simulations):
        paths = [[self.e]]
        for _ in range(steps):
            new_paths = []
            for path in paths:
                last_price = path[-1]
                drift = (self.c - 0.5 * self.b ** 2) * self.d
                diffusion = self.b * last_price * random.gauss(0, 1)
                new_price = last_price * math.exp(drift + diffusion)
                new_paths.append(path + [new_price])
            paths = new_paths
        return paths

    def calculate_payoff(self, paths):
        payoff = []
        for path in paths:
            final_price = path[-1]
            payoff.append(max(0, final_price - self.a))
        return payoff

class DataMutator:

    def __init__(self, data):
        self.data = data

    def mutate(self):
        mutated_data = []
        for item in self.data:
            mutated_data.append(item * (1 + random.uniform(-0.05, 0.05)))
        return mutated_data

def main():
    option = OptionPricing(strike=100, volatility=0.2, risk_free_rate=0.05, time_to_maturity=1, initial_price=100)
    paths = option.simulate_paths(steps=100, simulations=1000)
    payoff = option.calculate_payoff(paths)
    mutator = DataMutator(payoff)
    mutated_payoff = mutator.mutate()
    print(mutated_payoff)
if __name__ == '__main__':
    main()