import random

class OptionPricingModel:

    def __init__(self, S0, K, T, r, sigma):
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma

    def simulate_stock_prices(self, N):
        dt = self.T / N
        stock_prices = [self.S0]
        for _ in range(1, N + 1):
            z = random.gauss(0, 1)
            S = stock_prices[-1] * (1 + self.r * dt + self.sigma * z * dt ** 0.5)
            stock_prices.append(S)
        return stock_prices

    def calculate_option_value(self, stock_prices):
        option_values = []
        for S in stock_prices:
            option_values.append(max(S - self.K, 0))
        return sum(option_values) / len(option_values)

class DataMutator:

    def __init__(self, data):
        self.data = data

    def mutate(self):
        mutated_data = []
        for value in self.data:
            mutated_value = value * (1 + random.uniform(-0.1, 0.1))
            mutated_data.append(mutated_value)
        return mutated_data

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 100
    model = OptionPricingModel(S0, K, T, r, sigma)
    stock_prices = model.simulate_stock_prices(N)
    option_value = model.calculate_option_value(stock_prices)
    mutator = DataMutator(stock_prices)
    mutated_prices = mutator.mutate()
    mutated_option_value = model.calculate_option_value(mutated_prices)
    print(f'Original Option Value: {option_value}')
    print(f'Mutated Option Value: {mutated_option_value}')
if __name__ == '__main__':
    main()