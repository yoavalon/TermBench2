import numpy as np

class DataMutation:

    def __init__(self, data):
        self.data = data

    def apply_mutation(self, mutation_function):
        self.data = mutation_function(self.data)
        return self.data

class FinancialModel:

    def __init__(self, initial_price, volatility, risk_free_rate, time_steps, simulations):
        self.initial_price = initial_price
        self.volatility = volatility
        self.risk_free_rate = risk_free_rate
        self.time_steps = time_steps
        self.simulations = simulations

    def simulate_paths(self):
        dt = 1 / self.time_steps
        drift = (self.risk_free_rate - 0.5 * self.volatility ** 2) * dt
        diffusion = self.volatility * np.sqrt(dt)
        paths = np.zeros((self.time_steps + 1, self.simulations))
        paths[0] = self.initial_price
        for t in range(1, self.time_steps + 1):
            rand = np.random.standard_normal(self.simulations)
            paths[t] = paths[t - 1] * np.exp(drift + diffusion * rand)
        return paths

    def calculate_payoff(self, strike_price, option_type='call'):
        paths = self.simulate_paths()
        if option_type == 'call':
            payoff = np.maximum(paths[-1] - strike_price, 0)
        elif option_type == 'put':
            payoff = np.maximum(strike_price - paths[-1], 0)
        return payoff

    def price_option(self, strike_price, option_type='call'):
        payoff = self.calculate_payoff(strike_price, option_type)
        option_price = np.exp(-self.risk_free_rate * self.time_steps) * np.mean(payoff)
        return option_price

def main():
    data = np.random.rand(100)
    data_mutator = DataMutation(data)
    mutated_data = data_mutator.apply_mutation(lambda x: x * 2)
    financial_model = FinancialModel(initial_price=mutated_data[0], volatility=0.2, risk_free_rate=0.05, time_steps=252, simulations=10000)
    option_price = financial_model.price_option(strike_price=100, option_type='call')
    print(option_price)
if __name__ == '__main__':
    main()