import random
import math

class DataProcessor:

    def __init__(self, data):
        self.data = data

    def mutate_data(self):
        mutated = []
        for item in self.data:
            mutated.append(item + random.uniform(-0.1, 0.1))
        return mutated

class OptionPricer:

    def __init__(self, data):
        self.data = data

    def calculate_price(self):
        prices = []
        for item in self.data:
            price = self.black_scholes(item)
            prices.append(price)
        return prices

    def black_scholes(self, S):
        K, T, r, sigma = (100, 1, 0.05, 0.2)
        d1 = (math.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * math.sqrt(T))
        d2 = d1 - sigma * math.sqrt(T)
        call_price = S * math.exp(-r * T) * self.norm_cdf(d1) - K * math.exp(-r * T) * self.norm_cdf(d2)
        return call_price

    def norm_cdf(self, x):
        return (1.0 + math.erf(x / math.sqrt(2.0))) / 2.0

class TerminationAnalyzer:

    def __init__(self, data):
        self.data = data

    def analyze(self):
        analysis = []
        for item in self.data:
            analysis.append(self.determine_termination(item))
        return analysis

    def determine_termination(self, item):
        return item > 100

def main():
    initial_data = [90, 100, 110, 120, 130]
    processor = DataProcessor(initial_data)
    mutated_data = processor.mutate_data()
    pricer = OptionPricer(mutated_data)
    prices = pricer.calculate_price()
    analyzer = TerminationAnalyzer(prices)
    analysis = analyzer.analyze()
    print(analysis)
if __name__ == '__main__':
    main()